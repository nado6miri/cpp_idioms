#include <iostream>
#include <vector>
/*
int main()
{
	// 1. vector�� �޸� ���� ���
	std::vector<int> v(10);

	v.resize(7); // ������ ������ ���ô�.

	std::cout << "v.size = " << v.size() << std::endl;
	std::cout << "v.capacity = " << v.capacity() << std::endl;

	v.push_back(5);
	std::cout << "v.size = " << v.size() << std::endl; // 
	std::cout << "v.capacity = " << v.capacity() << std::endl;  // 8

	v.shrink_to_fit();
	std::cout << "v.size = " << v.size() << std::endl; // 8
	std::cout << "v.capacity = " << v.capacity() << std::endl; // 8

	v.push_back(5);
	std::cout << "v.size = " << v.size() << std::endl; // 9
	std::cout << "v.capacity = " << v.capacity() << std::endl;  // ? �����Ϸ����� �ٸ�... 1.5�� 2�� Ȯ��
}
*/

class DBConnect
{
public:
	DBConnect() { std::cout << "Connnect DB" << std::endl; }
	~DBConnect() { std::cout << "Disconnnect DB" << std::endl; }
};

int main()
{
	vector<DBConnect> v(5);
	// �پ�� �޸𸮴� �ı����� �ʽ��ϴ�. ������ �Ҹ��ڴ� ȣ���ؾ� �մϴ�. �Ҹ����� ����� ȣ���� �ʿ��մϴ�.
	v.resize(3); 

	// �þ �Ѱ��� ��ü�� ���� �޸𸮴� �̹� ������. �޸� ������ �̹� ���������� 1���� �ٽ� �÷ȴٸ� ������ ȣ���� �ʿ���. placement new�� ����ؼ� ������ ȣ�� �ʿ���.
	v.resize(4); 
}