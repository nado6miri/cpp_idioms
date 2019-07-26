#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

/*
// �ݺ��� ī�װ� ������ Ÿ��ȭ �մϴ�.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

// �� �����̳��� �ݺ��� ����� �ڽ��� ���� ������ �ݺ�������
// �˷� �־�� �մϴ�
template<typename T> class vector_iterator
{
public:
	// ��� �ݺ��ھȿ��� �ݵ�� iterator_category �� ���ǵǾ�� �մϴ�
	//typedef random_access_iterator_tag iterator_category;
	using iterator_category = random_access_iterator_tag;
};

template<typename T> class list_iterator
{
public:
	using iterator_category = bidirectional_iterator_tag;
};
*/

template<typename T>
void advance_imp(T& p, int n, std::random_access_iterator_tag)
{
	std::cout << "��������" << std::endl;
	p = p + n;
}
template<typename T>
void advance_imp(T& p, int n, std::input_iterator_tag)
{
	std::cout << "�������� �ƴ�" << std::endl;
	while (n--) ++p;
}

// �ݺ��� �� ����
// 1. Ŭ������ ������� ��ü ����
// 2. raw pointer
// �� 2���� �������� �ذ��ϴ� ����
template<typename T> struct iterator_traits
{
	using iterator_category = typename T::iterator_category;
};

template<typename T> struct iterator_traits<T*>
{
	using iterator_category = std::random_access_iterator_tag;
};

template<typename T>
void advance(T& p, int n)
{
//	advance_imp(p, n, typename T::iterator_category());

	advance_imp(p, n, typename std::iterator_traits<T>::iterator_category());
}



int main()
{
	//std::list<int> v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	//auto p = v.begin();	// v�� �迭�̸� error

	auto p = std::begin(v);		// v�� �迭�̾ ���� ����

	advance(p, 3);
}





