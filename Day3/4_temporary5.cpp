#include <iostream>

struct Base
{
	int value = 10;
};

struct Derived : public Base
{
	int value = 20;
};

int main()
{
	Derived d;
	std::cout << d.value << std::endl; // 20 - �ڽ��� ���� �켱��. 

	// Base�� �ӽð�ü�� ���� value�� �Ѱ� ��.
	std::cout << static_cast<Base>(d).value << std::endl; // 10 - Base �� �� ��ȸ�� 
	// Base�� ������ ���� value�� �Ѱ� ��.
	std::cout << static_cast<Base&>(d).value << std::endl; // 10 - Base �� �� ��ȸ�� 

	// Base�� �ӽð�ü�� ���� value ���� ���� - error �ӽð�ü�̱� rvalue��..  ������...���� �Ұ�
	//static_cast<Base>(d).value = 50;
	// Base�� ������ ���� value�� ���� ���� ok 
	static_cast<Base&>(d).value = 50;
}