#include <iostream>
#include <Windows.h> // win32 api
#include <memory>

// std::enable_shared_from_this - this pointer�� �ܺο��� ���� ������ü�� ������ �� �ְ� �ϴ� ��� Ŭ����
class Thread : public std::enable_shared_from_this<Thread> // CRTP
{
	std::shared_ptr<Thread> holdme;

public:
	~Thread() { std::cout << "~Thread" << std::endl; }
	// �Ʒ� �ڵ�� 2���� ������ �ֽ��ϴ�. 
	// 1. raw pointer(this)�� ������ �ʱ�ȭ �ϸ� ���� ��ü�� ���� ����� ���ϴ�. 
	// ���� shared_ptr�� ������ü�� �����ؾ� �ϴ� ����� �ʿ� -> std::enable_shared_from_this ��ӹ޴´�.��ӹ��� Ŭ������ ����Լ� shared_from_this() ���
	// 2. �����ڿ��� �ʱ�ȭ �ϸ� ���� ��ü�� ���� ����Ҷ� ���� ����� ��� 2�� �˴ϴ�.
	// 3. �����ڰ� ȣ��� ������ ���� ������ sp ����Ʈ �����Ͱ� �ʱ�ȭ ���� ���� �����̶� ���� ��ü�� �����ϴ�. �����ڿ��� holdme�� �ʱ�ȭ �ϸ� �ȵǰ� run() ���� �ؾ� ��.
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
		// self�� �ᱹ this��, self �� ����ϸ� static��� �Լ������� �ٸ� ����� ������ ������.
		Thread* self = static_cast<Thread*>(p);

		// ���������� ����Ʈ �����͸� �ٽ� �����Ѵ�.
		// ������ �߰��� ���� �߻����� �Ʒ��� ��ġ�� self->holdme.reset()�� ȣ����� ���� ��쿡 ����ؼ� �Ʒ�ó�� �����.
		// ���������� ����� smart ptr�� {}�� ����� �ڵ����� ������� -1��.
		std::shared_ptr<Thread> strong(self->holdme);
		self->holdme.reset();

		self->threadLoop();

		// �ڽ��� ��������� ������ �ִ� ����Ʈ �����͸� �ʱ�ȭ �Ѵ�.
		//self->holdme.reset();
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
	//MyThread* p = new MyThread;
	//p->run();
	{
		//new�� �̿��ϸ� delete �� �� ��� �ϱ� ������ smart ptr �����.
		std::shared_ptr<MyThread> sp(new MyThread);
		sp->run();
	}
	getchar();
}