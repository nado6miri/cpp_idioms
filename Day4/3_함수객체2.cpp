#include <iostream>

int Add(int a, int b) { return a + b; }


// �Լ���ü : () �����ڸ� ������ �ؼ� �Լ�ó�� ��� ������ ��
// �Լ���ü ���� 1. ���¸� ������ �Լ�
// �Ϲ��Լ��� ���۸� �ְ� ���¸� ���� �� ����.
// �Լ� ��ü�� Ŭ����(����ü)�̹Ƿ� ��� �����Ϳ� ��� �Լ� Ȱ�� ������.

struct Plus
{
	int base;
	Plus(int a = 0) : base(a) {}
	int operator() (int a, int b) { return a + b + base; }
};

int main()
{
	Plus p(100);
	int n1 = Add(1, 2); // ok
	int n2 = p(1, 2); // p.operator()(1,2)�� �ǹ�
	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
}