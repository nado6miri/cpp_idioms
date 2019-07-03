#include <iostream>
#include <Windows.h> // win32 api

// thread �Լ��� win���� �Ʒ��� ���� ������ ��.

/*
DWORD __stdcall foo(void* p)
{
	return 0;
}

int main()
{
	CreateThread(0, 0, foo, "A", 0, 0); // win32 thread �Լ� - linux : pthread_create(...)
}
*/


// ������ ������ ���� Ŭ����
// �Ʒ� �ڵ带 ���̺귯�� ���� Ŭ������� �����ϼ���.
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }

	// �������� ������ void * param 1���ε� ��ü ���ο� �ֱ� ������ this�� �Ѿ�� param �� �Ѿ �� ����
	// this�� �߰����� �ʵ��� �ϱ� ���� static �� �־� ��� ��. - static�� �ٿ���� �ϴ� ������.
	// �ȵ���̵� �ҽ� /platform_system_core/libutils/include/utils/Thread.h Threads.cpp 640 line
	static DWORD __stdcall threadMain(void* p)
	{
		// static �� �Ǹ� �ض� ������ ������ - static�� this �� ����. 
		// param ���� this�� �ޱ� ���� void run() { CreateThread(0, 0, threadMain, 0, 0, 0); } -> void run() { CreateThread(0, 0, threadMain, this, 0, 0); }�� ����
		//threadLoop(); 

		// self�� �ᱹ this��, self �� ����ϸ� static��� �Լ������� �ٸ� ����� ������ ������.
		Thread* self = static_cast<Thread*>(p);
		self->threadLoop();
		return 0;
	}

	virtual void threadLoop() = 0;
};

// �Ʒ� Ŭ������ ����� Ŭ���� �Դϴ�.
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
	mt.run(); // �� ���� ���ο� �����尡 �����Ǿ�  threadLoop()�� �����ؾ� �մϴ�.
	getchar();
}