#include<iostream>

template<typename T> struct is_reference
{
	enum { value = false };
};

// 템플릿 부분 특수화 (specialization) 문법 - T 의 형태에 따라 다른 구현을 사용하겠다는 의미임. - 즉 사용자가 포인터를 보내면 아래 코드를 사용함.
template<typename T> struct is_reference<T&>
{
	enum { value = true };
};


template<typename T> void is_reference(T v)
{
	if (is_reference<T>::value)
		std::cout << "reference" << std::endl;
	else
		std::cout << "reference 아님" << std::endl;
}



template<typename T> struct is_const
{
	enum { value = false };
};

// 템플릿 부분 특수화 (specialization) 문법 - T 의 형태에 따라 다른 구현을 사용하겠다는 의미임. - 즉 사용자가 포인터를 보내면 아래 코드를 사용함.
template<typename T> struct is_const<const T>
{
	enum { value = true };
};


template<typename T> void is_const(T v)
{
	if (is_const<T>::value)
		std::cout << "const" << std::endl;
	else
		std::cout << "const 아님" << std::endl;
}

int main()
{
	std::cout << is_reference<int>::value << std::endl; // 0
	std::cout << is_reference<int&>::value << std::endl; // 1
	std::cout << is_const<int>::value << std::endl; // 0
	std::cout << is_const<const int>::value << std::endl; // 1
}