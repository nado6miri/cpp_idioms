#include <iostream>
/*
// new�� ����ϸ� operator new()�� ȣ��˴ϴ�.
void* operator new(size_t sz)
{
	void* p = malloc(sz);
	if (p == nullptr)
	{
		throw std::bad_alloc();
	}

	return p;
}

// nothrow ������ ������...
// �Լ� �����ε��� empty�� ����ϴ� ��찡 �����ϴ�.
struct nothrow_t {};
nothrow_t nothrow;
//#define nothrow	1

void* operator new(size_t sz, nothrow_t)
{
	void* p = malloc(sz);
	if (p == nullptr)
	{
		throw std::bad_alloc();
	}

	return p;
}
*/
// nothrow ǥ�� �ڵ�� ���� ���� �� �� �ִ�. �Ķ��� empty�� ����ϴ� ����...
int main()
{
	try {
		int* p1 = new int; // �޸� ������ c++ǥ�ؿ��� std::bad_alloc ���� �߻���.
	}
	catch (std::bad_alloc& b) {}

	int* p2 = new(nothrow) int; // �޸� ������ 0���� ��ȯ�� ǥ�ؿ� nothrow ����. nothow�� ����� ����.. new ������ �����ε�
	if(p2 == nullptr) { }
}