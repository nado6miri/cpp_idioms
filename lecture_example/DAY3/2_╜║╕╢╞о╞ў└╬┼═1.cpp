// 2_����Ʈ������1
#include <memory>
#include <iostream>

int main()
{
	std::shared_ptr<int> sp1(new int);
	std::shared_ptr<int> sp2 = sp1;

	// ����Ʈ�������� ũ��� �Ϲ������� raw pointer�� 2���̴�.
	std::cout << sizeof(sp1)     << std::endl;
	std::cout << sp1.use_count() << std::endl;

	//-----------------------------
	// �Ʒ� �ڵ�� ���� �ȵ˴ϴ�.
	// �ڿ��� �����ϱ� ���� ���� ��ü�� sp3, sp4 ���� �����˴ϴ�.
	int* p = new int;
	std::shared_ptr<int> sp3(p);
	std::shared_ptr<int> sp4(p);

	std::cout << sp3.use_count() << std::endl; // ?
	// 
	// RAII : Resource Acquision Is Initialization - 197
	// �ڿ��� �Ҵ��ϴ� ���� �ڿ� ���� ��ü�� �ʱ�ȭ �ɶ� �̾���Ѵ�
	std::shared_ptr<int> sp5(new int); // ok!!!
}




