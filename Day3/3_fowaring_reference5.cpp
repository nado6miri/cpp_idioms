#include <iostream>
/*
// lvalue와 rvalue를 모두 전달받는 함수 만들기
// 1. call by value
void f1(int a) {}

// 2. lvalue 를 받을 수 있지만 rvalue는 받지 못함. 따라서 f1(int& a) ==> f1(const int& a) ----> const lvalue reference  사용
void f1(int& a) {}

// 3. 2개의 함수 - 2번처럼 const를 사용하고 싶지 않을때
void f1(int& a) {} //lvalue 받는 함수
void f1(int&& a) {} // rvalue 받는 함수
*/
// 4. 2개의 함수를 자동생성 - template 이용함. - 4번을 가장 많이 사용함.
// T&& : forwarding reference (universal reference라고도 합니다.) - T(type) 안에 & && 참조 포함 가능 --> reference collapse 알아야 함.
// int&& : rvalue reference
template<typename T> void f1(T&& a) 
{
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 0;
	f1(n);  // T : int&   f1(int&)
	f1(10); // T : int   f1(int&&)
}