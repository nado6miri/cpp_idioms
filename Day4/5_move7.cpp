#include <iostream>
#include <vector>
#include <string>
#include <vector>


// sizeof()
// decltype()

// nonexcept ���þ� : �Լ��� ���ܰ� ����(����)�� �˸��� ��
// void foo() noexcept
// void foo() noexcept(true)
// void foo() noexcept(false)

// noexcept ������ : ǥ���Ŀ� ���ܰ� �ִ��� �����ϴ°�
// bool b = noexcept(foo())
// bool b = noexcept(T()) //default �����ڰ� ���ܰ� �ִ��� ������ Ȯ��
// bool b = noexcept(T(T()))



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
	std::vector<Test> v(5);
	std::cout << "------------" << std::endl;
	// vector�� size�� �ø��� move�� �Ҹ��°� ȿ�����ϰ� ������ �߰��� ���� ������ ������ �ȵ� ���� ���� �����ڰ� �Ҹ� - ���� ������ ���� ��������� �Ҹ�.
	// ���º����� �ȵ� ���� STL������ �� ���ǿ��� move�� �Ⱦ�
	// noxcept�� ���ܰ� ���ٰ� ����ϸ� move������ ȣ���.
	v.resize(7); // noexcept ���ο� ���� ���� �Ǵ� move�� ����ϱ� ������  move_if_noexept �� �̿��ؼ� �����Ǿ� ����.
	std::cout << "------------" << std::endl;

	Test t1;
	Test t2 = t1; // ������ ���� ������ ���
	Test t3 = std::move(t2); // ������ move������ ��� - ���ܰ� �־ ���, ����, ĳ�����ϻ�...static_cast<Test&&>(t2)
	Test t4 = std::move_if_noexcept(t3); // move�������� ���ܿ��� ����, ���ܰ� ������ move���, ������ ���� ������ ���

}