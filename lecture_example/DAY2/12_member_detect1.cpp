// 12_member_detect1      143 page
#include <iostream>
#include <vector>

// list : ����Լ� sort()����
// vector : ����Լ� sort()����, �Ϲ� �Լ� sort()��� 
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

	//int n = at.max_size(); // 1. MyAllocator�� max_size�� ������ ���
						// 2. ������ allocator_traits�� max_size���
}

// cppreference.com   ���� allocator �˻�


