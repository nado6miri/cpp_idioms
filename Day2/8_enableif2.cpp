#include <iostream>
#include <type_traits>


// 최대 공약수는 정수일때만 동작, 실수일때는 의미가 없음 - 따라서 정수일때만 동작하고 실수일때는 동작하지 않도록 함.
/*
template<typename T> T gcd(T arg1, T arg2)
{
	// arg1, arg2의 최대 공약수를 반환한다고 가정
	// static_assert : 1번째 인자가 false이면 컴파일을 중지한다.
	static_assert(std::is_integral<T>::value, "not integral");
	return 0;
}
*/

// 정수 타입이면 enable, 정수가 아니면 enable_if가 false라서 사용하지 않도록 컴파일타임시 치환이 되지 않아 아래 double gcd()함수로 갈 수 있다.
template<typename T> 
typename std::enable_if<std::is_integral<T>::value, T>::type
gcd(T arg1, T arg2)
{
	// arg1, arg2의 최대 공약수를 반환한다고 가정
	// static_assert : 1번째 인자가 false이면 컴파일을 중지한다.
	static_assert(std::is_integral<T>::value, "not integral");
	return 0;
}


// double 버전의 함수 제공
double gcd(double arg1, double arg2)
{
	std::cout << "double" << std::endl;
	return 0;
}

int main()
{
	gcd(10, 6);
	gcd(3.4f, 2.4f);
}