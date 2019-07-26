#include <iostream>
#include <memory>

int main()
{
	int* rp = nullptr; // raw pointer �� ��ü�� �ı��� �����
					   // �˼� ����.
	std::weak_ptr<int> wp; // ��������� �������� �ʴ� ����Ʈ������
	{
		std::shared_ptr<int> sp1(new int);
		std::shared_ptr<int> sp2 = sp1; // ������� ����

		rp = sp1.get();  // ��¥ ������ ������
		wp = sp1;

		std::cout << sp1.use_count() << std::endl;
	}
	// android/  libutils/refbase.h ���� ������.


	if (wp.expired())
	{
		std::cout << "wp : ��ü�� �ı���" << std::endl;
	}

	if (rp != nullptr)
	{
		std::cout << "��ü���" << std::endl;
	}
}

