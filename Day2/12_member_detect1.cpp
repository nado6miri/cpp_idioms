// 12_member_detect1  - 143 page
#include<iostream>
#include<vector>

// cppreference.com 에서 allocator를 검색할 것.
// vector / list 등 공통으로 컨테이너에 대해 쓸 수 있다. 하지만 일부 컨테이너에 함수가 없을경우 분기 처리를 해야 함. front() 존재여부 확인
template<typename T> void foo(T& c)
{
	auto n = c.front();
}

int main()
{
	std::vector<int> v = { 1, 2, 3, };
	foo(v);

	// 1. MyAllocator에 max_size가 있으면 사용, 없으면 allocator_traits의 max_size 사용 - virtual사용해도 되나 성능때문에 이걸 씀 - inline - 컴파일단계에서 치환
	MyAllocator<int> ax;
	std::allocator_traits<MyAllocator<int>> at(ax);
	int n = at.max_size(); 
}
