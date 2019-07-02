#include<iostream>
#include<type_traits>

template<int N> struct int2type   // 115 page code
{
	enum { value = N };
};


// 포인터인 경우와 포인터가 아닌 경우로 분리해서 2개의 함수 템플릿을 만든다.
template<typename T> void printv_imp(T v, int2type<1>)
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}


template<typename T> void printv_imp(T v, int2type<0>)
{
	std::cout << "not pointer" << std::endl;
	std::cout << v << std::endl;
}

template<typename T> void printv(T a)
{
	// T가 포인터인지에 따라 다른 함수를 호출하게 한다.
	// std::is_pointer<T>::value 의 값은 true / false이기 때문에 type이 같아 함수 오버로딩 불가함. 따라서 int2type을 사용해야 함.
	// int2type<0> 은 type이기 때문에 함수 param으로 사용 불가능, 따라서 ()를 붙이게 되면 임시 객체 생성 - int2type<0>() : 임시객체
	printv_imp(a, int2type<std::is_pointer<T>::value>());
}


int main()
{
	int n = 0;
	printv(n); // 1 - error 
	printv(&n); // 2
}

// ? 채워보세요. 왜 컴파일 에러일까요? - 컴파일러에서 if(false) 로 이미 알고 있지만  if문은 runtime문이기 때문에 코드 포함시키다 보니 에러 발생함.
// 1, 2중 어느곳이 문제일까요? 1번