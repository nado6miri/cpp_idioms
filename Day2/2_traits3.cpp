#include<iostream>

template<typename T> struct is_reference
{
	enum { value = false };
};

// ���ø� �κ� Ư��ȭ (specialization) ���� - T �� ���¿� ���� �ٸ� ������ ����ϰڴٴ� �ǹ���. - �� ����ڰ� �����͸� ������ �Ʒ� �ڵ带 �����.
template<typename T> struct is_reference<T&>
{
	enum { value = true };
};


template<typename T> void is_reference(T v)
{
	if (is_reference<T>::value)
		std::cout << "reference" << std::endl;
	else
		std::cout << "reference �ƴ�" << std::endl;
}



template<typename T> struct is_const
{
	enum { value = false };
};

// ���ø� �κ� Ư��ȭ (specialization) ���� - T �� ���¿� ���� �ٸ� ������ ����ϰڴٴ� �ǹ���. - �� ����ڰ� �����͸� ������ �Ʒ� �ڵ带 �����.
template<typename T> struct is_const<const T>
{
	enum { value = true };
};


template<typename T> void is_const(T v)
{
	if (is_const<T>::value)
		std::cout << "const" << std::endl;
	else
		std::cout << "const �ƴ�" << std::endl;
}

int main()
{
	std::cout << is_reference<int>::value << std::endl; // 0
	std::cout << is_reference<int&>::value << std::endl; // 1
	std::cout << is_const<int>::value << std::endl; // 0
	std::cout << is_const<const int>::value << std::endl; // 1
}