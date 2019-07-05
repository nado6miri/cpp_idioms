#include <iostream>
#include <functional>

using namespace std::placeholders;

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	void(*f1)(int); // ���ڰ� 1���� �Լ� �ּҸ� ���� �� �ִ�.

	// c++11 ���� �߰��� �Լ� �������� ������ ���ø�
	// �ַ� bind�� ���� ����Ѵ�.
	std::function<void(int)> f; //parameter�� int 1���̰� void type�� function ptr ���� �� �ִ� f ����

	//f = &foo; // foo �Լ��� param�� 4���� ���� �� ����
	f = std::bind(&foo, _1, 0, 0, 0);
	f(10); // 10, 0, 0, 0

}