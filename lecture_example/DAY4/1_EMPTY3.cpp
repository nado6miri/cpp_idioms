#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
/*
int main()
{
	std::vector<int> v = { 1,2,3 };
	auto p1 = v.begin();
	++p1;			// ok
	--p1;			// ok
	p1 = p1 + 3;	// ok

	std::list<int> s = { 1,2,3 };
	auto p2 = s.begin();
	++p2;			// ok
	--p2;			// ok
	p2 = p2 + 3;	// error

	std::forward_list<int> fs = { 1,2,3 }; // �̱۸���Ʈ
	auto p3 = fs.begin();
	++p3;			// ok
	--p3;			// error
	p3 = p3 + 3;	// error

}
*/
// �Է� (�����̳ʿ��� ���� ���� ��)
// ��� (�����̳ʿ� �ִ°�)

// �ݺ��� ī�װ� 5����
// �Է� �ݺ��� : �Է�, ++
// ��� �ݺ��� : ���, ++
// ������ �ݺ��� : �Է�, ++, ��Ƽ �н�      �̱۸���Ʈ �ݺ���
// ����� �ݺ��� : �Է�, ++, --, ��Ƽ �н�  ������Ʈ �ݺ���
// �������� �ݺ��� : �Է�, ++, --, +, -, [], ��Ƽ �н�
//							=> ���ӵ� �޸𸮿� ���� (vector)

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = std::find(s.begin(), s.end(), 5);
		// find �˰����� 1, 2��° ���ڴ� �ݺ��� �Դϴ�.
		// �ּ� �䱸������ �����ϱ�� ?
		// 5���� �����߿��� ��� ������
		// => �Է� �ݺ���
	std::reverse(s.begin(), s.end()); // �ּ� ����
				// => �� ���� �ݺ���

	//std::sort(s.begin(), s.end()); // �� ��Ʈ �Դϴ�.
				// => ���� ���� �ݺ��ڰ� ���޵Ǿ�� �մϴ�.
	s.sort(); // ���� �ƴ� �ٸ� �˰���.

	// ����!
	std::vector<int> v = { 1,2,3 };
	//v.sort(); // �� ��� �Լ��� ������� ?
				// ����... �Ϲ��Լ�(�˰���) sort �� ����ϸ�ȴ�.

	//std::sort()
	// cppreference.com  ���� find ã�� ������.
}






