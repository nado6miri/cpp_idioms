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


// move�� �˰���
// move���� �˾ƾ� �ϴ� ��
// 1. Ŭ������ ���鶧 move�迭 �Լ� 2���� ����� ���
// 2. �Ϲ� �˰����� �����Ҷ� move()�� ����ؼ� �ű�� ���� ���� ������찡 �ִ�.
template<typename T> void Swap(T& a, T& b)
{
	/*
	//swap�� ���� ���縦 3�� �ϴ� ������ �Ǿ� �־ ȿ�������� swap�� �ؾ� ��.
	T tmp = a;
	a = b;
	b = tmp;
	*/

	// ȿ�������� swap�ϴ� ���
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	Test t1, t2;
	Swap(t1, t2);
}