#include <iostream>
#include <vector>

template<typename T, typename Ax = std::allocator<T> > class vector
{
	Ax ax; // �޸� �Ҵ��
	T* buff;
	int size;
public:
	void push_back(const T& a)
	{
		// �޸𸮰� �����ؼ� ���Ҵ��ؾ� �մϴ�. ��� �ұ�� ?
		// new ? malloc ? brk ? HeapAlloc 
		buff = ax.allocate(size* 1.5);
		ax.deallocate(buff, size*1.5);
	}
};


