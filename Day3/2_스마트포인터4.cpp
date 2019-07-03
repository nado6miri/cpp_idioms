#include <iostream>
#include <memory>

// android/libutils/refbase.h �� ���� ������.
// platform_system_core / libutils / RefBase.cpp - 149 ����...
int main()
{
	// raw pointer�� ���� �������� ������(������� ���� ����)- �������� ��ü�� �ı��� ����� �� �� ����. �׷��� weak_ptr�� ����Ѵ�.
	// weak_ptr�� ������� �������� ������ ��ü�� �ı��Ǿ����� �� �� �ִ�.
	// weak_ptr�� �ڿ��� �ּ� �Ӹ� �ƴ϶� ������ü �ּҵ� ������ �ִ�. (������ü�� weak_ptr�� ����ϰ� ����
	// ������ü �ı� ������ strong counter / weak counter ��� 0�� �ɶ� �����.
	// ���� counter / �ڿ� ptr / weak count /  ������
	// make_shared�� ����ϰ� �Ǹ� ��ü�� ������ü�� �ϳ��� �����Ǳ� ������ ��ü�� �Ҹ�Ǵ���(�Ҹ��� ȣ��) ���� ��ü�� �����Ⱓ �����ؾ� �ϱ� ������
	// �޸� ���鿡�� ���ظ� ����. ���߿� ������ü ������ ���� ������.
	int* rp = nullptr; 
	std::weak_ptr<int> wp; // ��������� �������� �ʴ� ����Ʈ ������
	{
		std::shared_ptr<int> sp1(new int);
		std::shared_ptr<int> sp2 = sp1; // ������� ����

		rp = sp1.get(); // ��¥ ������ ������..

		std::cout << sp1.use_count() << std::endl;
	}

	if (rp != nullptr)
	{
		std::cout << "��ü���" << std::endl;
	}

	if (wp.expired())
	{
		std::cout << "wp ��ü �ı���" << std::endl;
	}

}