#include <iostream>

struct Test
{	
	int data;

	void foo() &  { std::cout << __FUNCSIG__ << std::endl; }
	void foo() && { std::cout << __FUNCSIG__ << std::endl; }
};

int main()
{
	Test t; // �̸��� �ֽ��ϴ�. ���� ����� ���� ����
			// �̸��� ���ؼ� ������ ���� ����. lvalue
	t.data = 10;

	t.foo(); // foo() &

	Test&& r = Test(); // �̸��� �����ϴ�. ���Ϲ��忡���� ���. rvalue
			// �ӽð�ü
	//Test().data = 10;// error. �ӽð�ü�� rvalue

	Test().foo(); // foo() &&
}


