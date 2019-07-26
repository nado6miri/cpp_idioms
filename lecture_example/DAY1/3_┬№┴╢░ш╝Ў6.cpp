// 3_참조계수1.cpp
#include <iostream>
#include <vector>
#include <atomic> // C++11 멀티스레드에 안전한 타입 

template<typename T> class RefCountedBase
{
//	mutable int m_refCount = 0;
	mutable std::atomic<int> m_refCount = 0;
public:

	void ref() const { m_refCount.fetch_add(1); }

	void deref() const
	{
		m_refCount.fetch_sub(1);
		int cnt = m_refCount.load();

		if (cnt == 0)
			delete static_cast<const T*>(this);	
	}
	// 구글 "android github"   1번째 링크
	// platform_system_core/libutils/include/LightRefBase.h


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

