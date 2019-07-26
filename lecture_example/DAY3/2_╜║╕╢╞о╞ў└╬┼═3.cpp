#include <iostream>
#include <memory>
void foo(void* p) { free(p); }

int main()
{
	// 삭제자 변경
	std::shared_ptr<int>  p1(new int); // p1의 소멸자에서 delete
	//std::shared_ptr<void> p2(malloc(100), 삭제자함수);
	//std::shared_ptr<void> p2(malloc(100), foo);

	// 결국 관리 객체안에 삭제자를 보관하게 됩니다.

	std::shared_ptr<void> p2(malloc(100), 
							[](void*p) { free(p); });


}