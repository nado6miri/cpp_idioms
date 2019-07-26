#include <iostream>

// 함수 객체의 장점 1. 상태를 가지는 함수
// 일반 함수는 동작만 있고 상태를 가질수 없다.
// 함수 객체는 클래스(구조체)이므로 멤버 데이타와 멤버함수 활용가능

int Add(int a, int b) { return a + b; }


struct Plus
{
	int base;

	Plus(int a = 0) : base(a) {}

	int operator()(int a, int b) { return a + b + base; }
};
int main()
{
	Plus p(100);
	int n1 = Add(1, 2);
	int n2 = p(1, 2);   

}


