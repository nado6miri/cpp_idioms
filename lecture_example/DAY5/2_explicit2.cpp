#include <iostream>
#include <string>
#include <vector>
#include <memory>
void foo(std::string s) {}

int main()
{
	// string 은 explicit 생성자가 아닙니다.
	std::string s1("hello");
	std::string s2 = "hello"; // ok.
	//foo("hello"); // explicit 생성자 라면 error
 
	// vector의 생성자는 explicit 입니다
	std::vector<int> v1(10);  // 10개짜리 vector
	std::vector<int> v2 = 10;  // error
	std::vector<int> v3{ 10 }; // 1개를 10으로 초기화
	std::vector<int> v4 = { 10 }; // ok. explicit 아님.

	// C++ 표준 스마트포인터는 모두 explicit
	std::unique_ptr<int> p1(new int);
	std::unique_ptr<int> p2 = new int; // error
}



