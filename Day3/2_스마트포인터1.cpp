// 2_스마트 포인터
#include <memory>
#include <iostream>

int main()
{
	// shared ptr 은 객체도 가리키고 refcnt를 관리하는 관리객체를 생성하고 둘다 가리키고 있다. 진짜 포인터의 2배로 잡힘. 
	std::shared_ptr<int> sp1(new int); // 
	std::shared_ptr<int> sp2 = sp1;

	std::cout << sizeof(sp1) << std::endl;
	std::cout << sp1.use_count() << std::endl;

	int* p = new int;
	std::shared_ptr<int> sp3(p);
	// 아래 코드는 절대 안됩니다.. - 자원을 관리하기 위한 객체가 sp3, sp4 각각 생성됩니다.
	// sp4 입장에서는 sp3에서 관리하는 동일한 객체를 관리하기 위해 별도의 관리 객체를 생성함.  sp3가 없어지면 sp4는 dangling이 됨.
	//std::shared_ptr<int> sp4(p); 

	// 따라서 shared ptr을 사용시 
	// RAII : Resource Acquisition Is Initiaization : 자원을 할당하는 것은 자원 관리 객체가 초기화 될때 이어야 한다. - 아래처럼 사용해야 함.
	std::shared_ptr<int> sp5(new int); // OK


	std::cout << sp5.use_count() << std::endl; 
}