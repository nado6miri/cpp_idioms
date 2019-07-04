#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
/*
// STL������ �ݺ��ڸ� 5������ ������
// �Է� : �����̳ʿ��� ���� ���°�
// ��� : �����̳ʿ� �ִ� ��
// 1. �Է� �ݺ��� : �Է�, ++
// 2. ��� �ݺ��� : ���, ++
// 3. ������ �ݺ��� : �Է�, ++, ��Ƽ�н�   --------> �̱۸���Ʈ �ݺ���
// 4. ����� �ݺ��� : �Է�, ++, --, ��Ƽ�н�  --------> ������Ʈ �ݺ���
// 5. �������� �ݺ��� : �Է�, ++, --, +, -, [], ��Ƽ�н� -------> ���ӵ� �޸𸮿� ������ ��ǥ���� ���� vector
*/

/* c++ ǥ�ؿ� ������
// �ݺ��� ī�װ� ������ Ÿ��ȭ �մϴ�.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_iterator_tag : bidirectional_iterator_tag {};

// �� �����̳��� �ݺ��� ����� �ڽ��� ���� ������ �ݺ������� �˷� �־�� �մϴ�.
template<typename T> class vector_iterator
{
public:
	// ��� �ݺ��� �ȿ��� �ݵ�� iterator_category�� ���� �Ǿ�� �մϴ�.
	//typedef random_access_iterator_tag iterator_category; // old style --> using���� ����
	using iterator_category = random_access_iterator_tag;
};

template<typename T> class list_iterator
{
public:
	// ��� �ݺ��� �ȿ��� �ݵ�� iterator_category�� ���� �Ǿ�� �մϴ�.
	//typedef random_access_iterator_tag iterator_category; // old style --> using���� ����
	using iterator_category = random_access_iterator_tag;
};
*/

template<typename T> void advance_imp(T& p, int n, std::random_access_iterator_tag)
{
	std::cout << "��������" << std::endl;
	p = p + n;
}

template<typename T> void advance_imp(T& p, int n, std::input_iterator_tag)
{
	std::cout << "�������� �ƴ�" << std::endl;
	while (n--) ++p;
}


// advance �Լ��� ����� ����
void advance(T& p, int n)
{
	// T : �ݺ���
	// p�� 5���� ������ � ������ �˾ƾ� �Ѵ�.
	// p = p + n;
	advance_imp(p, n, typename T::iterator_category());
}

int main()
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };

	auto p = v.begin();

	advance(p, 3); // vector, list ��� ����
}