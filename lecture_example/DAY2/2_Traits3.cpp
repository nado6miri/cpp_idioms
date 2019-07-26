#include <iostream>

// is_reference ����� ������.
// is_pointer �� �� ���� ����� ������.
template<typename T> struct is_reference
{
	enum { value = false};
};
template<typename T> struct is_reference<T&>
{
	enum { value = true };
};
template<typename T> struct is_const
{
	enum { value = false };
};
template<typename T> struct is_const<const T>
{
	enum { value = true };
};

int main()
{
	std::cout << is_reference<int>::value << std::endl;  // 0
	std::cout << is_reference<int&>::value << std::endl; // 1

	std::cout << is_const<int>::value << std::endl;       // 0
	std::cout << is_const<const int>::value << std::endl; // 1
}


