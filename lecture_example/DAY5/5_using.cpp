// 5_using
#include <iostream>
#include <type_traits>
/*
// C++14 ���� �Ʒ� �ڵ带 �����մϴ�
// using ����
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;

// variable template �̶�� ����.
template<typename T>
bool is_pointer_v = std::is_pointer<T>::value;
*/
template<typename T> void foo(T a)
{
	//std::remove_
	//bool b = std::is_pointer<T>::value;
	bool b = std::is_pointer_v<T>;

	//typename std::remove_pointer<T>::type  t;
	std::remove_pointer_t<T> t;
}
int main()
{
	int n;
	foo(&n);
}
