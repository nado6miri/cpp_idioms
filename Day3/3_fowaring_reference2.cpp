#include <iostream>

// __FUNCTION__ : C++ ǥ�� ��ũ�� - �Լ� �̸��� ��Ÿ��
// __FUNCSIG__ : �Լ��̸� + SIGNATURE, VC++������
// __PRETTY_FUNCTION__ :  �Լ��̸� + SIGNATURE, G++������
void foo(int& a) { std::cout << __FUNCSIG__ << std::endl; }
void foo(const int& a) { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& a) { std::cout << __FUNCSIG__ << std::endl; }

int main()
{
	int n = 0;
	foo(n); // �����ε����� const�� ���� ������ const�� ���� �ͺ��� ã�´�. 1��ȣ�� ������ 2�� ȣ��
	foo(10); // 2�� �Ǵ� 3������ ���µ� const�� ���� ������ 3������ ȣ��, ������ 2�� ȣ��

	int& r = n;
	foo(r); // 1�� ȣ��, ������ 2�� ȣ��

	int&& r2 = 10; // 10�� rvalue, r2�� �̸��� �ְ� ���ʿ� �� �� �ִ�. ����  lvalue�̴�.
	r2 = 20;
	foo(r2); // 1�� ȣ���.

	foo(static_cast<int&&>(r2)); // 3�� ȣ���.
}