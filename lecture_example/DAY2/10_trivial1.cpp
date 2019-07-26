// 10_trivial1
#include <iostream>

// trivial : 생성자, 복사 생성자, 소멸자,대입연산자 등이 하는일이 없는경우
//           "trivial 하다" 라고 합니다.

// 1. 가상함수가 없고
// 2. 객체형 멤버가 없거나 멤버의 생성자가 trivial 하고
// 3. 기반 클래스가 없거나 기반클래스의 생성자가 trivial 하고
// 4. 사용자가 만든 생성자가 없을때

// "생성자는 trivial" 합니다.


class A {};

class B : public A
{
	int a;
	//A a;
public:
	//virtual void foo() { std::cout << "foo" << std::endl; }
};


int main()
{
	// B는 생성자가 trivial 할까요 ?
	// B의 생성자가 trivial 하면 생성자 호출을 하지 않아도
	// 사용가능해야 합니다
	B* p = static_cast<B*>(operator new(sizeof(B)));

	new(p) B;

	p->foo(); // ???
}


