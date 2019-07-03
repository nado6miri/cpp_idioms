#include <iostream>

int main()
{
	int n = 0;
	n = 10; // lvalue : ��ȣ�� ���ʿ� �ü� �ִ� ǥ����, rvalue : ��ȣ�� ���ʿ� �� �� ���� ǥ���� (���� ������ �ƴ�, ǥ���� �������� ������)
	n + 1 = 10; // n+1 : rvalue
	(n = 10) = 20; // n = 10 : lvalue
	// foo(); // void expression

	// ��Ģ 1. lvalue reference &�� lvalue�� ����ų �� �ִ�.
	int& r1 = n;  // ok
	//int& r2 = 10; // error

	// ��Ģ 2 : const lvalue reference &(����)�� lvalue��  rvalue��� ����Ų��.
	const int& r3 = n;  // ok;
	const int& r4 = 10; // ok; ����ų �� ������ ����� �߰���.

	// Point() �ӽð�ü�� rvalue
	// ���� 3 : &&�� c++11�� rvalue reference�� rvalue�� ����ų �� �ִ�.
	int&& r5 = n; // error
	int&& r6 = 10; // ok

}