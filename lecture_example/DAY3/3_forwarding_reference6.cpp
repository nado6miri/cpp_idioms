// 3_forwarding_reference6
#include <iostream>
void foo(int&  arg) { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& arg) { std::cout << __FUNCSIG__ << std::endl; }

void forwarding(int& n)  { foo(n); }
void forwarding(int&& n) 
{
	// main 에서 10(rvalue)를 보냈는데
	// int&& n = 10   으로 받으면서 lvalue 가 되었다.
	// 즉, value의 특성이 변경되었다.
	// 원래 대로(rvalue로) 캐스팅해서 전달
	foo(static_cast<int&&>(n)); 
}

int main()
{
	int x = 10;
	forwarding(x); // x를 foo에 보내고 싶다.
	forwarding(10);// 10을 foo에 보내고 싶다.

	int&& n = 10; // 10 : rvalue
				  // n  : lvalue 
}


