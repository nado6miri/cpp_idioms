#include <iostream>

// const를 맨 앞에 붙이지 말도 뒤에 붙이면 가독성도 좋아지고 오류도 방지할 수 있다.
// (const int c1 = 10)  == (int const c1 = 10)
// (const int* a) != (int* const a) 

template<typename T> class Base
{
public:
	// a는 const 입니다.
	virtual void foo(const T a)
	{
		std::cout << "Base foo" << std::endl;
	}
};

class Derived : public Base<int*>
{
public:
	// foo 가상함수 정의해 보세요... override사용하지 말아 주세요. (override 사용 생활화 필요)
	//virtual void foo(const int* a) // --error
	virtual void foo(int* const a) // ok
	{
		std::cout << "Derived foo" << std::endl;
	}
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derieved foo" 나오게 해보세요.
}