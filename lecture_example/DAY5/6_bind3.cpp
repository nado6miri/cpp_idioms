// 6_bind
#include <iostream>
#include <functional>
using namespace std::placeholders;

void foo(int a, int& b) { b = 100; }
int main()
{
	std::function<void(int)> f;

	int n = 0;
//	f = std::bind(&foo, _1, n); // n�� �ƴ϶� n�� ���� ����(����)

	f = std::bind(&foo, _1, std::ref(n)); // ������ �����ش޶�
	f(10); // foo(10,n)

	std::cout << n << std::endl; // �� ���ñ�� ? 0 ? 100
}




