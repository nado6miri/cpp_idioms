// 6_SFINAE2
#include <iostream>

// 핵심 1. 함수 호출시 어떤 함수를 호출하는지는 인자만 가지고 결정
//         한다. 반환 타입은 관련 없다.

// 템플릿을 사용하기로 결정하고, T를 특정 타입으로 치환할때
// 실패하면 에러가 아니라 다른 버전의 함수를 사용하게 한다.

// Subtitution Failure Is Not An Error => SFINAE

template<typename T>
typename T::type foo(T n) { std::cout << "T" << std::endl; return 0; }
// int::type foo(int n) {} 함수를 생성하려고 한다.

void foo(...) { std::cout << "..." << std::endl; }

int main()
{
	foo(10);
}

