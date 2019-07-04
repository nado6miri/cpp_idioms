#include <iostream>


class People
{
	char* name;
	int age;
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

	// �ӽð�ü(rvalue)�� ��� ���� ���� - �ڿ��� ������ ���� �ƴ϶� move �̵� ��������.
	People(const People&& p) : name(p.name), age(p.age)
	{
		p.name = nullptr; // �ڿ� �����ϵ��� �����ϸ� ��.
		p.age = 0; //  �ص��׸� ���ص� �׸�
	}

};

People foo()
{
	People p("lee", 30);
	return p;
}

int main()
{
	People p1("kim", 10);
	People p2 = p1;  

	// �ӽ� ��ü�� �Ѿ���� ���� �����ϰ� �ӽð�ü�� �����
	// ���� �ӽð�ü ������ ���� �ٷ� ���������� �ϸ� ȿ������ ����.
	// �ӽð�ü�϶�(rvalue)�� ����Ͽ� �ϳ� �� �����.
	People p3 = foo();
}