// 2_스마트포인터1
#include <memory>
#include <iostream>

int main()
{
	std::shared_ptr<int> sp1(new int);
	std::shared_ptr<int> sp2 = sp1;

	// 스마트포인터의 크기는 일반적으로 raw pointer의 2배이다.
	std::cout << sizeof(sp1)     << std::endl;
	std::cout << sp1.use_count() << std::endl;

	//-----------------------------
	// 아래 코드는 절대 안됩니다.
	// 자원을 관리하기 위한 관리 객체가 sp3, sp4 각각 생성됩니다.
	int* p = new int;
	std::shared_ptr<int> sp3(p);
	std::shared_ptr<int> sp4(p);

	std::cout << sp3.use_count() << std::endl; // ?
	// 
	// RAII : Resource Acquision Is Initialization - 197
	// 자원을 할당하는 것은 자원 관리 객체가 초기화 될때 이어야한다
	std::shared_ptr<int> sp5(new int); // ok!!!
}




