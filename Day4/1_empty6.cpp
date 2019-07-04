#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
/*
// STL에서는 반복자를 5가지로 구분함
// 입력 : 컨테이너에서 꺼내 오는것
// 출력 : 컨테이너에 넣는 것
// 1. 입력 반복자 : 입력, ++
// 2. 출력 반복자 : 출력, ++
// 3. 전진형 반복자 : 입력, ++, 멀티패스   --------> 싱글리스트 반복자
// 4. 양방향 반복자 : 입력, ++, --, 멀티패스  --------> 더블리스트 반복자
// 5. 임의접근 반복자 : 입력, ++, --, +, -, [], 멀티패스 -------> 연속된 메모리와 유사함 대표적인 것이 vector
*/

/* c++ 표준에 존재함
// 반복자 카테고리 개념을 타입화 합니다.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_iterator_tag : bidirectional_iterator_tag {};
*/

/*
반복자의 형태
1. 클래스로 만들어진 객체 형태
2. raw pointer
위 2개의 차이점을 해결하는 도구
*/
template<typename T> struct iterator_traits
{
	using iterator_category = typename T::iterator_category;
};

template<typename T> struct iterator_traits<T*>
{
	using iterator_category = std::random_access_iterator_tag; // raw ptr은 random access
};


template<typename T> void advance_imp(T& p, int n, std::random_access_iterator_tag)
{
	std::cout << "임의접근" << std::endl;
	p = p + n;
}

template<typename T> void advance_imp(T& p, int n, std::input_iterator_tag)
{
	std::cout << "임의접근 아님" << std::endl;
	while (n--) ++p;
}


// advance 함수를 만들어 보자
void advance(T& p, int n)
{
	// T : 반복자
	// p가 5가지 유형에 어떤 것인지 알아야 한다.
	// p = p + n;
	//advance_imp(p, n, typename T::iterator_category()); // 배열은 안됨 list / vector ok
	advance_imp(p, n, typename std::iterator_traits<T>::iterator_category); // list, vector, array모두 됨
}

int main()
{
	//std::vector<int> v = { 1, 2, 3, 4, 5 };
	int v[5] = { 1, 2, 3, 4, 5 };

	//auto p = v.begin(); // 배열일 경우 에러
	auto p = std::begin(v); // vector랑 배열이랑 둘다 지원한다.

	advance(p, 3); // vector, list 모두 지원
}