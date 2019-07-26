// 3_참조계수1.cpp
#include <iostream>
#include <vector>

class Car
{
	//....
	int m_refCount = 0; // 참조 계수를 위한 변수
					// C++11 부터 member field 초기화 가능
public:
	void ref()   { ++m_refCount; }
	void deref() { if (--m_refCount == 0) delete this; }

	// protected 소멸자 : 객체를 스택에 만들수 없게 한다.
	//                    195 page 아래쪽 코드.
protected:
	~Car() { std::cout << "~Car" << std::endl; }
};

int main()
{
	//Car c;

	Car* p1 = new Car;
	p1->ref();   // 규칙 1. 객체 생성시 참조 계수 증가
	
	Car* p2 = p1;
	p2->ref();   // 규칙 2. 포인터 복사시 참조계수 증가

	p2->deref(); // 규칙 3. 더이상 필요없을때 참조 계수 감소
	p1->deref();
}
  
   