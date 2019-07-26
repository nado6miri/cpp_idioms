// 5_move1
#include <iostream>

class People
{
	char* name;
	int   age;
public:
	People(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~People() { delete[] name; }

	// ���� ����� ������ ���� ������
	People(const People& p) : age(p.age)
	{
		// ������ ������ �޸� ��ü�� ����
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}
};
int main()
{
	People p1("kim", 10);
	People p2 = p1;
}
