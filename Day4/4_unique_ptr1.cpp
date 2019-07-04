
#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Car go" << std::endl; }
	~Car() { std::cout << "~Car"  << std::endl; }
};


// smart pointer를 만들어 봅시다.
// 핵심 : -> 와 *를 재 정의해서 포인터 처럼 보이게 하는 것.
// 장점 : raw pointer가 아니라 객체이므로 소멸자등을 활용해서 자동 삭제 기능을 넣을 수 있다.

class unique_ptr
{
	Car* obj;
public:
	unique_ptr(Car* p = 0) : obj(p) {}
	~unique_ptr() { delete obj;  }

	Car* operator->() { return obj; }
	Car& operator*() { return *obj; }
};

int main()
{
	unique_ptr p1(new Car);
	p1->Go(); // (p1.operator->())Go()  ---> c++은 이렇게 변환함. (p1.operator->())->Go()

	(*p1).Go(); // p1.operator*
}