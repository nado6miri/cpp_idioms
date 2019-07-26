// 3_�������1.cpp
#include <iostream>
#include <vector>

// ���ۿ��� "webkit github"
// source/wtf/wtf/RefCounted.h ��� �ҽ� Ȯ���� ������


class RefCountedBase
{
protected:
	mutable int m_refCount = 0;
public:
	void ref()   const { ++m_refCount; }
};

#define WTF_MAKE_NONCOPYABLE(classname )		\
		classname(const classname&)= delete;	\
		classname& operator=(const classname&) = delete;

template<typename T> class RefCounted : public RefCountedBase
{
	WTF_MAKE_NONCOPYABLE(RefCounted)
protected:
	RefCounted() {}
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
	void Go() { std::cout << "Car::Go" << std::endl; }
};


template<typename T> class AutoPtr
{
	T* m_obj;
public:
	AutoPtr(T* p = 0) : m_obj(p) { if (m_obj) m_obj->ref(); }

	AutoPtr(const AutoPtr& p) : m_obj(p.m_obj)
	{
		if (m_obj) m_obj->ref();
	}
	~AutoPtr() { if (m_obj) m_obj->deref(); }


	T* operator->() { return m_obj; }
	T& operator*() { return *m_obj; }
};

int main()
{
	// ��¥ ������ ó�� AutoPtr�� ����ϸ� �˴ϴ�
	AutoPtr<Car> p1 = new Car; 
	
	p1->Go();  // p1.operator->() �� ���� �Դϴ�.

	AutoPtr<Car> p2 = p1;
}




