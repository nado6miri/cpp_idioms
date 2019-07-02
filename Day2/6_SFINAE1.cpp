// 6_SFINAE1

#include <iostream>

//void foo(int n) { std::cout << "int" << std::endl; }
//void foo(float n) { std::cout << "float" << std::endl; }
//void foo(double n) { std::cout << "double" << std::endl; }
void foo(...) { std::cout << "..." << std::endl; }

//template<typename T> void foo(T n) { std::cout << "T" << std::endl; }


int main()
{
	float f = 3.4f;

	// overloading resolution
	foo(f); // 1. float 함수 호출 - exactly matching - float
	// 위 foo(float)를 주석 처리하면 어떤 함수가 호출될까 - template가 생성된다.
	// 다시 template 함수를 주석처리하면 어떤 함수가 호출될까 - double 함수가 호출됨. data 손실이 없는 방향으로 감 - promotion
	// 다시 double을 주석처리하면 어떤 함수가 호출될까? - int 함수가 호출됨 - standard conversion(표준 타입끼리 변환됨)
	// int 함수를 주석처리 하면 어떤 함수가 호출될까? - 가변인자 함수가 맨 마지막에 호출된다.
}