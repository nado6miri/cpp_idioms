#include <iostream>

void foo(int& arg) { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& arg) { std::cout << __FUNCSIG__ << std::endl; }

// �ΰ��� �Լ��� �ϳ��� �����Ϸ��� ���ø� �̿� - �׷��� �Լ��� cast ������ ������....
//void forwarding(int& n) { foo(static_cast<int&>(n)); }
//void forwarding(int&& n) { foo(static_cast<int&&>(n)); }

// ���� : perfect forwarding : ���޹��� ���ڸ� �ٸ������� ���޽� �Ϻ��� �����ϴ� ���
// 1. �Լ� ���ڸ� T&&�� �޾Ƽ�
// 2. �ٸ������� �������� std::forward(T>(arg)�� ��� ������.
template<typename T> void forwarding(T&& n)
{
	//foo(static_cast<T&&>(n));
	// ǥ�ؿ� �ִ� forward�� ���� ������ ó�� ��.
	foo(std::forward<T>(n)); //forward �ȿ��� ��ó�� casting��.
}

// 10 => T : int   T&& : int&&
// n =>  T : int&  T&& : int&

int main()
{
	int x = 10;
	forwarding(x); // x�� foo�� ������ �ʹ�.
	forwarding(10); // 10�� foo�� ������ �ʹ�.
}

