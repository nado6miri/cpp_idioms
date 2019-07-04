#include <iostream>
#include <vector>
#include <string>

class Test
{
	int data;
	std::string s = "hello";
public:
	Test() {} // resource = new int;
	~Test() { std::cout << __FUNCSIG__ << std::endl; } // 소멸자

	Test(const Test& t) : data(t.data), s(t.s) { std::cout << __FUNCSIG__ << std::endl; } // 복사생성자

	// 대입 연산자
	Test& operator=(const Test& t) 
	{ 
		data = t.data;
		s = t.s;
		std::cout << __FUNCSIG__ << std::endl; 
		return *this; 
	} 

	// move 생성자 -move 생성자에서는 모든 멤버를 반드시 move로 옮기자
	Test(Test&& t) : data(t.data), s(std::move(t.s))
	{ std::cout << __FUNCSIG__ << std::endl; } 

	// move 대입 연산자
	Test& operator=(const Test&& t) 
	{ 
		data = t.data;
		s = std::move(t.s);
		std::cout << __FUNCSIG__ << std::endl; 
		return *this; 
	} 
};

int main()
{
	Test t1;
	Test t2 = t1; // 복사
	t2 = t1; // 대입

	Test t3 = std::move(t1); // move연산
	t3 = std::move(t1); // move 대입연산
}