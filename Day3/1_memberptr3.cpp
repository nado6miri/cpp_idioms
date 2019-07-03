#include <iostream>
#include <Windows.h> // win32 api
#include <memory>

// std::enable_shared_from_this - this pointer로 외부에서 만든 관리객체를 공유할 수 있게 하는 기반 클래스
class Thread : public std::enable_shared_from_this<Thread> // CRTP
{
	std::shared_ptr<Thread> holdme;

public:
	~Thread() { std::cout << "~Thread" << std::endl; }
	// 아래 코드는 2개의 문제가 있습니다. 
	// 1. raw pointer(this)를 가지고 초기화 하면 관리 객체가 따로 만들어 집니다. 
	// 따라서 shared_ptr의 관리객체를 공유해야 하는 방법이 필요 -> std::enable_shared_from_this 상속받는다.상속받은 클래스이 멤버함수 shared_from_this() 사용
	// 2. 생성자에서 초기화 하면 관리 객체를 같이 사용할때 참조 계수가 즉시 2가 됩니다.
	// 3. 생성자가 호출된 시점은 아직 외의의 sp 스마트 포인터가 초기화 되지 않은 시점이라 관리 객체가 없습니다. 생성자에서 holdme를 초기화 하면 안되고 run() 에서 해야 함.
	//Thread() : holdme(this)
	Thread() //: holdme(shared_from_this())
	{

	}

	void run() 
	{
		holdme = shared_from_this();
		CreateThread(0, 0, threadMain, this, 0, 0); 
	}

	static DWORD __stdcall threadMain(void* p)
	{
		// self가 결국 this임, self 를 사용하면 static멤버 함수에서도 다른 멤버의 접근이 가능함.
		Thread* self = static_cast<Thread*>(p);

		// 지역변수로 스마트 포인터를 다시 생성한다.
		// 이유는 중간에 예외 발생으로 아래에 위치한 self->holdme.reset()이 호출되지 않을 경우에 대비해서 아래처럼 사용함.
		// 지역변수로 선언된 smart ptr은 {}을 벗어나면 자동으로 참조계수 -1됨.
		std::shared_ptr<Thread> strong(self->holdme);
		self->holdme.reset();

		self->threadLoop();

		// 자신의 참조계수를 가지고 있던 스마트 포인터를 초기화 한다.
		//self->holdme.reset();
		return 0;
	}

	virtual void threadLoop() = 0;
};


// 아래 클래스는 사용자 클래스 입니다.
class MyThread : public Thread
{
public:
	virtual void threadLoop()
	{
		std::cout << "MyThread" << std::endl;
	}
};

int main()
{
	//MyThread* p = new MyThread;
	//p->run();
	{
		//new를 이용하면 delete 를 해 줘야 하기 때문에 smart ptr 사용함.
		std::shared_ptr<MyThread> sp(new MyThread);
		sp->run();
	}
	getchar();
}