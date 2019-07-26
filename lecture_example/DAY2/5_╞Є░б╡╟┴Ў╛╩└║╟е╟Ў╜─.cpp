// 5_�򰡵�������ǥ����
#include <iostream>

short foo(int n)
{
	std::cout << "foo" << std::endl;
	return 0;
}
int main()
{
	int n = 0;
	std::cout << sizeof(n)      << std::endl; // 4
	std::cout << sizeof(&foo)   << std::endl; // 4
	//std::cout << sizeof(foo)    << std::endl; // error.
	
	// sizeof(�Լ�ȣ���) : �Լ� ȣ���� ���(��ȯ��)�� ũ��
	
	foo(0); // �Լ� ȣ��. �򰡵Ǵ� ǥ����
	sizeof(foo(0)); // �Լ� ȣ���� �Ǵ°��� �ƴ�. 
					//	�򰡵��� ���� ǥ����
	std::cout << sizeof( foo(0) ) << std::endl; // 2

	// C++���� �򰡵��� ���� ǥ������ 4���� �ֽ��ϴ�.
	// unevaluated expression

//	sizeof(foo(0));   // ��ȯ�� ũ��
//	decltype(foo(0)); // ��ȯ�� Ÿ��
//	noexcept(foo(0)); // �Լ��� ���ܰ� �ִ��� ����
//	typeid(foo(0));   // ��ȯ���� Ÿ�� ����
}




