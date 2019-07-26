// 3_참조계수1.cpp
#include <iostream>
#include <vector>

template<typename T> class RefCountedBase
{
	// mutable 멤버 데이타 : 상수함수안에서도 값을 수정할수 있다
	mutable int m_refCount = 0;
public:

	// 상수 객체라도 수명을 관리할수 있어야 한다.
	// 참조계수를 조작하는 함수는 반드시 "상수 멤버함수" 이어야한다
	void ref()   const { ++m_refCount; }
	
	void deref() const
	{
		//x = 0; //error.  this->x = 0;
		// 일반 멤버 함수에서 this : RefCountedBase* this
		// 상수 멤버 함수에서 this : const RefCountedBase* this

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

