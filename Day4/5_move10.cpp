#include <iostream>
#include <vector>
#include <string>
#include <vector>


class Test
{
	int data;
	std::string s = "hello";
public:
	Test() {} // resource = new int;
	~Test() { std::cout << __FUNCSIG__ << std::endl; } // �Ҹ���

	Test(const Test& t) : data(t.data), s(t.s) { std::cout << __FUNCSIG__ << std::endl; } // ���������

	// ���� ������
	Test& operator=(const Test& t)
	{
		data = t.data;
		s = t.s;
		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}

	// move ������ -move �����ڿ����� ��� ����� �ݵ�� move�� �ű���
	// move ����
	// move �迭 �Լ��� ���鶧�� ���ܰ� ������ �ʰ� �����, ���ܰ� ���ٰ� �� �����Ϸ����� �˷�����. (noexcept)
	// noexcept : ���ܰ� ���ٴ� �ǹ�
	// noexcept(true) : ���ܰ� ����.
	// noexcept(false) : ���ܰ� ���� �� �ִ�.

	//Test(Test&& t) noexcept(std::string(std::string())) : data(t.data), s(std::move(t.s))
	Test(Test&& t) noexcept(std::is_nothrow_move_constructible<std::string>::value) : data(t.data), s(std::move(t.s))
		//Test(Test&& t) : data(t.data), s(std::move(t.s))
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	// move ���� ������
	Test& operator=(const Test&& t) noexcept(std::is_nothrow_move_assignable<std::string>::value)
		//Test& operator=(const Test&& t)
	{
		data = t.data;
		s = std::move(t.s);
		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}
};


int main()
{
	Test t1;
	Test t2 = std::move(t2); //move - static_cast<Test&&>(t2) �� casting��

	// move ȣ�� ? copy ȣ�� ? -  copyȣ��... ������ const �� �ڿ� �̵� �Ұ� ���� 
	const Test t3;
	Test t4 = std::move(t3);  // static_cast<const Test&&>(t2) �� casting�� ���� noexcept ������ copy �� ���� ��
}