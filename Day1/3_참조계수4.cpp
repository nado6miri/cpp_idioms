// 3_�������1.cpp

#include<iostream>
#include<vector>

/*
// ref counter�� �����ϴ� ���� Ŭ������ ��������.
class RefCountBase
{
	int m_refCount = 0; //���� ����� ���� ���� c++11���� member field �ʱ�ȭ ������.
public:
	void ref() { ++m_refCount; }
	void deref() // void deref(RefCountBase* this)
	{
		if (--m_refCount == 0) delete this; // delete�� heap�� �ִ� ���� ������. stack�� �ƴ�.
	}

	//  protected �Ҹ��� - ��ü�� stack �� ���� �� ���� ����.... - page 195 �Ʒ��� �ڵ���.
protected:
	// ��� Ŭ���� �����ͷ�   delete�ϸ� ��� Ŭ������ �Ҹ��ڸ� ȣ��ȴ�. �Ļ�Ŭ������ �Ҹ��ڸ� ȣ���ϰ� �Ϸ��� �Ҹ��ڸ� �����Լ��� �ؾ� �Ѵ�.
	//  Base *p = new Derived  delete p �Ұ�� �Ļ�Ŭ������ �Ҹ��� ȣ���� ���� �������� ������.
	virtual ~RefCountBase()
	{
	}
};
*/

// virtual �� �����ϸ� ���� ���̺��� ����� overhead�� �߻��� ���� virtual�� ����ϰ� ���� ����.
// �׷��� �Ʒ��� ���� �ۼ���.  CRTP (Curiosly Recurring Template Pattern - 71page)
// ��� Ŭ������ template�ε� �Ļ�Ŭ������ ���鶧 �ڽ��� �̸��� ���ø� ���ڷ� ������ �ִ� ���
// �̷��� ������� �Ļ� Ŭ������ �̸��� �̸� ����� �� �ִ�.
template<typename T> class RefCountBase
{
	int m_refCount = 0; //���� ����� ���� ���� c++11���� member field �ʱ�ȭ ������.
public:
	void ref() { ++m_refCount; }
	void deref() // void deref(RefCountBase* this)
	{
		if (--m_refCount == 0) delete static_cast<T*>(this); // delete�� heap�� �ִ� ���� ������. stack�� �ƴ�.
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