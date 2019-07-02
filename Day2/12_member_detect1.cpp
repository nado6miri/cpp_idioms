// 12_member_detect1  - 143 page
#include<iostream>
#include<vector>

// cppreference.com ���� allocator�� �˻��� ��.
// vector / list �� �������� �����̳ʿ� ���� �� �� �ִ�. ������ �Ϻ� �����̳ʿ� �Լ��� ������� �б� ó���� �ؾ� ��. front() ���翩�� Ȯ��
template<typename T> void foo(T& c)
{
	auto n = c.front();
}

int main()
{
	std::vector<int> v = { 1, 2, 3, };
	foo(v);

	// 1. MyAllocator�� max_size�� ������ ���, ������ allocator_traits�� max_size ��� - virtual����ص� �ǳ� ���ɶ����� �̰� �� - inline - �����ϴܰ迡�� ġȯ
	MyAllocator<int> ax;
	std::allocator_traits<MyAllocator<int>> at(ax);
	int n = at.max_size(); 
}
