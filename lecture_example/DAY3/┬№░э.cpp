// 참고
#include <iostream>

const int c1 = 10;
int const c2 = 10;

template<typename T> class Base
{
public:
	// a 는 const 입니다.
	//	virtual void foo(const T a)
	virtual void foo(T const a)
	{
		std::cout << "Base foo" << std::endl;
	}
};
class Derived : public Base<int*>
{
public:
	// foo 가상함수 재정의 해보세요.. override 사용하지 말아 보세요
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
	p->foo(0); // "Derived foo" 나오게 해보세요
}

