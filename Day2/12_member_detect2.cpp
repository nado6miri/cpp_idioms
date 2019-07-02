#include <iostream>
#include <type_traits>
#include <vector>
#include <complex>

template<typename T> struct has_front_function
{
	typedef char YES[1];
	typedef short NO[2];

	// T() : T type의 임시 객체 생성
	// decltype(표현식) arg : 표현식의 타입과 동일한 타입의 변수 arg 생성
	template<typename T> static YES& test(decltype(T().front())* arg);  // void type이 넘오올 경우 대비하여 * arg 한다.

	template<typename T> static NO& test(...);// { }
	static constexpr bool value = (sizeof(test<T>(0)) == sizeof(YES));
};


int main()
{
	//bool b = has_front_function<std::vector<int>>::value;
	bool b = has_front_function<std::complex<double>>::value;
	std::cout << b << std::endl;
}