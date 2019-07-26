#include <iostream>
#include <Windows.h>  // win32 api

/*
DWORD __stdcall foo(void* p)
{
	return 0;
}
int main()
{
	CreateThread(0, 0, foo, "A", 0, 0);// win32 ������ �Լ�
				// linux : pthread_create(...)
}
*/
// ������ ������ ���� Ŭ����
// �Ʒ� �ڵ带 ���̺귯�� ���� Ŭ������� �����ϼ���
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }

	// �ٽ� 1. �Ʒ� �Լ��� �ݵ�� static ��� �Լ��� �Ǿ�� �մϴ�.
	// �ȵ���̵�ҽ�/platform_system_core/libutils/include/utils/
	// Thread.h   Threads.cpp
	static DWORD __stdcall threadMain(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		// self �� �ᱹ this �Դϴ�. 
		// self�� ����ϸ� static ����Լ������� �ٸ� ����� 
		// �����Ҽ� �ֽ��ϴ�.
		self->threadLoop(); 
		//threadLoop();
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
	mt.run();   // �� ���� ���ο� �����尡 �����Ǿ threadLoop()��
				// �����ؾ� �մϴ�.
	getchar();
}
