// 3_�������5.cpp

#include<iostream>
#include<vector>

template<typename T> class RefCountBase
{
	//  mutable ��� ������ : ����Լ��ȿ����� ���� ������ �� �ִ�.
	mutable int m_refCount = 0; //���� ����� ���� ���� c++11���� member field �ʱ�ȭ ������.
public:
	// ��� ��ü�� ������ ������ �� �־�� �Ѵ�. 
	// ��������� �����ϴ� �Լ��� �ݵ�� "��� ����Լ�" �̾�� �Ѵ�.
	// ����Լ��ε� �ȿ��� ���� �����ؾ� �Ѵ�. ���� mutable�� ������.
	void ref() const { ++m_refCount; }
	void deref() const // void deref(RefCountBase* this)
	{
		// �Ϲ� ����Լ����� this : RefCountedBase* this
		// ��� ����Լ����� this :  const RefCountedBase* this
		if (--m_refCount == 0)
		{
			//delete static_cast<T*>(this); // delete�� heap�� �ִ� ���� ������. stack�� �ƴ�.
			delete static_cast<T*>(const_cast<RefCountBase*>(this));
			// �Ǵٸ� �ذ�å
			//delete static_cast<const T*>(this);
		}
	}

	//  protected �Ҹ��� - ��ü�� stack �� ���� �� ���� ����.... - page 195 �Ʒ��� �ڵ���.
protected:
	~RefCountBase()
	{
	}
};



class Car : public RefCountBase<Car> // �̷��� �̿��� �Ļ�Ŭ���� �̸��� �����Ͽ� ���ø����� �����.
{
public:
	~Car() { std::cout << "~Car" << std::endl; }
};

void main()
{
	Car* p1 = new Car;
	p1->ref(); // rule1 : ��ü ������ ���� ��� ����

	Car* p2 = p1;
	p2->ref();	// ��Ģ 2 . ������ ����ÿ� ������� ����

	p2->deref(); // ��Ģ3 . ���̻� �ʿ� ������ ������� ���� 
	p1->deref();
}