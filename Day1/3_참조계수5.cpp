// 3_참조계수5.cpp

#include<iostream>
#include<vector>

template<typename T> class RefCountBase
{
	//  mutable 멤버 데이터 : 상수함수안에서도 값을 수정할 수 있다.
	mutable int m_refCount = 0; //참조 계수를 위한 변수 c++11부터 member field 초기화 가능함.
public:
	// 상수 객체라도 수명을 관리할 수 있어야 한다. 
	// 참조계수를 조작하는 함수는 반드시 "상수 멤버함수" 이어야 한다.
	// 상수함수인데 안에서 값을 변경해야 한다. 따라서 mutable로 선언함.
	void ref() const { ++m_refCount; }
	void deref() const // void deref(RefCountBase* this)
	{
		// 일반 멤버함수에서 this : RefCountedBase* this
		// 상수 멤버함수에서 this :  const RefCountedBase* this
		if (--m_refCount == 0)
		{
			//delete static_cast<T*>(this); // delete는 heap에 있는 것을 삭제함. stack이 아님.
			delete static_cast<T*>(const_cast<RefCountBase*>(this));
			// 또다른 해결책
			//delete static_cast<const T*>(this);
		}
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