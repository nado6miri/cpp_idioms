//73 page
#include <iostream>

// empty class : non static ��� ����Ÿ�� ���� class

struct AAA
{
	
};

int main()
{
	AAA aaa;
	std::cout << sizeof(aaa) << std::endl;  // empty class �� ũ��� 1�� ���ǵǾ� ����. 4����Ʈ
}
