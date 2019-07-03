#include <iostream>

// const�� �� �տ� ������ ���� �ڿ� ���̸� �������� �������� ������ ������ �� �ִ�.
// (const int c1 = 10)  == (int const c1 = 10)
// (const int* a) != (int* const a) 

template<typename T> class Base
{
public:
	// a�� const �Դϴ�.
	virtual void foo(const T a)
	{
		std::cout << "Base foo" << std::endl;
	}
};

class Derived : public Base<int*>
{
public:
	// foo �����Լ� ������ ������... override������� ���� �ּ���. (override ��� ��Ȱȭ �ʿ�)
	//virtual void foo(const int* a) // --error
	virtual void foo(int* const a) // ok
	{
		std::cout << "Derived foo" << std::endl;
	}
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derieved foo" ������ �غ�����.
}