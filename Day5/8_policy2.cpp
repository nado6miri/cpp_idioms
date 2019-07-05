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
		// 메모리가 부족해서 재 할당 해야 합니다. 어떻게 할까요?
		// new ? malloc ? brk ? HeapAlloc -> 할당방법 다양 따라서 해제 방법도 다양해야함. 그래서  policy base
		buff = ? ;
	}
};
*/

template<typename T, typename Ax = std::allocator<T> > class vector
{
	Ax ax; // 메모리 할당기
	T* buff;
	int size;

public:
	void push_back(const T& a)
	{
		// 메모리가 부족해서 재 할당 해야 합니다. 어떻게 할까요?
		// new ? malloc ? brk ? HeapAlloc -> 할당방법 다양 따라서 해제 방법도 다양해야함. 그래서  policy base
		buff = ax.allocate(size*1.5);
		ax.deallocate(buff, size*1.5);
	}
};