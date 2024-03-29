// 5_평가되지않은표현식
#include <iostream>

short foo(int n)
{
	std::cout << "foo" << std::endl;
	return 0;
}
int main()
{
	int n = 0;
	std::cout << sizeof(n)      << std::endl; // 4
	std::cout << sizeof(&foo)   << std::endl; // 4
	//std::cout << sizeof(foo)    << std::endl; // error.
	
	// sizeof(함수호출식) : 함수 호출의 결과(반환값)의 크기
	
	foo(0); // 함수 호출. 평가되는 표현식
	sizeof(foo(0)); // 함수 호출이 되는것은 아님. 
					//	평가되지 않은 표현식
	std::cout << sizeof( foo(0) ) << std::endl; // 2

	// C++에서 평가되지 않은 표현식은 4개가 있습니다.
	// unevaluated expression

//	sizeof(foo(0));   // 반환값 크기
//	decltype(foo(0)); // 반환값 타입
//	noexcept(foo(0)); // 함수가 예외가 있는지 조사
//	typeid(foo(0));   // 반환값의 타입 정보
}




