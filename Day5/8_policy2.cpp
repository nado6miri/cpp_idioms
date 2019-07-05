#include <iostream>
#include <vector>
/*
template<typename T> class vector
{
	T* buff;
	int size;

public:
	void push_back(const T& a)
	{
		// �޸𸮰� �����ؼ� �� �Ҵ� �ؾ� �մϴ�. ��� �ұ��?
		// new ? malloc ? brk ? HeapAlloc -> �Ҵ��� �پ� ���� ���� ����� �پ��ؾ���. �׷���  policy base
		buff = ? ;
	}
};
*/

template<typename T, typename Ax = std::allocator<T> > class vector
{
	Ax ax; // �޸� �Ҵ��
	T* buff;
	int size;

public:
	void push_back(const T& a)
	{
		// �޸𸮰� �����ؼ� �� �Ҵ� �ؾ� �մϴ�. ��� �ұ��?
		// new ? malloc ? brk ? HeapAlloc -> �Ҵ��� �پ� ���� ���� ����� �پ��ؾ���. �׷���  policy base
		buff = ax.allocate(size*1.5);
		ax.deallocate(buff, size*1.5);
	}
};