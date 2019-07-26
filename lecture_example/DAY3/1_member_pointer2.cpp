#include <iostream>
#include <Windows.h>  // win32 api

/*
DWORD __stdcall foo(void* p)
{
	return 0;
}
int main()
{
	CreateThread(0, 0, foo, "A", 0, 0);// win32 스레드 함수
				// linux : pthread_create(...)
}
*/
// 스레드 개념을 담은 클래스
// 아래 코드를 라이브러리 내부 클래스라고 생각하세요
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }

	// 핵심 1. 아래 함수는 반드시 static 멤버 함수가 되어야 합니다.
	// 안드로이드소스/platform_system_core/libutils/include/utils/
	// Thread.h   Threads.cpp
	static DWORD __stdcall threadMain(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		// self 가 결국 this 입니다. 
		// self를 사용하면 static 멤버함수에서도 다른 멤버에 
		// 접근할수 있습니다.
		self->threadLoop(); 
		//threadLoop();
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
	mt.run();   // 이 순간 새로운 스레드가 생성되어서 threadLoop()를
				// 실행해야 합니다.
	getchar();
}
