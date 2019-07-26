#include <iostream>

// __FUNCTION__   :  C++ ǥ�� ��ũ��, �Լ��̸��� ��Ÿ����.
// __FUNCSIG__    : �Լ��̸� + signature, vc++ ����
// __PRETTY_FUNCTION__ :  �Լ��̸� + signature, g++ ���� 

void foo(int& a)       { std::cout << __FUNCSIG__ << std::endl; }
void foo(const int& a) { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& a)      { std::cout << __FUNCSIG__ << std::endl; }

int main()
{
	int n = 0;
	foo(n); // 1��ȣ��, ������ 2��.
	foo(10); // 3�� ȣ��, ������ 2��

	int& r = n;
	foo(r); // 1��ȣ��, ������ 2��

	int&& r2 = 10; // 10�� rvalue ���� r2�� �̸��� �ְ�
					// ���ʿ� �ü� �ִ�. ���� lvalue�̴�.
//	10 = 20; //error. 10�� rvalue
//	r2 = 20; // ok
	foo(r2); // 1
	foo(static_cast<int&&>(r2)); // 3
}