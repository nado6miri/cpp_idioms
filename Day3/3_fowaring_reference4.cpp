#include <iostream>

// 함수인자로 
// int& : int의 lvalue만 전달가능
// int&& : int의 rvalue만 전달가능
// T& : 모든 타임의 lvalue만 전달 가능함.
// T&& : 모든 타입의 lvalue와 rvalue 전달 가능함.

// lvalue(n)을 보내면  T : int&  함수(int&)
// rvalue(0)을 보내면  T : int   함수(int&&)

void f1(int& a) {}
void f2(int& a) {}

template<typename T> void f3(T& a) { }
//f3<int>(n); //호출시 reference callapsing에 따라 & 임 -  lvalue
//f3<int&>(n); //호출시 reference callapsing에 따라 & 임 -  lvalue
//f3<int&&>(n); //호출시 reference callapsing에 따라 & 임 -  lvalue

template<typename T> void f4(T&& a) { }

int main()
{
	int n = 0;
	// 사용자가 type을 직접 전달하면 어떤 함수가 생성될지 생각해 봅시다.
	f4<int>(0); // T : int       T&& : int&&     f4(int&&) -> rvalue
	f4<int&>(n); // T : int&    T&& : int& &&   f4(int&) -> lvalue
	f4<int&&>(0); // T : int&&   T&& : int&& &&   f4(int&&) -> rvalue

	// 사용자가 type을 지정하지 않으면 컴파일러가 타입을 결정해야 한다. 어떻게 결정할 지 생각해 보세요.
	f4(n);  // 컴파일러는 lvalue를 받도록 T를 결정한다. T : int&로 결정하고 최종함수를 f4(int&)로 생성한다.
	f4(0);	// 컴파일러는 rvalue를 받도록 T를 결정한다. T : int로 결정하고, 최종함수는 f2(int&&)로 생성함.
}