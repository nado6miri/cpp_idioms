#include <iostream>

/*
// new �� ����ϸ� operator new()�� ȣ��˴ϴ�.
void* operator new(size_t sz)
{
	void* p = malloc(sz);

	if (p == nullptr)
		throw std::bad_alloc();
	
	return p;
}

// �Լ� �����ε��� empty�� ����ϴ� ��찡 ���� �ֽ��ϴ�.
struct nothrow_t {};
nothrow_t nothrow;

void* operator new(size_t sz, nothrow_t)
{
	void* p = malloc(sz);
	return p;
}
//#define nothrow 1
*/

int main()
{
	try
	{
		int* p1 = new int; // �޸� ������ std::bad_alloc ���� �߻�
	}
	catch (std::bad_alloc& b) {}

	int* p2 = new(nothrow) int; // �޸� ������ 0��ȯ

	if (p2 = nullptr) {}
}


