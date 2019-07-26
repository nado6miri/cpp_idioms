#include <iostream>
#include <type_traits>


// 포인터 인 경우와 포인터가 아닌 경우로 분리해서 
// 2개의 함수 템플릿을 만든다

template<typename T> void printv_imp_pointer(T v)
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> void printv_imp_not_pointer(T v)
{
	std::cout << "not pointer" << std::endl;
	std::cout << v << std::endl;
}

template<typename T> void printv(T a)
{
	// if 문 : 실행시간 조건문
	//         조건의 결과에 상관없이 컴파일 할때는
	//         아래 2개의 함수 템플릿 모두 사용된다고 
	//         컴파일러가 생각해서 2개 함수 모두 인스턴스화 됩니다.
	if (std::is_pointer<T>::value)
		printv_imp_pointer(a);
	else
		printv_imp_not_pointer(a);
}


int main()
{
	int n = 0;
	printv(n); 
}
