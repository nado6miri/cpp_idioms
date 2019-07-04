#include <iostream>

int Add(int a, int b) { return a + b; }


// 함수객체 : () 연산자를 재정의 해서 함수처럼 사용 가능한 것

struct Plus
{
	int operator() (int a, int b) { return a + b; }
};

int main()
{
	Plus p;
	int n1 = Add(1, 2); // ok
	int n2 = p(1, 2); // p.operator()(1,2)의 의미

	// a + b ; // a.operator+(b) 의미
	// a();    // a.operator()() 의미
	// a(1, 2); // a.operator()(1,2) 의미
}