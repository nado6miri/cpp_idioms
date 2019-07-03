#include <iostream>

// �Լ����ڷ� 
// int& : int�� lvalue�� ���ް���
// int&& : int�� rvalue�� ���ް���
// T& : ��� Ÿ���� lvalue�� ���� ������.
// T&& : ��� Ÿ���� lvalue�� rvalue ���� ������.

// lvalue(n)�� ������  T : int&  �Լ�(int&)
// rvalue(0)�� ������  T : int   �Լ�(int&&)

void f1(int& a) {}
void f2(int& a) {}

template<typename T> void f3(T& a) { }
//f3<int>(n); //ȣ��� reference callapsing�� ���� & �� -  lvalue
//f3<int&>(n); //ȣ��� reference callapsing�� ���� & �� -  lvalue
//f3<int&&>(n); //ȣ��� reference callapsing�� ���� & �� -  lvalue

template<typename T> void f4(T&& a) { }

int main()
{
	int n = 0;
	// ����ڰ� type�� ���� �����ϸ� � �Լ��� �������� ������ ���ô�.
	f4<int>(0); // T : int       T&& : int&&     f4(int&&) -> rvalue
	f4<int&>(n); // T : int&    T&& : int& &&   f4(int&) -> lvalue
	f4<int&&>(0); // T : int&&   T&& : int&& &&   f4(int&&) -> rvalue

	// ����ڰ� type�� �������� ������ �����Ϸ��� Ÿ���� �����ؾ� �Ѵ�. ��� ������ �� ������ ������.
	f4(n);  // �����Ϸ��� lvalue�� �޵��� T�� �����Ѵ�. T : int&�� �����ϰ� �����Լ��� f4(int&)�� �����Ѵ�.
	f4(0);	// �����Ϸ��� rvalue�� �޵��� T�� �����Ѵ�. T : int�� �����ϰ�, �����Լ��� f2(int&&)�� ������.
}