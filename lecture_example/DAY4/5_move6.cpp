#include <iostream>
#include <string>

class Test
{
	int data;
	std::string s = "hello";
public:
	Test() {} 
	~Test() {}
	Test(const Test& t) : data(t.data), s(t.s)   { std::cout << __FUNCSIG__ << std::endl; }

	Test& operator=(const Test& t) 
	{
		data = t.data;
		s = t.s;

		std::cout << __FUNCSIG__ << std::endl; 
		return *this; 
	}





	// move �����ڿ����� ��� ����� �ݵ�� move�� �ű���!
	Test(Test&& t) : data(t.data), s(std::move(t.s))
	{ std::cout << __FUNCSIG__ << std::endl; }


	Test& operator=(Test&& t)
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
	Test t2 = t1;
	t2 = t1;

	Test t3 = std::move(t1); 
	t3 = std::move(t1);
}



