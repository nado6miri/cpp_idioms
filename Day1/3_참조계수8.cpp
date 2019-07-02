// 3_�������5.cpp

#include<iostream>
#include<vector>

class RefCountedBase
{
protected:
	//  mutable ��� ������ : ����Լ��ȿ����� ���� ������ �� �ִ�.
	mutable int m_refCount = 0; //���� ����� ���� ���� c++11���� member field �ʱ�ȭ ������.
public:
	// ��� ��ü�� ������ ������ �� �־�� �Ѵ�. 
	// ��������� �����ϴ� �Լ��� �ݵ�� "��� ����Լ�" �̾�� �Ѵ�.
	// ����Լ��ε� �ȿ��� ���� �����ؾ� �Ѵ�. ���� mutable�� ������.
	void ref() const { ++m_refCount; }

};

// 237 page - thin template
// Ŭ���� ���ø��� �ʹ� ���� Ÿ�Կ� ���ؼ� �ν��Ͻ�ȭ �ɶ� �ڵ尡 Ŀ�� �� �ִ�. - code bloat - code bloat�� ���� ���� ���
// T�� ������� �ʴ� ��� �Լ��� ���ø��� �ƴ� ��� Ŭ������ ���� ��ӹ���..!!

template<typename T> class RefCounted : public RefCountedBase
{
	// �� Ŭ����(�Ǵ� ��� Ŭ������)�� ���� �Ǹ� �ȵȴ�.
	// �����Ϸ��� ���� �����ڸ� ������ ���ϰ� �Ѵ�. �׻� ������ �����. ���� / ������ ���´�.
	//WTF_MAKE_NOCOPYABLE(RefCounted);
	RefCounted(const RefCounted&) = delete; // c++11 �Լ� ����
	RefCounted& operator = (const RefCounted&) = delete; // ���Ե� ����

public:
	void deref() const // void deref(RefCountBase* this)
	{
		// �Ϲ� ����Լ����� this : RefCountedBase* this
		// ��� ����Լ����� this :  const RefCountedBase* this
		if (--m_refCount == 0)
		{
			//delete static_cast<T*>(this); // delete�� heap�� �ִ� ���� ������. stack�� �ƴ�.
			delete static_cast<T*>(const_cast<RefCounted*>(this));
			// �Ǵٸ� �ذ�å
			//delete static_cast<const T*>(this);
		}
	}

	//  protected �Ҹ��� - ��ü�� stack �� ���� �� ���� ����.... - page 195 �Ʒ��� �ڵ���.
protected:
	RefCounted() {}
	~RefCounted()
	{
	}
};


class Car : public RefCounted<Car> // �̷��� �̿��� �Ļ�Ŭ���� �̸��� �����Ͽ� ���ø����� �����.
{
public:
	~Car() { std::cout << "~Car" << std::endl; }
};

// ���ϳ��� �Ļ� Ŭ������ �����..... ���� Ŭ������ �����ϴ� �Լ��� T�������� ������ T�� ������� ����/�Լ��� �ߺ����� ��. - �����ʿ�.
class Truck : public RefCounted<Truck> // �̷��� �̿��� �Ļ�Ŭ���� �̸��� �����Ͽ� ���ø����� �����.
{
public:
	~Truck() { std::cout << "~Car" << std::endl; }
};

// ref count�� �̿��ؼ� �����ϰ�   p1->deref()�� ����ϸ� �����ϰ� ����ϱ� ���ŷο� ����  shared ptr �� �����.
void main()
{
	Car* p1 = new Car;
	p1->ref(); // rule1 : ��ü ������ ���� ��� ����

	Car* p2 = p1;
	p2->ref();	// ��Ģ 2 . ������ ����ÿ� ������� ����

	Car* p3 = new Car(*p1); 

	p2->deref(); // ��Ģ3 . ���̻� �ʿ� ������ ������� ���� 
	p1->deref();
}