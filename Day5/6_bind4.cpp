#include <iostream>
#include <functional>

// button �� ���� ó���ϴ� handler�� �����ϸ� ��ư�� ��û ������.. ȿ���� ó������ bind
using namespace std::placeholders;

class Button
{
public:
	//void(*handler) ();
	std::function<void ()> handler;
	void Click() { handler(); }
};

void foo() { std::cout << "foo" << std::endl; }
void goo() { std::cout << "goo" << std::endl; }
void hoo(int id) { std::cout << "hoo" << id << std::endl; }


int main()
{
	Button b1, b2;
	/*
	nana C++ GUI Library
	Form rm;
	b1.handler = [&rm]() { rm.Close(); };
	*/
	//b1.handler = &foo;
	//b2.handler = &goo;

	b1.handler = std::bind(&hoo, 1);
	b2.handler = std::bind(&hoo, 2);
	b1.Click();

	b1.handler = []() { std::cout << "Dialog Close" << std::endl; };
	b1.Click();
}