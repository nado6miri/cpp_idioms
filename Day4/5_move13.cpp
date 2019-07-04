#include <iostream>
#include <vector>
#include <string>
#include <vector>

template<typename T, typename U> struct pair
{
	T first;
	U second;

	pair(const T& a, const T& b) : first(a), second(b) {};
	template<typename A = T, typename B = U>
	pair(A&& a = A(), B&& b = B()) 
		: first(std::forward<A>(a))
		, second(std::forward<B>(b)) {};
};

int main()
{
	int x, y;
	pair<int, int> p1(std::move(x), std::move(y));
	pair<int, int> p2; // type을 안줬을 경우....default type 처리함.

}