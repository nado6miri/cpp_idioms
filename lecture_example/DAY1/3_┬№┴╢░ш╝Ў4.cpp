// 3_�������1.cpp
#include <iostream>
#include <vector>

// CRTP ( Curiosly Recurring Template Pattern ) - 71
// ��� Ŭ������ ���ø� �ε�. �Ļ� Ŭ������ ���鶧 �ڽ��� �̸���
// ���ø� ���ڷ� ������ �ִ� ���.
// �̷��� ������� �Ļ�Ŭ������ �̸��� �̸� ����Ҽ� �ִ�.

template<typename T> class RefCountedBase
{
	int m_refCount = 0;
public:
	void ref() { ++m_refCount; }
	void deref()   
	{
		if (--m_refCount == 0)
			delete static_cast<T*>(this);
	}
protected:
	~RefCountedBase() {  }
};

class Car : public RefCountedBase<Car>
{
public:
	~Car() { std::cout << "~Car" << std::endl; }
};

int main()
{
	Car* p1 = new Car;
	p1->ref();

	Car* p2 = p1;
	p2->ref();

	p2->deref();
	p1->deref();
}

