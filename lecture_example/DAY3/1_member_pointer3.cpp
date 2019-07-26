#include <iostream>
#include <memory>
#include <Windows.h>  // win32 api

// std::enable_shared_from_this : this 포인터로
//			외부에서 만든 관리객체를 공유할수 있게 하는 기반 클래스
// CRTP
class Thread : public std::enable_shared_from_this<Thread>
{
	std::shared_ptr<Thread> holdme;
public:
	~Thread() { std::cout << "~Thread" << std::endl; }

	// 아래 코드는 2개의 문제가 있습니다.
	// 1. raw pointer(this)를 가지고 초기화 하면
	//    관리객체가 따로 만들어 집니다
	// 2. 생성자에서 초기화 하면 관리객체를 같이 사용할때 
	//    참조계수가 즉시 2가 됩니다.

	// 3. 생성자가 호출된 시점에는 아직 외부의 sp 스마트 포인터가
	//     초기화 되지 않은 시점 입니다. 즉, 관리객체가 없습니다.

	//Thread() : holdme(this)
	// shared_from_this() : 외부에 만들어져 있는 shared_ptr용
	//			관리 객체를 같이 사용하게 하는 함수.
	Thread() //: holdme( shared_from_this() )
	{
	}
	void run() 
	{ 
		holdme = shared_from_this(); // 이순간 외부의 sp의 관리
				// 객체를 공유합니다. 참조계수가 2가 됩니다.

		CreateThread(0, 0, threadMain, this, 0, 0); 
	}


	static DWORD __stdcall threadMain(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		// 지역변수로 스마트 포인터를 다시 생성한다.
		std::shared_ptr<Thread> strong(self->holdme);
		self->holdme.reset(); 


		self->threadLoop();

		// 자신의 참조계수를 가지고 있던 스마트 포인터를 reset 합니다.
		//self->holdme.reset();

		return 0;
	}
	virtual void threadLoop() = 0;
};


class MyThread : public Thread
{
	int data = 0;
public:
	virtual void threadLoop()
	{
		std::cout << "MyThread" << std::endl;
		data = 10;   
	}
};
int main()
{
//	MyThread* p = new MyThread;
//	p->run();

	{
		std::shared_ptr<MyThread> sp(new MyThread);
		sp->run();
	}

	getchar();
}
