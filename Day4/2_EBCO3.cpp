#include <iostream>
#include <type_traits>

class Empty {};

template<typename T
	, typename U
	, bool b = std::is_empty<T>::value> 
struct PAIR
//{};

// 결국 위의 pair는 사용하지 않고 아래 2개만 사용됩니다. 이 경우에는 선언만 해도 됩니다.
// 아래 소스가 boost lib 의 "compress_pair" 입니다.
// c++  표준인 unique_ptr 만들때 이 기술이 사용된다.

template<typename T, typename U> struct PAIR<T, U, false> // 부분 특수화
{
	T v1;
	U v2;
	T& getValue1() { return v1; };
	U& getValue2() { return v2; };

	template<typename A, typename B>
	PAIR(A&& a, B&& b) : v1(std::forward(<A>(a)), v2(std::forward<B>(b)) {};

	PAIR() = default; // default 생성자를 만들어라.  PAIR {} 와 동일 의미
};

template<typename T, typename U> struct PAIR : public T
{
	U v2;
	T& getValue1() { return *this; };
	U& getValue2() { return v2; };

	template<typename A, typename B>
	PAIR(A&& a, B&& b) : T(std::forward(<A>(a))  // 기반 클래스 생성자 호출
		, v2(std::forward<B>(b)) {};

	PAIR() = default; // default 생성자를 만들어라.  PAIR {} 와 동일 의미
};


int main()
{
	PAIR<Empty, int> p;
	std::cout << sizeof(p) << std::endl;
	PAIR<int, Empty> p2;
	std::cout << sizeof(p2) << std::endl;
};

//4 / 8이 출력돼야 하는뎅.... 8/4가 출력... ?? 개선필요