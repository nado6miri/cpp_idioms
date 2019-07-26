#include <iostream>

/*
// new 를 사용하면 operator new()가 호출됩니다.
void* operator new(size_t sz)
{
	void* p = malloc(sz);

	if (p == nullptr)
		throw std::bad_alloc();
	
	return p;
}

// 함수 오버로딩시 empty을 사용하는 경우가 많이 있습니다.
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
		int* p1 = new int; // 메모리 부족시 std::bad_alloc 예외 발생
	}
	catch (std::bad_alloc& b) {}

	int* p2 = new(nothrow) int; // 메모리 부족시 0반환

	if (p2 = nullptr) {}
}


