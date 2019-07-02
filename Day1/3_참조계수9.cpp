#include <iostream>
#include <vector>


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
	Car() {}
	~Car() { std::cout << "~Car" << std::endl; }
	void Go() { std::cout << "Car::Go" << std::endl; }
};

// ��ü�� ������� ������� �����ϱ�� ������ �ߴٸ� raw pointer�� ������� ����.
// �� Smart Pointer�� �����ؾ� �Ѵ�.
template<typename T> class AutoPtr
{
	T* m_obj;
public : 
	AutoPtr(T* p = 0) : m_obj(p) {
		if (m_obj) { m_obj->ref(); }
	}
	AutoPtr(const AutoPtr& p) : m_obj(p.m_obj)
	{
		if (m_obj) m_obj->ref();
	}
	~AutoPtr() { if (m_obj) m_obj->deref(); }

	// ��¥ ������ó�� ����� �� �־�� �Ѵ�.
	T* operator->() { return m_obj; }
	T& operator*() { return *m_obj; }
};

int main()
{
	//Car* p1 = new Car;	p1->ref();
	AutoPtr<Car> p1 = new Car; // AutoPtr<Car> p1(new Car)

	//Car* p2 = p1;   	p2->ref();
	AutoPtr<Car> p2 = p1;

	//p2->deref();
	//p1->deref();
}

