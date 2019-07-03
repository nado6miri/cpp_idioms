#include <iostream>

struct Test
{
	int data;
	void foo() & { std::cout << __FUNCSIG__ << std::endl;  }
	void foo() && { std::cout << __FUNCSIG__ << std::endl; }
};

int main()
{
	Test t; // �̸��� �ֽ��ϴ�. ���� ��������� ����, �̸��� ���ؼ� ������ ���ٰ���, lvalue
	t.data = 10;
	t.foo(); // �̸��� ������ ȣ���� �ϸ� foo() & �Լ��� ȣ���.

	Test(); // �̸��� �����ϴ�. ���� ���忡���� ��� ����. rvalue, ;(���� ������) ������ �Ҹ��.
	//Test().data = 10; // error , �ӽð�ü�� �̸��� ����. lvalue�� �ü� ����. rvalue ��.
	Test().foo(); // rvalue�� �ӽð�ü�� ������ �Լ��� ȣ�� �ϸ� foo() && �Լ��� ȣ���.

	Test&& r = Test(); // �ӽð�ü�� ref�� �����ϸ� ������ ����ȴ�. {}�� �Ѿ�� ���� ��.
	r.foo();
}