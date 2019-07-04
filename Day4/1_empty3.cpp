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
	p2 = p2 + 3; // error - ������ ������ ����� ������ ���� �ʴ´�. stl  ����...

	std::forward_list<int> fs = { 1, 2, 3 }; // single list
	auto p3 = fs.begin();
	++p3; // ok
	--p3; // error - �ڷᱸ���� �ȵ�
	p3 = p3 + 3; // error - ��������.
}

// STL������ �ݺ��ڸ� 5������ ������
// �Է� : �����̳ʿ��� ���� ���°�
// ��� : �����̳ʿ� �ִ� ��
// 1. �Է� �ݺ��� : �Է�, ++
// 2. ��� �ݺ��� : ���, ++
// 3. ������ �ݺ��� : �Է�, ++, ��Ƽ�н�   --------> �̱۸���Ʈ �ݺ���
// 4. ����� �ݺ��� : �Է�, ++, --, ��Ƽ�н�  --------> ������Ʈ �ݺ���
// 5. �������� �ݺ��� : �Է�, ++, --, +, -, [], ��Ƽ�н� -------> ���ӵ� �޸𸮿� ������ ��ǥ���� ���� vector 
*/


int main()
{
	std::list<int> s = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// find �˰����� 1, 2 ��° ���ڴ� �ݺ��� �Դϴ�.
	// �ּ� �䱸������ �����ϰ���? - �Է� �ݺ��� �Դϴ�.
	// 5���� ���� �߿��� ��� ������.
	auto p = std::find(s.begin(), s.end(), 5);

	// �Ʒ� reverse�� �ּ� ������ �����ΰ���?, -- �����ϴ� ����� �ݺ���
	std::reverse(s.begin(), s.end()); 

	// quick sort�� �ּ� ������ �����ΰ���? �������� �ݺ��ڰ� ���� �Ǿ�� �մϴ�.
	//std::sort(s.begin(), s.end()); // error
	//���� linked list����ü�� sort�� �ִ�.
	s.sort();

	// ����
	std::vector<int> v = { 1, 2, 3 };
	//v.sort(); //error -  �����, ���� ���� - �� ����� sort() �Լ��� �������? ----> ����. �Ϲ��Լ�(�˰���) sort�� ����ϸ� �ȴ�.

	/* cppreference.com���� �Ʒ��� ã�� ������.
	std::find;
	std::reserve();
	std::sort();
	*/
}