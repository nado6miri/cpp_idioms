#include <iostream>
#include <type_traits>
#include <vector>
#include <complex>

template<typename T> struct has_front_function
{
	typedef char YES[1];
	typedef short NO[2];

	// T() : T type�� �ӽ� ��ü ����
	// decltype(ǥ����) arg : ǥ������ Ÿ�԰� ������ Ÿ���� ���� arg ����
	template<typename T> static YES& test(decltype(T().front())* arg);  // void type�� �ѿ��� ��� ����Ͽ� * arg �Ѵ�.

	template<typename T> static NO& test(...);// { }
	static constexpr bool value = (sizeof(test<T>(0)) == sizeof(YES));
};


int main()
{
	//bool b = has_front_function<std::vector<int>>::value;
	bool b = has_front_function<std::complex<double>>::value;
	std::cout << b << std::endl;
}