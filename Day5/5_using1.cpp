#include <iostream>
#include <type_traits>

// pointer�� ������ type
// typename std::remove_pointer<T>::type t;

// �� �ڵ尡 ������. ���� c++14���� �Ʒ� �ڵ带 ������
template<typename T> using remove_pointer_t = typename std::remove_pointer<T>::type;

// C++ 17�ɼ� - variable template��� ������.
template<typename T> bool is_pointer_v = std::is_pointer<T>::valule;

std::remove_

template<typename T> void foo(T a)
{
	bool b = std::is_pointer<T>::valule;
	//bool b = std::is_pointer_v<T>; // ���� ������...

	// pointer�� ������ type
	//typename std::remove_pointer<T>::type t;  // �����ؼ� �Ʒ� c++14 style��...
	remove_pointer_t<T> t;
}

int main()
{
	int n;
	foo(&n);
}