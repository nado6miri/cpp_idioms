// 3_�������1.cpp
#include <iostream>
#include <vector>

template<typename T> class RefCountedBase
{
	// mutable ��� ����Ÿ : ����Լ��ȿ����� ���� �����Ҽ� �ִ�
	mutable int m_refCount = 0;
public:

	// ��� ��ü�� ������ �����Ҽ� �־�� �Ѵ�.
	// ��������� �����ϴ� �Լ��� �ݵ�� "��� ����Լ�" �̾���Ѵ�
	void ref()   const { ++m_refCount; }
	
	void deref() const
	{
		//x = 0; //error.  this->x = 0;
		// �Ϲ� ��� �Լ����� this : RefCountedBase* this
		// ��� ��� �Լ����� this : const RefCountedBase* this

		if (--m_refCount == 0)
			delete static_cast<const T*>(this);
			//delete static_cast<T*>(
			//		const_cast<RefCountedBase*>(this));
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
	const Car* p1 = new Car;
	p1->ref();

	p1->deref();
}

