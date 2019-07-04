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

// 각 컨테이너의 반복자 설계시 자신이 무슨 종류의 반복자인지 알려 주어야 합니다.
template<typename T> class vector_iterator
{
public:
	// 모든 반복자 안에는 반드시 iterator_category가 정의 되어야 합니다.
	//typedef random_access_iterator_tag iterator_category; // old style --> using으로 변경
	using iterator_category = random_access_iterator_tag;
};

template<typename T> class list_iterator
{
public:
	// 모든 반복자 안에는 반드시 iterator_category가 정의 되어야 합니다.
	//typedef random_access_iterator_tag iterator_category; // old style --> using으로 변경
	using iterator_category = random_access_iterator_tag;
};
*/

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
	advance_imp(p, n, typename T::iterator_category());
}

int main()
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };

	auto p = v.begin();

	advance(p, 3); // vector, list 모두 지원
}