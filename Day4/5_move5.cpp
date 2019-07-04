#include <iostream>
#include <vector>
#include <string>

// class�� �ڿ��� �Ҵ����� ������ �Ҹ��ڰ� ��� �ȴ�.
// c++98
// Ŭ������ �ڿ��� �Ҵ��ϸ� rule of 3 ��Ģ�� ����� �Ѵ�. (� ����� ������ ����)
// �Ҹ���  /  ���� ������ / ���Կ�����

// c++11
// "move ������, move ���� ������ - rule of 3 + rule of 2 = rule of 5

// move �迭�Լ��� �������� ������ ���� �迭 �Լ��� ȣ��ǰ� �ȴ�.
class Test
{
	int data;
	int* resource;
public:
	Test() {} // resource = new int;
	~Test() { std::cout << __FUNCSIG__ << std::endl; } // �Ҹ���
	Test(const Test& t) { std::cout << __FUNCSIG__ << std::endl; } // ���������
	Test& operator=(const Test& t) { std::cout << __FUNCSIG__ << std::endl; return *this;  } // ���� ������

	Test(Test&& t) { std::cout << __FUNCSIG__ << std::endl; } // move ������
	Test& operator=(const Test&& t) { std::cout << __FUNCSIG__ << std::endl; return *this; } // move ���� ������
};

int main()
{
	Test t1;
	Test t2 = t1; // ����
	t2 = t1; // ����

	Test t3 = std::move(t1); // move����
	t3 = std::move(t1); // move ���Կ���
}