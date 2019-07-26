// 4_unique_ptr
#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Car Go" << std::endl; }
	~Car()    { std::cout << "~Car"   << std::endl; }
};
// 스마트포인터를 만들어 봅시다.
// 핵심 : -> 와 * 를 재정의해서 포인터 처럼 보이게 하는 것.
// 장점 : raw pointer 가 아니라 객체이므로 소멸자등을 활용해서
//		 자동삭제 기능을 넣을수 있다.

class unique_ptr
{
	Car* obj;
public:
	unique_ptr(Car* p = 0) : obj(p) {}
	~unique_ptr() { delete obj; }
	Car* operator->() { return obj; }
	Car& operator*()  { return *obj; }
};

int main()
{
	unique_ptr p1(new Car);
	p1->Go(); // (p1.operator->())Go()
			  // (p1.operator->())->Go()
	(*p1).Go(); // p1.operator*
}

