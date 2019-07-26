// 3_참조계수1.cpp
#include <iostream>
#include <vector>

// 구글에서 "webkit github"
// source/wtf/wtf/RefCounted.h 열어서 소스 확인해 보세요


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
	// 진짜 포인터 처럼 AutoPtr을 사용하면 됩니다
	AutoPtr<Car> p1 = new Car; 
	
	p1->Go();  // p1.operator->() 의 원리 입니다.

	AutoPtr<Car> p2 = p1;
}




