#include <iostream>

int main()
{
	int n = 0;
	n = 10; // lvalue : 등호의 왼쪽에 올수 있는 표현식, rvalue : 등호의 왼쪽에 올 수 없는 표현식 (변수 개념이 아님, 표현식 관점에서 봐야함)
	n + 1 = 10; // n+1 : rvalue
	(n = 10) = 20; // n = 10 : lvalue
	// foo(); // void expression

	// 규칙 1. lvalue reference &는 lvalue만 가리킬 수 있다.
	int& r1 = n;  // ok
	//int& r2 = 10; // error

	// 규칙 2 : const lvalue reference &(참조)는 lvalue와  rvalue모두 가리킨다.
	const int& r3 = n;  // ok;
	const int& r4 = 10; // ok; 가리킬 수 있지만 상수성 추가됨.

	// Point() 임시객체는 rvalue
	// 규착 3 : &&는 c++11의 rvalue reference는 rvalue만 가리킬 수 있다.
	int&& r5 = n; // error
	int&& r6 = 10; // ok

}