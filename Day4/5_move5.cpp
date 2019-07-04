#include <iostream>
#include <vector>
#include <string>

// class가 자원을 할당하지 않으면 소멸자가 없어도 된다.
// c++98
// 클래스가 자원을 할당하면 rule of 3 법칙을 따라야 한다. (어떤 사람은 생성자 포함)
// 소멸자  /  복사 생성자 / 대입연산자

// c++11
// "move 생성자, move 대입 연산자 - rule of 3 + rule of 2 = rule of 5

// move 계열함수를 제공하지 않으면 복사 계열 함수가 호출되게 된다.
class Test
{
	int data;
	int* resource;
public:
	Test() {} // resource = new int;
	~Test() { std::cout << __FUNCSIG__ << std::endl; } // 소멸자
	Test(const Test& t) { std::cout << __FUNCSIG__ << std::endl; } // 복사생성자
	Test& operator=(const Test& t) { std::cout << __FUNCSIG__ << std::endl; return *this;  } // 대입 생성자

	Test(Test&& t) { std::cout << __FUNCSIG__ << std::endl; } // move 생성자
	Test& operator=(const Test&& t) { std::cout << __FUNCSIG__ << std::endl; return *this; } // move 대입 연산자
};

int main()
{
	Test t1;
	Test t2 = t1; // 복사
	t2 = t1; // 대입

	Test t3 = std::move(t1); // move연산
	t3 = std::move(t1); // move 대입연산
}