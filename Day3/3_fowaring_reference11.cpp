#include <iostream>

//template<typename T> void foo(const T& f)
template<typename T> void foo(T&& f)
{
	//f();
	std::forward<T>(f)();
}

void goo() { std::cout << "goo" << std::endl; }

int main()
{
	foo(goo);
	// ���� ǥ������ rvalue �Դϴ�.
	// mutable ���� ǥ���� : () ������ �Լ��� ���� ����� �ش޶�� �ǹ���.
	foo([]() mutable { std::cout << "lambda" << std::endl;  });
}