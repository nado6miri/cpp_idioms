#include <iostream>
#include <Windows.h> // win32 api

// thread 함수는 win에서 아래와 같이 만들어야 함.

/*
DWORD __stdcall foo(void* p)
{
	return 0;
}

int main()
{
	CreateThread(0, 0, foo, "A", 0, 0); // win32 thread 함수 - linux : pthread_create(...)
}
*/


// 스래드 개념을 담은 클래스
// 아래 코드를 라이브러리 내부 클래스라고 생각하세요.
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }

	// 에러나는 이유는 void * param 1개인데 객체 내부에 있기 때문에 this가 넘어가서 param 이 넘어갈 수 없음
	// this가 추가되지 않도록 하기 위해 static 을 넣어 줘야 함. - static을 붙여줘야 하는 이유임.
	// 안드로이드 소스 /platform_system_core/libutils/include/utils/Thread.h Threads.cpp 640 line
	static DWORD __stdcall threadMain(void* p)
	{
		// static 이 되면 해랑 라인은 에러임 - static은 this 가 없음. 
		// param 으로 this를 받기 위해 void run() { CreateThread(0, 0, threadMain, 0, 0, 0); } -> void run() { CreateThread(0, 0, threadMain, this, 0, 0); }로 변경
		//threadLoop(); 

		// self가 결국 this임, self 를 사용하면 static멤버 함수에서도 다른 멤버의 접근이 가능함.
		Thread* self = static_cast<Thread*>(p);
		self->threadLoop();
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
	MyThread mt;
	mt.run(); // 이 순간 새로운 스래드가 생성되어  threadLoop()를 실행해야 합니다.
	getchar();
}