#include <iostream>

void foo(int& arg) { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& arg) { std::cout << __FUNCSIG__ << std::endl; }

void forwarding(int& n) { foo(n); }
//void forwarding(int&& n) { foo(n); }
void forwarding(int&& n) 
{
	// main ���� 10(rvalue)�� ���´µ� int&& n = 10���� �����鼭 lvalue �� �Ǿ���. �� value�� Ư���� ����Ǿ���.
	// ������� (rvalue��) ĳ�����ؼ� ���� �ʿ���.
	foo(static_cast<int&&>(n)); 
}

int main()
{
	int x = 10;
	forwarding(x); // x�� foo�� ������ �ʹ�.
	forwarding(10); // 10�� foo�� ������ �ʹ�.

	// 10 : rvalue,  n : lvalue  ���� forwarding(10)�� ȣ���ϸ�  foo() �Լ��� �ι�° �Լ��� ȣ��� �� ������ ù��° �Լ��� ȣ��ȴ�.
	// ���� cast_static<int&&>�� casting �ϸ� �ι�° foo() �Լ��� ȣ��ȴ�.
	int&& n = 10; 
}

