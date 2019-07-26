// 3_forwarding_reference6
#include <iostream>
void foo(int&  arg) { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& arg) { std::cout << __FUNCSIG__ << std::endl; }

//void forwarding(int& n) { foo(static_cast<int&>(n)) ; }
//void forwarding(int&& n){ foo(static_cast<int&&>(n));}

// 정리. perfect forwarding
// 전달 받은 인자를 다른 곳으로 완벽히전달 하는 기술

// 1. 함수 인자를 T&& 로 받아서
// 2. 다른 곳에 보낼때는 std::forward<T>(arg) 로 묶어서 전달

template<typename T> 
void forwarding(T&& n)
{
	//foo(static_cast<T&&>(n));
	foo( std::forward<T>(n) ); //  forward 안에서 위처럼 캐스팅.
}
// 10 => T : int   T&& : int&&
// n  => T : int&  T&& : int&

int main()
{
	int x = 10;
	forwarding(x);   
	forwarding(10); 
}


