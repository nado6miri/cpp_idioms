
#include <iostream>
#include <memory>

// ������ �Լ���ü


template<typename T> struct default_delete
{
	inline void operator()(T* p)
	{
		std::cout << "default delete" << std::endl;
		delete p; // delete�� void * type�� ������ �Ҹ��� ȣ�� ����. �׷��� T�� ���
	}
};

struct Freer
{
	// free�� �Ҹ��� ȣ������ �����Ƿ� void*�� ����ص� �˴ϴ�.
	inline void operator()(void* p)
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};

template<typename T, typename D = default_delete<T>>
class unique_ptr
{
	T* obj;
	D d; // �����ڸ� �����մϴ�.
public:
	inline unique_ptr(T* p = 0, const D& del = D()) : obj(p), d(del) {}
	inline ~unique_ptr()
	{
		std::cout << "default delete" << std::endl;
		d(obj);
	}
	inline T* operator->() { return obj; };
	inline T& operator*() { return *obj; }

	// ���� �����ڿ� ���� �����ڸ� ���� �մϴ�.
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};

int main()
{
	unique_ptr<int> p1(new int);
	//unique_ptr<void> p2(malloc(100)); // malloc���� ������ ���� �Ҹ��ڷ� delete�ϸ� �ȵ�, 
	//unique_ptr<void, Freer> p2((int*)malloc(100));

	// error. ���� ǥ������ Ÿ���� �ƴ϶� ��ü�� 
	//unique_ptr<void, [](int*) { free(p); } > p2((int*)malloc(100));

	//unique_ptr<void, decltype([](int*) { free(p); })> p2((int*)malloc(100));

	// �����ڷ� ����� ���� ǥ������ ���� auto�� ��´�. ���ٽ��� �̿��ؼ� ���޽� �Ҹ��� ó��..
	auto del = [](void* p) { free(p); std::cout << "lambda" << std::endl;  };
	unique_ptr<int, decltype(del)> p3(new int, del);
}