// 10_trivial1

#include <iostream>

// trivial : 생성자, 복사 생성자, 소멸자등이 하는일이 없는경우 trivial하다 라고 합니다.
// 1. 가상함수가 없고
// 2. 객체형 멤버가 없거나 멤버의 생성자가 trivial하고
// 3. 기반 클래스가 없거나 기반 클래스의 생성자가 trivial하고
// 4. 사용자가 만든 생성자가 없을때
// 생성자는 trivial하다 라고 합니다.

class A {};

class B : public A
{
	//A a;
public:
	virtual void foo() { std::cout << "foo" << std::endl; }
};

int main()
{
	// B는 생성자가 trivial 할까요?
	// B의 생성자가 trivial하면 생성자 호출을 하지 않아도 사용가능 해야 합니다.
	B* p = static_cast<B*>(operator new(sizeof(B)));
	new(p) B;  // 생성자 호출을 하지 않으면 죽는다. 따라서 trivial하지 않다. 생성자는 가상함수를 초기화 해 주는 역할을 함.
	p->foo();
}