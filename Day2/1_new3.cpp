#include <iostream>
#include <vector>
/*
int main()
{
	// 1. vector의 메모리 관리 기술
	std::vector<int> v(10);

	v.resize(7); // 원리를 생각해 봅시다.

	std::cout << "v.size = " << v.size() << std::endl;
	std::cout << "v.capacity = " << v.capacity() << std::endl;

	v.push_back(5);
	std::cout << "v.size = " << v.size() << std::endl; // 
	std::cout << "v.capacity = " << v.capacity() << std::endl;  // 8

	v.shrink_to_fit();
	std::cout << "v.size = " << v.size() << std::endl; // 8
	std::cout << "v.capacity = " << v.capacity() << std::endl; // 8

	v.push_back(5);
	std::cout << "v.size = " << v.size() << std::endl; // 9
	std::cout << "v.capacity = " << v.capacity() << std::endl;  // ? 컴파일러마다 다름... 1.5배 2배 확장
}
*/

class DBConnect
{
public:
	DBConnect() { std::cout << "Connnect DB" << std::endl; }
	~DBConnect() { std::cout << "Disconnnect DB" << std::endl; }
};

int main()
{
	vector<DBConnect> v(5);
	// 줄어든 메모리는 파괴되지 않습니다. 하지만 소멸자는 호출해야 합니다. 소멸자의 명시적 호출이 필요합니다.
	v.resize(3); 

	// 늘어난 한개의 객체를 위한 메모리는 이미 존재함. 메모리 공간은 이미 존재하지만 1개를 다시 늘렸다면 생성자 호출이 필요함. placement new를 사용해서 생성자 호출 필요함.
	v.resize(4); 
}