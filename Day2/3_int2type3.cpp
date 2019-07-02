#include<iostream>
#include<type_traits>


// 포인터인 경우와 포인터가 아닌 경우로 분리해서 2개의 함수 템플릿을 만든다.
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
	// if문 : 실행시간 조건문 - 조건문의 결과에 상관없이 컴파일시 아래 2개 함수 템플릿 모두 사용된다고 컴파일러가 생각하고 2개 함수 인스턴스화 됨.
	// 컴파일할때 포함을 시키지 않도록 조치 필요...함수 overloading은 컴파일시 코드를 포함시키지 않도록 해야 함. - 해결책
	if (std::is_pointer<T>::value)  //포인터 인지 조사 - 컴파일할때 알고 있다. true 인지 false 인지...
	{
		printv_imp_pointer(a);
	}
	else
	{
		printv_imp_not_pointer(a);
	}
}


int main()
{
	int n = 0;
	printv(n); // 1 - error 
	printv(&n); // 2
}

// ? 채워보세요. 왜 컴파일 에러일까요? - 컴파일러에서 if(false) 로 이미 알고 있지만  if문은 runtime문이기 때문에 코드 포함시키다 보니 에러 발생함.
// 1, 2중 어느곳이 문제일까요? 1번