#include <iostream>
#include <functional>

// 그럼 std::reference_wrapper 를 사용하지 말고 직접 만들어 보자. - 포인터로 만들면 됨. 결국 참조가 포인터임.
template<typename T> class reference_wrapper
{
	T* ptr;
public:
	reference_wrapper(T& p) { ptr = &p;  }

	// 변환 연산자 : 반환타입을 표기하지 않는 특징이 있다.
	// 객체가 다른 타입으로 변환되기 위해 필요함.
	operator T&() { return *ptr; }
	T& get() const { return *ptr; }
};


int main()
{
	int n1 = 10;
	int n2 = 20;
	/*
	std::reference_wrapper<int> r1 = n1;
	std::reference_wrapper<int> r2 = n2;
	*/
	reference_wrapper<int> r1 = n1;
	reference_wrapper<int> r2 = n2;

	// 진짜 참조와 호환 가능해야 한다.
	// 컴파일러가 r1.operator int&()라는 변환 연산자가 있는지 찾게 된다. - 위에 추가해 보자.
	int& r3 = r1; 


	// c++의 참조는 const임. 따라서 참조가 이동하지 않고 값이 이동함.
	// 하지만 reference_wrapper 를 사용하면 reference가 다른곳 즉 r2는 n2를 가리키지 않고 n1 을 가리킨다. 즉 이동 가능한 참조 !!!
	r2 = r1; //  이 한줄의 의미를 생각해 보세요.

	std::cout << n1 << std::endl; // 10
	std::cout << n2 << std::endl; // 20
	std::cout << r1 << std::endl; // 10
	std::cout << r2 << std::endl; // 10

	r2.get() = 30;
	std::cout << n1 << std::endl; // ?
	std::cout << r2 << std::endl; // ?
}