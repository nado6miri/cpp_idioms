#include <iostream>
#include <memory>

void foo(void *p) { free(p); }

int main()
{
	std::shared_ptr<int> p1(new int); // p1의 소멸자에서 자동으로 delete ehla
	//std::shared_ptr<void> p2(malloc(100), 삭제자 함수); // malloc을 했기 때문에 삭제자 함수 전달 필요
	//std::shared_ptr<void> p2(malloc(100), foo); // malloc을 했기 때문에 삭제자 함수 전달 필요 - old style..

	std::shared_ptr<void> p2(malloc(100), [](void*p) { free(p); }); // c++ 11에서 람다 함수 지원
	
	// 관리객체 : strong count(참조계수), 자기 자신포인터, weak count.., 마지막으로 삭제자를 보관하게 됨
}