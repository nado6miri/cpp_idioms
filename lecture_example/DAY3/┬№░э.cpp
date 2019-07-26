// ����
#include <iostream>

const int c1 = 10;
int const c2 = 10;

template<typename T> class Base
{
public:
	// a �� const �Դϴ�.
	//	virtual void foo(const T a)
	virtual void foo(T const a)
	{
		std::cout << "Base foo" << std::endl;
	}
};
class Derived : public Base<int*>
{
public:
	// foo �����Լ� ������ �غ�����.. override ������� ���� ������
	// 
	//virtual void foo(const int* a) override
	virtual void foo(int* const a)
	{
		std::cout << "Derived foo" << std::endl;
	}
};
int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo" ������ �غ�����
}

