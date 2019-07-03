#include <iostream>

void foo(int& arg) { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& arg) { std::cout << __FUNCSIG__ << std::endl; }

void forwarding(int& n) { foo(n); }
//void forwarding(int&& n) { foo(n); }
void forwarding(int&& n) 
{
	// main 에서 10(rvalue)를 보냈는데 int&& n = 10으로 받으면서 lvalue 가 되었다. 즉 value의 특성이 변경되었다.
	// 원래대로 (rvalue로) 캐스팅해서 전달 필요함.
	foo(static_cast<int&&>(n)); 
}

int main()
{
	int x = 10;
	forwarding(x); // x를 foo에 보내고 싶다.
	forwarding(10); // 10을 foo에 보내고 싶다.

	// 10 : rvalue,  n : lvalue  따라서 forwarding(10)을 호출하면  foo() 함수는 두번째 함수가 호출될 것 같지만 첫번째 함수가 호출된다.
	// 따라서 cast_static<int&&>로 casting 하면 두번째 foo() 함수가 호출된다.
	int&& n = 10; 
}

