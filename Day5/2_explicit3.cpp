#include <iostream>

void foo(std::initializer_list<int> e)
{

}

int main()
{
	// initializer_list : 메모리에 연속적으로 놓인 동일 타입의 객체를 관리하는 도구
	std::initializer_list<int> s = { 1, 2, 3, 4, 5, 6, 7 }; // 연속적인 메모리로 할당하나 heap에 생성하지 않고 stack에 생성함.

	foo(s);
	foo({ 1, 2, 3, 4, 5, 6, 7 }); // ok - 이 목적으로 initializer_list을 만들었고 실질적으로는 생성자에서 만들기 위해 만들었음
	auto p = s.begin();
	std::cout << *p << std::endl;
}