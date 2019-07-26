#include <iostream>
#include <vector>

/*
int main()
{
	// 1. vector 의 메모리 관리기술
	std::vector<int> v(10);

	v.resize(7); // 원리를 생각해 봅시다.

	std::cout << v.size() << std::endl;		// 7
	std::cout << v.capacity() << std::endl; //10

	v.push_back(5);

	std::cout << v.size() << std::endl;		// 8
	std::cout << v.capacity() << std::endl;	// 10

	v.shrink_to_fit();

	std::cout << v.size() << std::endl;		// 8
	std::cout << v.capacity() << std::endl;	// 8

	v.push_back(5);

	std::cout << v.size() << std::endl;		// 9
	std::cout << v.capacity() << std::endl;	// 12
}
*/

class DBConnect
{
public:
	DBConnect()  { std::cout << "Connect DB" << std::endl; }
	~DBConnect() { std::cout << "Disconnect DB" << std::endl; }
};
int main()
{
	vector<DBConnect> v(5);
	v.resize(3); // 줄어든 메모리는 파괴 되지 않습니다.
				// 하지만 소멸자를 호출해야 합니다.
				// 소멸자의 명시적 호출이 필요합니다

	v.resize(4);// 늘어난 한개의 객체를 위한 메모리는 이미 있습니다.
				// 존재하는 메모리에 생성자만 다시 호출해야 합니다.
				// placement new 를 사용해서 생성자 호출
}





