#include <iostream>
#include <string>
#include <vector>
#include <memory>

int main()
{
	std::string s1("hello");
	std::string s2 = "hello"; // ok
	//foo("hello"); // explicit �����ڶ�� error - �׷��� string�� ��밡�� ���� string�� explicit�����ڰ� �ƴմϴ�.

	// vector�� �����ڰ� explicit��.
	std::vector<int> v10(10); // 10��¥�� vector
	std::vector<int> v2 = 10; // error
	std::vector<int> v3 { 10 }; // 1��¥�� vector, �ʱⰪ 10�� vector
	std::vector<int> v4 = { 10 }; // ok, explicit�� �ƴ� �ٸ� ������ ����

	// c++ ǥ�� ����Ʈ �����ʹ� ��� explicit �̴�.
	std::unique_ptr<int> p1(new int);
	std::unique_ptr<int> p2 = new int; // error
}