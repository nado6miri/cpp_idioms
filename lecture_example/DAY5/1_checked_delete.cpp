// 1_checked_delete    37page
#include <iostream>

class Test;  // Ŭ���� ���� ����
			 // ������ ������ ��� ������ ������ ����� �ִ�
			 // �ҿ����� Ÿ��(incomplete type)

// check �Ŀ� delete
void foo(Test* p)
{
	//sizeof(Test); // complete Ÿ�Ը� ũ�⸦ ���Ҽ� �ִ�.
	
	// �ȵ���̵� �ҽ��� ���� �������� ���� �־��� �ڵ�
	//enum { type_must_be_complete = sizeof(Test)};

	// C++11 ���Ŀ��� static assert ���
	static_assert(sizeof(Test) > 0,
					"error, delete incomplete type");

	delete p;
}

class Test
{
public:
	Test()  { std::cout << "Test()" << std::endl; }
	~Test() { std::cout << "~Test()" << std::endl; }
};

int main()
{
	std::default_delete<int> df;

	Test* p = new Test;
	foo(p);
}
