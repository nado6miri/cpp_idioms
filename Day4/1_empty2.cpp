#include <iostream>
/*
// new를 사용하면 operator new()가 호출됩니다.
void* operator new(size_t sz)
{
	void* p = malloc(sz);
	if (p == nullptr)
	{
		throw std::bad_alloc();
	}

	return p;
}

// nothrow 버전을 만들자...
// 함수 오버로딩시 empty를 사용하는 경우가 많습니다.
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
// nothrow 표준 코드와 비교해 보면 알 수 있다. 파람을 empty로 사용하는 이유...
int main()
{
	try {
		int* p1 = new int; // 메모리 부족시 c++표준에서 std::bad_alloc 예외 발생함.
	}
	catch (std::bad_alloc& b) {}

	int* p2 = new(nothrow) int; // 메모리 부족시 0으로 반환됨 표준에 nothrow 있음. nothow를 만들어 보자.. new 연산자 오버로딩
	if(p2 == nullptr) { }
}