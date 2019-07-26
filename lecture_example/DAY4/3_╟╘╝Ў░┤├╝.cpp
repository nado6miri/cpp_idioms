#include <iostream>

int Add(int a, int b) { return a + b; }

// 함수객체 : () 연산자를 재정의해서 함수 처럼 사용가능한것
struct Plus
{
	int operator()(int a, int b) { return a + b; }
};
int main()
{
	Plus p;
	int n1 = Add(1, 2); // ok
	int n2 = p(1, 2);   // p.operator()(1,2)

	// a + b; // a.operator+(b)
	// a();   // a.operator()()
	// a(1,2);// a.operator()(1,2)
}


