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

// �߿��� �̾߱�
class Object
{
	Test data;
public:
	Object() {}
	//void setData(Test d) { data = d; }

	// setter ����� 1. const &  -�׻� ���� ���
	// void setData(const Test& d) { data = d; }
	// �Ʒ� �ڵ�� ���� �׻� ����(const �� move �ɼ� ����.)
	// void setData(const Test& d) { data = std::move(d); }

	// setter 2. 2���� ������
	// const & ������ && �������� 2�� ������
	//void setData(const Test& d)  { data = d; }
	//void setData(Test&& d) { data = std::move(d); }

	// setter 3. call by value �� ���� ���ܱ� ?
	// void  setData(Test d) { data = std::move(d); }

	// setter 4. forwarding reference
	template<typename T> void setData(T&& d)
	{
	//	data = d; // 1   ������ ����
	//	data = std::move(d); // 2 ������ move
		data = std::forward<T>(d); // 3
	}
};

int main()
{
	Object obj;

	Test data;


	obj.setData(data);			// ���� ���� 1ȸ
								// ���� ���� 1ȸ, move ���� 1ȸ
	obj.setData(std::move(data));// move ���� 1ȸ
								 // move ���� 1ȸ, move���� 1ȸ
}






