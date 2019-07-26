#include <iostream>
// lvalue와 rvalue를 모두 전달받는 함수 만들기
// 1. call by value
// void f1(int a) {}

// 2. const lvalue reference
//void f1(const int& a) {}

// 3. 2개의 함수 
//void f1(int&  a) {}
//void f1(int&& a) {}

// 4. 2개의 함수를 자동생성
// T&&  : forwarding reference(universal reference 라고도 합니다)
// int&&: rvalue reference
template<typename T> void f1(T&& a) 
{
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 0;
	f1(n);    // T : int&    f1(int& )
	f1(10);   // T : int     f1(int&&)
}

