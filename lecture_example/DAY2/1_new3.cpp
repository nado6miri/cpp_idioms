#include <iostream>
#include <vector>

/*
int main()
{
	// 1. vector �� �޸� �������
	std::vector<int> v(10);

	v.resize(7); // ������ ������ ���ô�.

	std::cout << v.size() << std::endl;		// 7
	std::cout << v.capacity() << std::endl; //10

	v.push_back(5);

	std::cout << v.size() << std::endl;		// 8
	std::cout << v.capacity() << std::endl;	// 10

	v.shrink_to_fit();

	std::cout << v.size() << std::endl;		// 8
	std::cout << v.capacity() << std::endl;	// 8

	v.push_back(5);

	std::cout << v.size() << std::endl;		// 9
	std::cout << v.capacity() << std::endl;	// 12
}
*/

class DBConnect
{
public:
	DBConnect()  { std::cout << "Connect DB" << std::endl; }
	~DBConnect() { std::cout << "Disconnect DB" << std::endl; }
};
int main()
{
	vector<DBConnect> v(5);
	v.resize(3); // �پ�� �޸𸮴� �ı� ���� �ʽ��ϴ�.
				// ������ �Ҹ��ڸ� ȣ���ؾ� �մϴ�.
				// �Ҹ����� ����� ȣ���� �ʿ��մϴ�

	v.resize(4);// �þ �Ѱ��� ��ü�� ���� �޸𸮴� �̹� �ֽ��ϴ�.
				// �����ϴ� �޸𸮿� �����ڸ� �ٽ� ȣ���ؾ� �մϴ�.
				// placement new �� ����ؼ� ������ ȣ��
}





