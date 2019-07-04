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


// �߿��� �̾߱�
class Object
{
	Test data;
public:
	Object() {}
	//void setData(Test d) { data = d; } --> copy���ٴ� ������ ���� �Ʒ�ó��...

	// setter ����� 1.  const & - data = d;�� �׻� ���� ����
	//void setData(const Test& d) { data = d; }
	//void setData(const Test& d) { data = std::move(d); } // �տ� const�� �پ� �ֱ� ������ move�� �ϴ��� �׻� ���簡 ��. const�� move�� �� ����.

	// setter 2.  2���� ������.. const & �� && ���� 2�� ������... 
	//void setData(const Test& d) { data = d;  }  // const/lvalue ó��
	//void setData(Test&& d) { data = std::move(d); } // rvalueó��...

	// setter 3. call by value�� ���� ���ܱ�? - move �� �����ٰ� �����ϸ� call by  value �ϳ��� ���� ��...setter3 ���ǿ��� �������, move���� ��� �̷�� ������ Ȯ��
	//void setData(Test d) { data = std::move(d); }

	//setter 4. forwarding reference T&& �� lvalue������ lvalue, rvalue ������ rvalue
	template<typename T> void setData(T&& d)
	{
		//data = d; // 1 ������ ����
		//data = std::move(d); // 2 ������ move
		data = std::forward<T>(d); //3 �Ѵ� ������. lvalue ������ ����, rvalue ������ �̵�
	}
	// ����� 2���� ����� ���� ���� ����.
};

int main()
{
	Object obj;
	Test data;
	obj.setData(data); // data�� ��� �� �ǵ� - ���� ���� 1ȸ �߻�, setter3 ������ ������� 1ȸ, move���� 1ȸ
	obj.setData(std::move(data)); // move�� �߱� ������ ��� �Ⱦ� �ǵ�. // move ���� 1ȸ, setter3 ������ move ���� 1ȸ, move���� 1ȸ
}