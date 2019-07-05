#include <iostream>
#include <string>
#include <vector>
#include <memory>

int main()
{
	std::string s1("hello");
	std::string s2 = "hello"; // ok
	//foo("hello"); // explicit 생성자라면 error - 그러나 string을 사용가능 따라서 string은 explicit생성자가 아닙니다.

	// vector는 생성자가 explicit임.
	std::vector<int> v10(10); // 10개짜리 vector
	std::vector<int> v2 = 10; // error
	std::vector<int> v3 { 10 }; // 1개짜리 vector, 초기값 10인 vector
	std::vector<int> v4 = { 10 }; // ok, explicit가 아닌 다른 생성자 존재

	// c++ 표준 스마트 포인터는 모두 explicit 이다.
	std::unique_ptr<int> p1(new int);
	std::unique_ptr<int> p2 = new int; // error
}