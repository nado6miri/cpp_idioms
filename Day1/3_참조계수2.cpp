// 3_참조계수2.cpp

#include<iostream>
#include<vector>

class Car
{
	int m_refCount = 0; //참조 계수를 위한 변수 c++11부터 member field 초기화 가능함.
public:
	void ref() { ++m_refCount;  }
	void deref() { if (--m_refCount == 0) delete this; } // delete는 heap에 있는 것을 삭제함. stack이 아님.

	//  protected 소멸자 - 객체를 stack 에 만들 수 없게 하자.... - page 195 아래쪽 코드임.
protected:
	~Car()
	{
		std::cout << "~Car" << std::endl;
	}

};

void main()
{
	//Car c;	// stack 에 생성함. error
	Car* p1 = new Car;
	p1->ref(); // rule1 : 객체 생성시 참조 계수 증가

	Car* p2 = p1;
	p2->ref();	// 규칙 2 . 포인터 복사시에 참조계수 증가

	p2->deref(); // 규칙3 . 더이상 필요 없을때 참조계수 감소 
	p1->deref(); 
}