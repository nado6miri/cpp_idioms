// 2_����Ʈ ������
#include <memory>
#include <iostream>

int main()
{
	// shared ptr �� ��ü�� ����Ű�� refcnt�� �����ϴ� ������ü�� �����ϰ� �Ѵ� ����Ű�� �ִ�. ��¥ �������� 2��� ����. 
	std::shared_ptr<int> sp1(new int); // 
	std::shared_ptr<int> sp2 = sp1;

	std::cout << sizeof(sp1) << std::endl;
	std::cout << sp1.use_count() << std::endl;

	int* p = new int;
	std::shared_ptr<int> sp3(p);
	// �Ʒ� �ڵ�� ���� �ȵ˴ϴ�.. - �ڿ��� �����ϱ� ���� ��ü�� sp3, sp4 ���� �����˴ϴ�.
	// sp4 ���忡���� sp3���� �����ϴ� ������ ��ü�� �����ϱ� ���� ������ ���� ��ü�� ������.  sp3�� �������� sp4�� dangling�� ��.
	//std::shared_ptr<int> sp4(p); 

	// ���� shared ptr�� ���� 
	// RAII : Resource Acquisition Is Initiaization : �ڿ��� �Ҵ��ϴ� ���� �ڿ� ���� ��ü�� �ʱ�ȭ �ɶ� �̾�� �Ѵ�. - �Ʒ�ó�� ����ؾ� ��.
	std::shared_ptr<int> sp5(new int); // OK


	std::cout << sp5.use_count() << std::endl; 
}