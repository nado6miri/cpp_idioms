// 3_�������1.cpp
#include <iostream>
#include <vector>

// 237 page . thin template
// Ŭ���� ���ø��� �ʹ� ���� Ÿ�Կ� ���ؼ� �ν��Ͻ�ȭ �ɶ� �ڵ尡 
// Ŀ���� �ִ� - code bloat
// code bloat �� ���� ���� ���

// T�� ������� ���� ��� �Լ��� ���ø��� �ƴ� ��� Ŭ������ ����
// ��ӹ���.!!



// Ŭ���� ���ø��� ���鶧 
// ���ø� �Ķ���� T�� ������� ���� ��� �Լ��� 
// ���ø��� �ƴ� ��� Ŭ������ ���� ��ӹ���


class RefCountedBase
{
protected:
	mutable int m_refCount = 0;
public:
	void ref()   const { ++m_refCount; }
};

template<typename T> class RefCounted : public RefCountedBase
{
public:
	void deref() const
	{
		if (--m_refCount == 0) delete static_cast<const T*>(this);
	}
protected:
	~RefCounted() {  }
};

class Car : public RefCounted<Car>
{
public:
	~Car() { std::cout << "~Car" << std::endl; }
};

class Truck : public RefCounted<Truck>
{
};


int main()


{
	const Car* p1 = new Car;
	p1->ref();

	p1->deref();
}

