#include <iostream>
#include <string>
#include <vector>
#include <memory>
void foo(std::string s) {}

int main()
{
	// string �� explicit �����ڰ� �ƴմϴ�.
	std::string s1("hello");
	std::string s2 = "hello"; // ok.
	//foo("hello"); // explicit ������ ��� error
 
	// vector�� �����ڴ� explicit �Դϴ�
	std::vector<int> v1(10);  // 10��¥�� vector
	std::vector<int> v2 = 10;  // error
	std::vector<int> v3{ 10 }; // 1���� 10���� �ʱ�ȭ
	std::vector<int> v4 = { 10 }; // ok. explicit �ƴ�.

	// C++ ǥ�� ����Ʈ�����ʹ� ��� explicit
	std::unique_ptr<int> p1(new int);
	std::unique_ptr<int> p2 = new int; // error
}



