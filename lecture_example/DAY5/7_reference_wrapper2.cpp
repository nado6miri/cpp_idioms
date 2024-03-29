// 7_reference_wrapper
#include <iostream>
#include <functional>

// reference_wrapper : 이동 가능한 참조
//			  참조 끼리 대입시 참조가 이동

template<typename T> class reference_wrapper
{
	T* ptr;
public:
	reference_wrapper(T& p) { ptr = &p; }

	// 변환 연산자 : 반환 타입을 표기 하지 않는 특징이 있다.
	// 객체가 다른 타입으로 변환되기 위해 필요
	operator T&() { return *ptr; }
	T& get() const { return *ptr; }
};

int main()
{
	int n1 = 10;
	int n2 = 20;
	reference_wrapper<int> r1 = n1;
	reference_wrapper<int> r2 = n2;

	int& r3 = r1; // 진짜 참조와 호환 가능해야 한다.
			// r1.operator int&() 라는 "변환 연산자" 함수가 있는지
			// 찾게 된다.



	r2 = r1; // 이 한줄의 의미를 잘생각해 보세요

	//r2.get() = 30;
	std::cout << n1 << std::endl; // 10
	std::cout << n2 << std::endl; // 20
	std::cout << r1 << std::endl; // 10
	std::cout << r2 << std::endl; // 10
}

