// 6_SFINAE3

#include <iostream>

// 핵심 1. 함수 호출시 어떤 함수를 호출하는지 인자만 가지고 결정한다. 반환 타입은 관련없다.
// 템플릿을 사용하기로 결정하고 T를 특정 타입으로 치환할때 실패하면 에러가 아니라 다른 버전의 함수를 사용하게 된다. (SFINAE)
/*
template<typename T>
void foo(T n) 
{ 
	typename T::type n; // 1. SFINAE 적용 안됨 - error발생  int type에 type이 없음.
}
*/

// SFINAE가 적용되는 위치 3곳 (함수 SIGNATURE에 적용)
// 1. 함수 반환값 - 가장 많이 사용되는 기술
template<typename T> typename T::type foo(T n)
{
}

// 2. 함수 인자타입 - 생성자와 같이 반환 타입이 없는 곳에서 SFINAE를 사용하고 싶을때..
template<typename T> void foo(T n, typename T::type n2)
{
}

// 3. 템플릿 인자 - 함수의 모양이 복잡해 지지 않는 특징이 있다. - 잘 사용 안함.
template<typename T, typename T2 = typename T::type> void foo(T n)
{
}



void foo(...) { std::cout << "..." << std::endl; }



int main()
{
	// overloading resolution
	foo(10);
}