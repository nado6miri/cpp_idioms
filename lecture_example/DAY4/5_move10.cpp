#include <iostream>
#include <string>
#include <vector>

// noexcept ���þ� : �Լ��� ���ܰ� ����(����)�� �˸��� ��
// void foo() noexcept
// void foo() noexcept(true)
// void foo() noexcept(false)

// noexcept ������ : ǥ������ ���ܰ� �ִ��� �����ϴ°�
// bool b = noexcept(foo())
// bool b = noexcept(T())
// bool b = noexcept(T(T()))



class Test
{
	int data;
	std::string s = "hello";
public:
	Test() {}
	~Test() {}
	Test(const Test& t) : data(t.data), s(t.s) { std::cout << __FUNCSIG__ << std::endl; }

	Test& operator=(const Test& t)
	{
		data = t.data;
		s = t.s;

		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}





	// move �� ����
	// move �迭 �Լ��� ���鶧�� ���ܰ� ������ �ʰ� �����
	// ���ܰ� ���ٰ� �� �����Ϸ����� �˷� ����!
	// noexcept : ���ܰ� ���ٴ� �ǹ�
	// noexcept(true) : ���ܰ� ����.
	// noexcept(false) : ���ܰ� ������ �ִ�.

	// sizeof(ǥ����) : ǥ���� ũ��
	// decltype(ǥ����) : ǥ���� Ÿ��
	// noexcept(ǥ����) : ǥ������ ���� ���� ����.

//	Test(Test&& t) noexcept ( 
//		noexcept( std::string(std::string())) : data(t.data), s(std::move(t.s))

	Test(Test&& t) noexcept (
		std::is_nothrow_move_constructible<std::string>::value) : data(t.data), s(std::move(t.s))
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	Test& operator=(Test&& t) noexcept (
		std::is_move_assignable<std::string>::value)
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
	Test t2 = std::move(t2); // move
		// static_cast<Test&&>(t2)

	const Test t3;
	Test t4 = std::move(t3); // copy ?
		// static_cast<const Test&&>(t2)

	// const object �� move �ɼ� �����ϴ�.
}



