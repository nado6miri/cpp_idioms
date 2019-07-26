#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>


// tag dispatching : ����ǥ�� ���� �Լ� �й�.
/*
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

template<typename T>
void advance(T& p, int n)
{
	advance_imp(p, n, typename std::iterator_traits<T>::iterator_category());
}
*/
// enable_if �������� ������ ���ô�.
template<typename T>
typename std::enable_if<
	std::is_same< 
		typename std::iterator_traits<T>::iterator_category,
		std::random_access_iterator_tag>::value>::type
advance(T& p, int n)
{
	std::cout << "��������" << std::endl;
	p = p + n;
}

template<typename T>
typename std::enable_if<
	!std::is_same<
	typename std::iterator_traits<T>::iterator_category,
	std::random_access_iterator_tag>::value>::type
advance(T& p, int n)
{
	std::cout << "�������� �ƴ�" << std::endl;
	while (n--) ++p;
}

int main()
{
	int v[5] = { 1,2,3,4,5 };

	auto p = std::begin(v);

	advance(p, 3);
}





