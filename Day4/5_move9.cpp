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


// 1. ����ڰ� ����� move�� ��� �������� ������ ==> �����Ϸ��� ��� ������ �ش�.
// 2. ����ڰ� ����迭 �Լ��� �����ϸ� �����Ϸ��� move�迭�� �������� �ʴ´�.
// ��� : ���� �����ڸ� ������ ���ƶ�... ������ ���� �Ҵ� char *�� �ϰ� �Ǹ� ���� �����ڸ� ������ ��. ���� string �� ����ض�..
// ����  class �ȿ��� raw pointer�� ������� ����. .�׷��� ���� �����ڸ� ���� �ʿ䰡 ����...
// rule of zefo :  ����ڰ� ���� �ڿ��� �������� ������ �Ҹ���, ����迭 2��, Move �迭 2���� ���� �ʿ� ����. �����Ϸ��� ��� ����.
class Object
{
	Test data;
	// char *s;
	std::string s;
public:
	Object() {}; // 
	Object(const Object& o) : data(o.data) {} // ����ڰ� ���� �����ڸ� �������. �����Ϸ� ���忡����  ��move�����ڸ� ���� �� ����. �� ��� �Ѵ� ���簡 ��.
};

int main()
{
	Object o1;
	Object o2 = o1;
	Object o3 = std::move(o2);
}