// 1_checked_delete  37page
#include <iostream>

class Test; // class ���漱�� - ������ ������ ������ ������ ������ ���� �� �ִ�. �ҿ����� Ÿ��(incomplete type)

// check �Ŀ� delete����.
void foo(Test* p)
{
	//sizeof(Test); // complete Ÿ�Ը� ũ�⸦ ���� �� �ִ�.
	// �ȵ���̵� �ҽ��� ���� �������� ���� �ִ� �ڵ�
	//enum { type_must_be_complete = sizeof(Test) };

	//c++11���� static assert ���
	static_assert(sizeof(Test) > 0, "error, delete incomplete type type");
	delete p;
};

class Test
{
public:
	Test() { std::cout << __FUNCSIG__ << std::endl; };
	~Test() { std::cout << __FUNCSIG__ << std::endl; };
};


int main()
{
	std::default_delete<int> df;
	Test*p = new Test;
	foo(p);
}