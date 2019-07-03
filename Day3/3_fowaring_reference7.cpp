#include <iostream>

void foo(int& arg) { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& arg) { std::cout << __FUNCSIG__ << std::endl; }

// 두개의 함수를 하나로 통일하려면 템플릿 이용 - 그러나 함수에 cast 연상자 때문에....
//void forwarding(int& n) { foo(static_cast<int&>(n)); }
//void forwarding(int&& n) { foo(static_cast<int&&>(n)); }

// 정리 : perfect forwarding : 전달받은 인자를 다른곳으로 전달시 완벽히 전달하는 기술
// 1. 함수 인자를 T&&로 받아서
// 2. 다른곳으로 받을때는 std::forward(T>(arg)로 묶어서 전달함.
template<typename T> void forwarding(T&& n)
{
	//foo(static_cast<T&&>(n));
	// 표준에 있는 forward를 쓰면 간단히 처리 됨.
	foo(std::forward<T>(n)); //forward 안에서 위처럼 casting됨.
}

// 10 => T : int   T&& : int&&
// n =>  T : int&  T&& : int&

int main()
{
	int x = 10;
	forwarding(x); // x를 foo에 보내고 싶다.
	forwarding(10); // 10을 foo에 보내고 싶다.
}

