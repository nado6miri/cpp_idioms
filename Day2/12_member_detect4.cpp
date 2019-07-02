#include <iostream>
#include <type_traits>
#include <vector>
#include <complex>

template<typename T> struct has_front_function
{
	typedef char YES[1];
	typedef short NO[2];

	// T() : T type의 임시 객체 생성
	template<typename U> static YES& test(decltype(std::declval<U>().front())* arg);  // void type이 넘오올 경우 대비하여 * arg 한다.

	template<typename U> static NO& test(...);// { }
	static constexpr bool value = (sizeof(test<T>(0)) == sizeof(YES));
};


int main()
{
	//bool b = has_front_function<std::vector<int>>::value;
	bool b = has_front_function<std::complex<double>>::value;
	std::cout << b << std::endl;
}