#include <iostream>

// 1. template 으로 해야 한다.

template<typename T>
class unique_ptr
{
	T* obj;
public:
	inline unique_ptr(T* p = 0) : obj(p) {}
	inline ~unique_ptr() { delete obj; }
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

	// 복사생성자와 대입연산자를 삭제 합니다.
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};

int main()
{
	unique_ptr<int> p1(new int);
	*p1 = 10;
	//unique_ptr<int> p2 = p1; // error
}

