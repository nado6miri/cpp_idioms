
#include <iostream>

// 1. Car만 지원하기 때문에 Template으로 변환하자.

// smart pointer를 만들어 봅시다.
// 핵심 : -> 와 *를 재 정의해서 포인터 처럼 보이게 하는 것.
// 장점 : raw pointer가 아니라 객체이므로 소멸자등을 활용해서 자동 삭제 기능을 넣을 수 있다.

template<typename T>
class unique_ptr
{
	T* obj;
public:
	inline unique_ptr(T* p = 0) : obj(p) {}
	inline ~unique_ptr() { delete obj; }
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

	// 복사 생성자와 대입 연산자를 삭제 합니다.
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};

int main()
{
	unique_ptr<int> p1(new int);
	*p1 = 10;
//	unique_ptr<int> p2 = p1; // error - shared ptr을 만들어야....unique로는 안됨.
}