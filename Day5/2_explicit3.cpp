#include <iostream>

void foo(std::initializer_list<int> e)
{

}

int main()
{
	// initializer_list : �޸𸮿� ���������� ���� ���� Ÿ���� ��ü�� �����ϴ� ����
	std::initializer_list<int> s = { 1, 2, 3, 4, 5, 6, 7 }; // �������� �޸𸮷� �Ҵ��ϳ� heap�� �������� �ʰ� stack�� ������.

	foo(s);
	foo({ 1, 2, 3, 4, 5, 6, 7 }); // ok - �� �������� initializer_list�� ������� ���������δ� �����ڿ��� ����� ���� �������
	auto p = s.begin();
	std::cout << *p << std::endl;
}