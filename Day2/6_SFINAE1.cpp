// 6_SFINAE1

#include <iostream>

//void foo(int n) { std::cout << "int" << std::endl; }
//void foo(float n) { std::cout << "float" << std::endl; }
//void foo(double n) { std::cout << "double" << std::endl; }
void foo(...) { std::cout << "..." << std::endl; }

//template<typename T> void foo(T n) { std::cout << "T" << std::endl; }


int main()
{
	float f = 3.4f;

	// overloading resolution
	foo(f); // 1. float �Լ� ȣ�� - exactly matching - float
	// �� foo(float)�� �ּ� ó���ϸ� � �Լ��� ȣ��ɱ� - template�� �����ȴ�.
	// �ٽ� template �Լ��� �ּ�ó���ϸ� � �Լ��� ȣ��ɱ� - double �Լ��� ȣ���. data �ս��� ���� �������� �� - promotion
	// �ٽ� double�� �ּ�ó���ϸ� � �Լ��� ȣ��ɱ�? - int �Լ��� ȣ��� - standard conversion(ǥ�� Ÿ�Գ��� ��ȯ��)
	// int �Լ��� �ּ�ó�� �ϸ� � �Լ��� ȣ��ɱ�? - �������� �Լ��� �� �������� ȣ��ȴ�.
}