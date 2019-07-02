// 3_참조계수1.cpp

#include<iostream>
#include<vector>

/*
// ref counter를 관리하는 기초 클래스를 생성하자.
class RefCountBase
{
	int m_refCount = 0; //참조 계수를 위한 변수 c++11부터 member field 초기화 가능함.
public:
	void ref() { ++m_refCount; }
	void deref() // void deref(RefCountBase* this)
	{
		if (--m_refCount == 0) delete this; // delete는 heap에 있는 것을 삭제함. stack이 아님.
	}

	//  protected 소멸자 - 객체를 stack 에 만들 수 없게 하자.... - page 195 아래쪽 코드임.
protected:
	// 기반 클래스 포인터로   delete하면 기반 클래스의 소멸자만 호출된다. 파생클래스의 소멸자를 호출하게 하려면 소멸자를 가상함수로 해야 한다.
	//  Base *p = new Derived  delete p 할경우 파생클래스의 소멸자 호출을 위해 가상으로 선언함.
	virtual ~RefCountBase()
	{
	}
};
*/

// virtual 을 생성하면 가상 테이블이 생기고 overhead가 발생함 따라서 virtual을 사용하고 싶지 않음.
// 그래서 아래와 같이 작성함.  CRTP (Curiosly Recurring Template Pattern - 71page)
// 기반 클래스가 template인데 파생클래스를 만들때 자신의 이름을 템플릿 인자로 전달해 주는 기술
// 미래에 만들어질 파생 클래스의 이름을 미리 사용할 수 있다.
template<typename T> class RefCountBase
{
	int m_refCount = 0; //참조 계수를 위한 변수 c++11부터 member field 초기화 가능함.
public:
	void ref() { ++m_refCount; }
	void deref() // void deref(RefCountBase* this)
	{
		if (--m_refCount == 0) delete static_cast<T*>(this); // delete는 heap에 있는 것을 삭제함. stack이 아님.
	}

	//  protected 소멸자 - 객체를 stack 에 만들 수 없게 하자.... - page 195 아래쪽 코드임.
protected:
	~RefCountBase()
	{
	}
};



class Car : public RefCountBase<Car> // 미래에 이용할 파생클래스 이름을 전달하여 템플릿으로 사용함.
{
public:
	~Car() { std::cout << "~Car" << std::endl; }
};

void main()
{
	Car* p1 = new Car;
	p1->ref(); // rule1 : 객체 생성시 참조 계수 증가

	Car* p2 = p1;
	p2->ref();	// 규칙 2 . 포인터 복사시에 참조계수 증가

	p2->deref(); // 규칙3 . 더이상 필요 없을때 참조계수 감소 
	p1->deref();
}