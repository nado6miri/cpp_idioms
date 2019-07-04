#include <iostream>

int Add(int a, int b) { return a + b; }


// 함수객체 : () 연산자를 재정의 해서 함수처럼 사용 가능한 것
// 함수객체 장점 1. 상태를 가지는 함수
// 일반함수는 동작만 있고 상태를 가질 수 없다.
// 함수 객체는 클래스(구조체)이므로 멤버 데이터와 멤버 함수 활용 가능함.

struct Plus
{
	int base;
	Plus(int a = 0) : base(a) {}
	int operator() (int a, int b) { return a + b + base; }
};

int main()
{
	Plus p(100);
	int n1 = Add(1, 2); // ok
	int n2 = p(1, 2); // p.operator()(1,2)의 의미
	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
}