#include <iostream>
#include <memory>
void foo(void* p) { free(p); }

int main()
{
	// ������ ����
	std::shared_ptr<int>  p1(new int); // p1�� �Ҹ��ڿ��� delete
	//std::shared_ptr<void> p2(malloc(100), �������Լ�);
	//std::shared_ptr<void> p2(malloc(100), foo);

	// �ᱹ ���� ��ü�ȿ� �����ڸ� �����ϰ� �˴ϴ�.

	std::shared_ptr<void> p2(malloc(100), 
							[](void*p) { free(p); });


}