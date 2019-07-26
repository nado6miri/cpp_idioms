// concept1 - c++20 에 추가되는 문법

// 1. concept 을 만듭니다.
template<typename T>
cencept LessThanComparable(T a, T b)
{
	{a < b}->bool;
};

// 2. 템플릿을 만들때 T가 가져야 하는 조건(개념)을 명시합니다.
template<typename T> requires LessThanComparable 
T Max(T a, T b)
{
	return b < a ? a : b;
}

// 아래 처럼 축약해서 사용가능합니다.
LessThanComparable
Max(LessThanComparable a, LessThanComparable b)
{
	return b < a ? a : b;
}


int main()
{
	Max(1, 2);
}

template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type
foo(T p) {}

template<typename T>
typename std::enable_if<!std::is_pointer<T>::value>::type
foo(T p) {}

// g++ 소스이름.cpp  -fconcepts  로 컴파일 가능.
void foo(PointerConcept)    {}
void foo(NotPointerConcept) {}
void goo(std::DefaultConstructible a)
{
	using T = std::DefaultConstructible;
	T b; // 디폴트 생성자 필요
}
// cppreference.com