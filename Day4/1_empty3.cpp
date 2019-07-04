#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

/*
int main()
{
	std::vector<int> v = { 1, 2, 3 };
	auto p1 = v.begin();
	++p1; // 0k
	--p1; // ok
	p1 = p1 + 3; // ok

	std::list<int> s = { 1, 2, 3 };
	auto p2 = s.begin();
	++p2; // ok
	--p2; // ok
	p2 = p2 + 3; // error - 성능의 문제가 생기면 지원을 하지 않는다. stl  에서...

	std::forward_list<int> fs = { 1, 2, 3 }; // single list
	auto p3 = fs.begin();
	++p3; // ok
	--p3; // error - 자료구조상 안됨
	p3 = p3 + 3; // error - 지원안함.
}

// STL에서는 반복자를 5가지로 구분함
// 입력 : 컨테이너에서 꺼내 오는것
// 출력 : 컨테이너에 넣는 것
// 1. 입력 반복자 : 입력, ++
// 2. 출력 반복자 : 출력, ++
// 3. 전진형 반복자 : 입력, ++, 멀티패스   --------> 싱글리스트 반복자
// 4. 양방향 반복자 : 입력, ++, --, 멀티패스  --------> 더블리스트 반복자
// 5. 임의접근 반복자 : 입력, ++, --, +, -, [], 멀티패스 -------> 연속된 메모리와 유사함 대표적인 것이 vector 
*/


int main()
{
	std::list<int> s = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// find 알고리즘의 1, 2 번째 인자는 반복자 입니다.
	// 최소 요구조건은 무엇일가요? - 입력 반복자 입니다.
	// 5가지 종류 중에서 골라 보세요.
	auto p = std::find(s.begin(), s.end(), 5);

	// 아래 reverse의 최소 조건은 무엇인가요?, -- 지원하는 양방향 반복자
	std::reverse(s.begin(), s.end()); 

	// quick sort의 최소 조건은 무엇인가요? 임의접근 반복자가 전달 되어야 합니다.
	//std::sort(s.begin(), s.end()); // error
	//따라서 linked list는자체에 sort가 있다.
	s.sort();

	// 질문
	std::vector<int> v = { 1, 2, 3 };
	//v.sort(); //error -  양방향, 임의 접근 - 이 멤버는 sort() 함수가 있을까요? ----> 없다. 일반함수(알고리즘) sort를 사용하면 된다.

	/* cppreference.com에서 아래를 찾아 보세요.
	std::find;
	std::reserve();
	std::sort();
	*/
}