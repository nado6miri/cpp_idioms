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
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	auto p = v.begin();

	// p를 3칸 전진하고 싶습니다. 가장 좋은 코드가 무엇일까요?
	// 만약 연속된 메모리를 사용하는 vector 대신 성능 테스트를 위해 list로 바꾸게 되면 에러 발생. 따라서 둘 다 만족하는 advance()함수가 가장 좋음.
	//p = p + 3;   // vector는 되지만 list는 안됨.
	std::advance(p, 3); // vector, list 모두 지원

	
}