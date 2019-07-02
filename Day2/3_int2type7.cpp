#include <iostream>
#include<type_traits>

// int2type을 발전시켜 c++11 표준에 추가된 템플릿
template<typename T, T N> struct integral_constant
{
	// c++11 이전 스타일 - 컴파일시 상수를 만들 수 있는 유일한 방법
	//enum { value = N };
	static constexpr T value = N; // C++ 이후 스타일 - constexpr을 사용한 컴파일 시간 상수 
};

/*
integral_constant<int, 0> t0;
integral_constant<int, 1> t1;
integral_constant<short, 1> t2;

integral_constant<bool, true> b0;
integral_constant<bool, false> b1;

// true/false : 참, 거짓을 나타내는 값. 같은 타입
// true_type / false_type : 참, 거짓을 나타내는 타입. 다른 타입
typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

//C++ 표준의 is_pointer는 아래처럼 만들어 졌습니다.
template<typename T> struct is_pointer : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};
*/


// 포인터인 경우와 포인터가 아닌 경우로 분리해서 2개의 함수 템플릿을 만든다.
template<typename T> void printv_imp(T v, std::true_type)
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}


template<typename T> void printv_imp(T v, std::false_type)
{
	std::cout << "not pointer" << std::endl;
	std::cout << v << std::endl;
}

template<typename T> void printv(T a)
{
	// T가 포인터인지에 따라 다른 함수를 호출하게 한다.
	// std::is_pointer<T>::value 의 값은 true / false이기 때문에 type이 같아 함수 오버로딩 불가함. 따라서 int2type을 사용해야 함.
	// int2type<0> 은 type이기 때문에 함수 param으로 사용 불가능, 따라서 ()를 붙이게 되면 임시 객체 생성 - int2type<0>() : 임시객체
	// is_pointer의 기반클래스는 true_type / false_type임.
	printv_imp(a, std::is_pointer<T>());
}


int main()
{
	int n = 0;
	printv(n); // 1 - error 
	printv(&n); // 2
}



