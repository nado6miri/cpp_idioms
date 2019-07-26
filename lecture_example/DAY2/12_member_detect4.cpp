#include <iostream>
#include <type_traits>
#include <vector>
#include <array>
#include <complex>

template<typename T> struct has_front_function
{
	typedef char YES[1];
	typedef char NO[2];


	template<typename U>
	static YES&  test( decltype(std::declval<U>().front())*  arg);


	template<typename U>
	static NO& test(...);


	static constexpr bool value =
		(sizeof(test<T>(0)) == sizeof(YES));
};


int main()
{
	bool b = has_front_function<std::vector<int>>::value;

	std::cout << b << std::endl;
}