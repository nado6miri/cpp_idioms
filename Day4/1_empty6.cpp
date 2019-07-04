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
*/

/*
�ݺ����� ����
1. Ŭ������ ������� ��ü ����
2. raw pointer
�� 2���� �������� �ذ��ϴ� ����
*/
template<typename T> struct iterator_traits
{
	using iterator_category = typename T::iterator_category;
};

template<typename T> struct iterator_traits<T*>
{
	using iterator_category = std::random_access_iterator_tag; // raw ptr�� random access
};


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
	//advance_imp(p, n, typename T::iterator_category()); // �迭�� �ȵ� list / vector ok
	advance_imp(p, n, typename std::iterator_traits<T>::iterator_category); // list, vector, array��� ��
}

int main()
{
	//std::vector<int> v = { 1, 2, 3, 4, 5 };
	int v[5] = { 1, 2, 3, 4, 5 };

	//auto p = v.begin(); // �迭�� ��� ����
	auto p = std::begin(v); // vector�� �迭�̶� �Ѵ� �����Ѵ�.

	advance(p, 3); // vector, list ��� ����
}