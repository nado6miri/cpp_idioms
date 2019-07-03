#include <iostream>
/*
// lvalue�� rvalue�� ��� ���޹޴� �Լ� �����
// 1. call by value
void f1(int a) {}

// 2. lvalue �� ���� �� ������ rvalue�� ���� ����. ���� f1(int& a) ==> f1(const int& a) ----> const lvalue reference  ���
void f1(int& a) {}

// 3. 2���� �Լ� - 2��ó�� const�� ����ϰ� ���� ������
void f1(int& a) {} //lvalue �޴� �Լ�
void f1(int&& a) {} // rvalue �޴� �Լ�
*/
// 4. 2���� �Լ��� �ڵ����� - template �̿���. - 4���� ���� ���� �����.
// T&& : forwarding reference (universal reference��� �մϴ�.) - T(type) �ȿ� & && ���� ���� ���� --> reference collapse �˾ƾ� ��.
// int&& : rvalue reference
template<typename T> void f1(T&& a) 
{
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 0;
	f1(n);  // T : int&   f1(int&)
	f1(10); // T : int   f1(int&&)
}