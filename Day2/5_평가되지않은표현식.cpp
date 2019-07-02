#include <iostream>

short foo(int n)
{
	std::cout << "foo" << std::endl;
	return 0;
}

int main()
{
	int n = 0;
	std::cout << sizeof(n) << std::endl;  // 4
	std::cout << sizeof(&foo) << std::endl; // �Լ� �������� ũ�� - 32bit �ϰ�� 4
	//std::cout << sizeof(foo) << std::endl;  // �Լ��� ũ��� �� �� ����. error
	std::cout << sizeof(foo(0)) << std::endl; // �Լ� ȣ���� return �� - 2byte

	// �Լ� ȣ�� - �򰡵Ǵ� ǥ����
	foo(0); 

	// sizeof(�Լ�ȣ���) : �Լ� ȣ���� ���(��ȯ��)�� ũ�� - ���� �Լ��� ȣ����� ����. ���ϰ��� �����
	sizeof(foo(0));
	std::cout << sizeof(foo(0)) << std::endl; // 2

	// c++ ���� �򰡵��� ���� ǥ������ 4���� �ֽ��ϴ�. -  unevaluated expression
	/*
	sizeof(foo(0));	// ��ȯ�� ũ��
	decltype(foo(0)); // ��ȯ�� Ÿ��
	noexcept(foo(0)); // �Լ��� ���ܰ� �ִ��� ����
	typeid(foo(0)); /// ��ȯ���� type ����
	*/
	
}