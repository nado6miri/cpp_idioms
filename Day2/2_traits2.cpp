// 2_traits  115. int - To - Type 관련 (마지막 문제)
#include <iostream>

// Traits : 템블릿 인자T의 다양한 특질(Traits)를 조사하는 기술임.
// is_pointer : 컴파일 할때 T가 포인터인지 조사하는 도구 - 컴파일할때 사용하는 함수라는 의미로 metafunction이라고도 한다.
// 만드는 방법
// 1. 구조체 템플릿을 만든다.
// 2. enum { value = false }를 넣는다.
// 3. 조건을 만족하는 부분 특수화 버전을 만든다. 그리고 enum { value = true }를 넣는다.
template<typename T> struct is_pointer
{
	enum { value = false  };
};

// 템플릿 부분 특수화 (specialization) 문법 - T 의 형태에 따라 다른 구현을 사용하겠다는 의미임. - 즉 사용자가 포인터를 보내면 아래 코드를 사용함.
template<typename T> struct is_pointer<T*>
{
	enum { value = true };
};


template<typename T> void foo(T v)
{
	if (is_pointer<T>::value)
		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}

int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}