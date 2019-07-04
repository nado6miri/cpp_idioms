#include <iostream>

int Add(int a, int b) { return a + b; }


// �Լ���ü : () �����ڸ� ������ �ؼ� �Լ�ó�� ��� ������ ��

struct Plus
{
	int operator() (int a, int b) { return a + b; }
};

int main()
{
	Plus p;
	int n1 = Add(1, 2); // ok
	int n2 = p(1, 2); // p.operator()(1,2)�� �ǹ�

	// a + b ; // a.operator+(b) �ǹ�
	// a();    // a.operator()() �ǹ�
	// a(1, 2); // a.operator()(1,2) �ǹ�
}