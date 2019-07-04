
#include <iostream>

// 1. Car�� �����ϱ� ������ Template���� ��ȯ����.

// smart pointer�� ����� ���ô�.
// �ٽ� : -> �� *�� �� �����ؼ� ������ ó�� ���̰� �ϴ� ��.
// ���� : raw pointer�� �ƴ϶� ��ü�̹Ƿ� �Ҹ��ڵ��� Ȱ���ؼ� �ڵ� ���� ����� ���� �� �ִ�.

template<typename T>
class unique_ptr
{
	T* obj;
public:
	inline unique_ptr(T* p = 0) : obj(p) {}
	inline ~unique_ptr() { delete obj; }
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

	// ���� �����ڿ� ���� �����ڸ� ���� �մϴ�.
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};

int main()
{
	unique_ptr<int> p1(new int);
	*p1 = 10;
//	unique_ptr<int> p2 = p1; // error - shared ptr�� ������....unique�δ� �ȵ�.
}