#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

/*
// 반복자 카테고리 개념을 타입화 합니다.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

// 각 컨테이너의 반복자 설계시 자신이 무슨 종류의 반복자인지
// 알려 주어야 합니다
template<typename T> class vector_iterator
{
public:
	// 모든 반복자안에는 반드시 iterator_category 가 정의되어야 합니다
	//typedef random_access_iterator_tag iterator_category;
	using iterator_category = random_access_iterator_tag;
};

template<typename T> class list_iterator
{
public:
	using iterator_category = bidirectional_iterator_tag;
};
*/

template<typename T>
void advance_imp(T& p, int n, std::random_access_iterator_tag)
{
	std::cout << "임의접근" << std::endl;
	p = p + n;
}
template<typename T>
void advance_imp(T& p, int n, std::input_iterator_tag)
{
	std::cout << "임의접근 아님" << std::endl;
	while (n--) ++p;
}

// 반복자 의 형태
// 1. 클래스로 만들어진 객체 형태
// 2. raw pointer
// 위 2개의 차이점을 해결하는 도구
template<typename T> struct iterator_traits
{
	using iterator_category = typename T::iterator_category;
};

template<typename T> struct iterator_traits<T*>
{
	using iterator_category = std::random_access_iterator_tag;
};

template<typename T>
void advance(T& p, int n)
{
//	advance_imp(p, n, typename T::iterator_category());

	advance_imp(p, n, typename std::iterator_traits<T>::iterator_category());
}



int main()
{
	//std::list<int> v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	//auto p = v.begin();	// v가 배열이면 error

	auto p = std::begin(v);		// v가 배열이어도 문제 없다

	advance(p, 3);
}





