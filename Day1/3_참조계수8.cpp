// 3_참조계수5.cpp

#include<iostream>
#include<vector>

class RefCountedBase
{
protected:
	//  mutable 멤버 데이터 : 상수함수안에서도 값을 수정할 수 있다.
	mutable int m_refCount = 0; //참조 계수를 위한 변수 c++11부터 member field 초기화 가능함.
public:
	// 상수 객체라도 수명을 관리할 수 있어야 한다. 
	// 참조계수를 조작하는 함수는 반드시 "상수 멤버함수" 이어야 한다.
	// 상수함수인데 안에서 값을 변경해야 한다. 따라서 mutable로 선언함.
	void ref() const { ++m_refCount; }

};

// 237 page - thin template
// 클래스 템플릿이 너무 많은 타입에 대해서 인스턴스화 될때 코드가 커질 수 있다. - code bloat - code bloat를 막기 위한 기술
// T를 사용하지 않는 멤버 함수는 템플릿이 아닌 기반 클래스를 만들어서 상속받자..!!

template<typename T> class RefCounted : public RefCountedBase
{
	// 이 클래스(또는 기반 클래스는)는 복사 되면 안된다.
	// 컴파일러가 복사 생성자를 만들지 못하게 한다. 항상 쌍으로 사용함. 복사 / 대입을 막는다.
	//WTF_MAKE_NOCOPYABLE(RefCounted);
	RefCounted(const RefCounted&) = delete; // c++11 함수 삭제
	RefCounted& operator = (const RefCounted&) = delete; // 대입도 삭제

public:
	void deref() const // void deref(RefCountBase* this)
	{
		// 일반 멤버함수에서 this : RefCountedBase* this
		// 상수 멤버함수에서 this :  const RefCountedBase* this
		if (--m_refCount == 0)
		{
			//delete static_cast<T*>(this); // delete는 heap에 있는 것을 삭제함. stack이 아님.
			delete static_cast<T*>(const_cast<RefCounted*>(this));
			// 또다른 해결책
			//delete static_cast<const T*>(this);
		}
	}

	//  protected 소멸자 - 객체를 stack 에 만들 수 없게 하자.... - page 195 아래쪽 코드임.
protected:
	RefCounted() {}
	~RefCounted()
	{
	}
};


class Car : public RefCounted<Car> // 미래에 이용할 파생클래스 이름을 전달하여 템플릿으로 사용함.
{
public:
	~Car() { std::cout << "~Car" << std::endl; }
};

// 또하나의 파생 클래스가 생기면..... 기초 클래스에 존재하는 함수는 T붙은것을 제외한 T와 상관없는 변수/함수는 중복으로 됨. - 개선필요.
class Truck : public RefCounted<Truck> // 미래에 이용할 파생클래스 이름을 전달하여 템플릿으로 사용함.
{
public:
	~Truck() { std::cout << "~Car" << std::endl; }
};

// ref count를 이용해서 관리하고   p1->deref()를 사용하면 불편하고 사용하기 번거로움 따라서  shared ptr 을 사용함.
void main()
{
	Car* p1 = new Car;
	p1->ref(); // rule1 : 객체 생성시 참조 계수 증가

	Car* p2 = p1;
	p2->ref();	// 규칙 2 . 포인터 복사시에 참조계수 증가

	Car* p3 = new Car(*p1); 

	p2->deref(); // 규칙3 . 더이상 필요 없을때 참조계수 감소 
	p1->deref();
}