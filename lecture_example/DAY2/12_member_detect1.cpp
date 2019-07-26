// 12_member_detect1      143 page
#include <iostream>
#include <vector>

// list : 멤버함수 sort()제공
// vector : 멤버함수 sort()없음, 일반 함수 sort()사용 
template<typename T> 
void foo(T& c)
{
	auto n = c.front(); 
}

int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);

	//--------------------------------
	//MyAllocator<int> ax; 

	//std::allocator_traits<MyAllocator<int>> at(ax);

	//int n = at.max_size(); // 1. MyAllocator에 max_size가 있으면 사용
						// 2. 없으면 allocator_traits의 max_size사용
}

// cppreference.com   에서 allocator 검색


