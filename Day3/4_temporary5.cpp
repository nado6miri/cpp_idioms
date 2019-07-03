#include <iostream>

struct Base
{
	int value = 10;
};

struct Derived : public Base
{
	int value = 20;
};

int main()
{
	Derived d;
	std::cout << d.value << std::endl; // 20 - 자신의 값이 우선함. 

	// Base의 임시객체를 만들어서 value를 넘겨 줌.
	std::cout << static_cast<Base>(d).value << std::endl; // 10 - Base 의 값 조회시 
	// Base의 참조를 만들어서 value를 넘겨 줌.
	std::cout << static_cast<Base&>(d).value << std::endl; // 10 - Base 의 값 조회시 

	// Base의 임시객체를 만들어서 value 값을 저장 - error 임시객체이기 rvalue임..  때문에...대입 불가
	//static_cast<Base>(d).value = 50;
	// Base의 참조를 만들어서 value에 값을 저장 ok 
	static_cast<Base&>(d).value = 50;
}