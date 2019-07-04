// concept1 - c++20에 추가되는 문법

// 1. concept을 만듭니다.
template<typename T>
concept LessThanCompareable(T a, T b)
{
	{ a < b }-> bool; // {} 안의 연산 결과로  bool이 나와야 함.
};


// Max 함수로 넘어온  T type이 < 연산자를 지원하지 않을 경우.... concept을 이용해서 error msg를 가독성을 높인다.
//template<typename T> T Max(T a, T b)
template<typename T> requires LessThanComparable 
T Max(T a, T b)
{
	return b < a ? a : b;
}

// 아래처럼 축약해서 사용이 가능합니다. - 아래도 template임.
LessThanComparable
T Max(LessThanComparable a, LessThanComparable b)
{
	return b < a ? a : b;
}


int main()
{
	Max(1, 2);
}


//  아래 2개 함수 만들던 것을 좀 더 간단하게 만듬
template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type
foo(T p) {}

template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type
foo(T p) {}


void foo(PointerConcept) {}
void foo(NotPointerConcept) {}

void goo(std::DefaultConstructible a)
{
	using T = std::DefaultConstructible
}

// cppreference.com 들어가보면 concept lib를 확인 가능.