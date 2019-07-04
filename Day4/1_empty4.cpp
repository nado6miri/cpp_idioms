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
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	auto p = v.begin();

	// p�� 3ĭ �����ϰ� �ͽ��ϴ�. ���� ���� �ڵ尡 �����ϱ��?
	// ���� ���ӵ� �޸𸮸� ����ϴ� vector ��� ���� �׽�Ʈ�� ���� list�� �ٲٰ� �Ǹ� ���� �߻�. ���� �� �� �����ϴ� advance()�Լ��� ���� ����.
	//p = p + 3;   // vector�� ������ list�� �ȵ�.
	std::advance(p, 3); // vector, list ��� ����

	
}