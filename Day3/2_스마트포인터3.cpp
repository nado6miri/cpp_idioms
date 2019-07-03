#include <iostream>
#include <memory>

void foo(void *p) { free(p); }

int main()
{
	std::shared_ptr<int> p1(new int); // p1�� �Ҹ��ڿ��� �ڵ����� delete ehla
	//std::shared_ptr<void> p2(malloc(100), ������ �Լ�); // malloc�� �߱� ������ ������ �Լ� ���� �ʿ�
	//std::shared_ptr<void> p2(malloc(100), foo); // malloc�� �߱� ������ ������ �Լ� ���� �ʿ� - old style..

	std::shared_ptr<void> p2(malloc(100), [](void*p) { free(p); }); // c++ 11���� ���� �Լ� ����
	
	// ������ü : strong count(�������), �ڱ� �ڽ�������, weak count.., ���������� �����ڸ� �����ϰ� ��
}