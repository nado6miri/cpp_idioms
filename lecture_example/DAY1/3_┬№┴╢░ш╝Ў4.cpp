// 3_참조계수1.cpp
#include <iostream>
#include <vector>

// CRTP ( Curiosly Recurring Template Pattern ) - 71
// 기반 클래스가 템플릿 인데. 파생 클래스를 만들때 자신의 이름을
// 템플릿 인자로 전달해 주는 기술.
// 미래에 만들어질 파생클래스의 이름을 미리 사용할수 있다.

template<typename T> class RefCountedBase
{
	int m_refCount = 0;
public:
	void ref() { ++m_refCount; }
	void deref()   
	{
		if (--m_refCount == 0)
			delete static_cast<T*>(this);
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
	Car* p1 = new Car;
	p1->ref();

	Car* p2 = p1;
	p2->ref();

	p2->deref();
	p1->deref();
}

