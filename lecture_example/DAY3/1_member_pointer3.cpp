#include <iostream>
#include <memory>
#include <Windows.h>  // win32 api

// std::enable_shared_from_this : this �����ͷ�
//			�ܺο��� ���� ������ü�� �����Ҽ� �ְ� �ϴ� ��� Ŭ����
// CRTP
class Thread : public std::enable_shared_from_this<Thread>
{
	std::shared_ptr<Thread> holdme;
public:
	~Thread() { std::cout << "~Thread" << std::endl; }

	// �Ʒ� �ڵ�� 2���� ������ �ֽ��ϴ�.
	// 1. raw pointer(this)�� ������ �ʱ�ȭ �ϸ�
	//    ������ü�� ���� ����� ���ϴ�
	// 2. �����ڿ��� �ʱ�ȭ �ϸ� ������ü�� ���� ����Ҷ� 
	//    ��������� ��� 2�� �˴ϴ�.

	// 3. �����ڰ� ȣ��� �������� ���� �ܺ��� sp ����Ʈ �����Ͱ�
	//     �ʱ�ȭ ���� ���� ���� �Դϴ�. ��, ������ü�� �����ϴ�.

	//Thread() : holdme(this)
	// shared_from_this() : �ܺο� ������� �ִ� shared_ptr��
	//			���� ��ü�� ���� ����ϰ� �ϴ� �Լ�.
	Thread() //: holdme( shared_from_this() )
	{
	}
	void run() 
	{ 
		holdme = shared_from_this(); // �̼��� �ܺ��� sp�� ����
				// ��ü�� �����մϴ�. ��������� 2�� �˴ϴ�.

		CreateThread(0, 0, threadMain, this, 0, 0); 
	}


	static DWORD __stdcall threadMain(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		// ���������� ����Ʈ �����͸� �ٽ� �����Ѵ�.
		std::shared_ptr<Thread> strong(self->holdme);
		self->holdme.reset(); 


		self->threadLoop();

		// �ڽ��� ��������� ������ �ִ� ����Ʈ �����͸� reset �մϴ�.
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
