//11_is_abstract1
#include<iostream>
#include<type_traits>

// 143 page....

// 핵심 1. 함수 템플릿 버전과 가변인자 버전의 2개 함수를 만든다.
// 2. 템플릿 버전은 조건을 만족하지 않으면 실패하게 만든다. (컴파일시)

// T arg : 추상클래스라면 실패함. 하지만 인자를 보낼때 객체가 필요!!
// T* arg : 추상클래스라도 포인터는 만들 수 있다.
// T(*arr)[1] : 배열을 가리키는 포인터 - 추상클래스는 배열을 가리키는 포인터를 만들 수 없다.

// 추상클래스에서는 실패하도록 함.
template<typename T> short test(T(*arr)[1]);// {}

// 추상클래스는 사용가능함.
template<typename T> char test(...);// { }


class Shape
{
public:
	//virtual void Draw() = 0;
};

int main()
{
	// test<Shape>(0); // 호출, 평가되는 표현식
	int n = sizeof(test<Shape>(0)); // 함수 call은 하지 않고 return값의 size만....조사함.

	std::cout << n << std::endl;
}


