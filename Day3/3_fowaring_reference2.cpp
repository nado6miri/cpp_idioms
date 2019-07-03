#include <iostream>

// __FUNCTION__ : C++ 표준 매크로 - 함수 이름을 나타냄
// __FUNCSIG__ : 함수이름 + SIGNATURE, VC++전용임
// __PRETTY_FUNCTION__ :  함수이름 + SIGNATURE, G++전용임
void foo(int& a) { std::cout << __FUNCSIG__ << std::endl; }
void foo(const int& a) { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& a) { std::cout << __FUNCSIG__ << std::endl; }

int main()
{
	int n = 0;
	foo(n); // 오버로딩에서 const가 없기 때문에 const가 없는 것부터 찾는다. 1번호출 없으면 2번 호출
	foo(10); // 2번 또는 3번으로 가는데 const가 없기 때문에 3번으로 호출, 없으면 2번 호출

	int& r = n;
	foo(r); // 1번 호출, 없으면 2번 호출

	int&& r2 = 10; // 10은 rvalue, r2는 이름이 있고 왼쪽에 올 수 있다. 따라서  lvalue이다.
	r2 = 20;
	foo(r2); // 1번 호출됨.

	foo(static_cast<int&&>(r2)); // 3번 호출됨.
}