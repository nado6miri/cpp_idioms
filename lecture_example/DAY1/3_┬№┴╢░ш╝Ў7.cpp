// 3_참조계수1.cpp
#include <iostream>
#include <vector>

// 237 page . thin template
// 클래스 템플릿이 너무 많은 타입에 대해서 인스턴스화 될때 코드가 
// 커질수 있다 - code bloat
// code bloat 를 막기 위한 기술

// T를 사용하지 않은 멤버 함수는 템플릿이 아닌 기반 클래스를 만들어서
// 상속받자.!!



// 클래스 템플릿을 만들때 
// 템플릿 파라미터 T를 사용하지 않은 멤버 함수는 
// 템플릿이 아닌 기반 클래스를 만들어서 상속받자


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

