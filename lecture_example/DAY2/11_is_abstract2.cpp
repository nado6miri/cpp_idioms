// 11_is_abstract1
#include <iostream>
#include <type_traits>

class Shape
{
public:
	virtual void Draw() = 0;
};

// 핵심 1. 함수 템플릿 버전과 가변인자 버전의 2개의 함수를 만든다
//      2. 템플릿 버전은 조건을 만족하지 않으면 실패하게 만든다.

// T arg : 추상클래스라면 실패. 하지만 인자를 보낼때 객체가 필요!
// T* arg : 추상클래스라도 포인터는 만들수 있다. 

// T(*arr)[1] : 배열을 가리키는 포인터 - 추상클래스는 배열을
//				가리키는 포인터를 만들수 없다.

template<typename T> short test(T(*arr)[1]);
template<typename T> char test(...);

int main()
{
	//test<Shape>(0); // 호출. 평가되는 표현식

	// 호출하지 말고, 어느 함수가 호출되는지만 조사.
	int n = sizeof( test<Shape>(0) );

	std::cout << n << std::endl;
}







