#include <iostream>

// __FUNCTION__   :  C++ 표준 매크로, 함수이름을 나타낸다.
// __FUNCSIG__    : 함수이름 + signature, vc++ 전용
// __PRETTY_FUNCTION__ :  함수이름 + signature, g++ 전용 

void foo(int& a)       { std::cout << __FUNCSIG__ << std::endl; }
void foo(const int& a) { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& a)      { std::cout << __FUNCSIG__ << std::endl; }

int main()
{
	int n = 0;
	foo(n); // 1번호출, 없으면 2번.
	foo(10); // 3번 호출, 없으면 2번

	int& r = n;
	foo(r); // 1번호출, 없으면 2번

	int&& r2 = 10; // 10은 rvalue 지만 r2는 이름이 있고
					// 왼쪽에 올수 있다. 따라서 lvalue이다.
//	10 = 20; //error. 10은 rvalue
//	r2 = 20; // ok
	foo(r2); // 1
	foo(static_cast<int&&>(r2)); // 3
}