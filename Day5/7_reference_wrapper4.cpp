#include <iostream>
#include <functional>
#include <thread>

void foo(int a, int&b) { b = 100; }

int main()
{
	int n = 0;

	// thread�� �����ڿ��� ������ ����, �� �̼��� �����尡 �����˴ϴ�.
	//std::thread t(&foo, 1, n);  // 1, n �� foo  �Լ��� ������. n�� ������ �Ѿ���̳�? ������ �Ѿ ���̳�? bind�� �����ϰ� ������ �Ѿ. - �������
	std::thread t(&foo, 1, std::ref(n));  // 1, n �� foo  �Լ��� ������. n�� ������ �Ѱܶ�!! - bind�� ������. ��¿�� ���� ���� �Ѱܾ� �ϴµ� ������ ó���ؾ� �� ��� ref�� �����.

	t.join();
	std::cout << n << std::endl; // ??
}