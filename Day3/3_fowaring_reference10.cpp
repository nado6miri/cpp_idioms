#include <iostream>

// pair : 2개의 값을 보관하는 구조체
template<typename T, typename U> struct pair
{
	T first;
	U second;

	// 생성자 모양 1. call by value - 복사 overhead발생하여 참조로 변경 필요
	//pair(T a, U b) : first(a), second(b) {}

	// 생성자 모양 2. non const - lvaule reference - rvalue 를 받지 못함. - const를 이용 받기필요
	//pair(T& a, U& b) : first(a), second(b) {}

	// 생성자 모양 3. const - lvaule reference - lvalue / rvalue 모두 받음. 하지만 const가 추가되었음.. const추가 안하고 받으려면 forwarding reference 사용
	//pair(const T& a, const U& b) : first(a), second(b) {}

	// 생성자 모양 4. c++11 이후 스타일
	template<typename A, typename B> pair(A&& a, B&& b) : first(std::forward<A>(a)), second(std::forward<B>(b)) {}

};

int main()
{
	int a = 10, b = 20;
	pair<int, int> p1(10, 20);
	pair<int, int> p2(a, b);
	pair<int&, int&> p3(a, b);
	pair<int&&, int&&> p4(10, 20); 

	std::pair<int, double> p5;

}

// webkit / source/wtf/wtf/scope.h
// makeScopeExit 함수와 scopeExit 클래스 생성자를 보세요.