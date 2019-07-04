
#include <iostream>
#include <memory>

// 삭제자 함수객체


template<typename T> struct default_delete
{
	inline void operator()(T* p)
	{
		std::cout << "default delete" << std::endl;
		delete p; // delete는 void * type을 받으면 소멸자 호출 못함. 그래서 T를 사용
	}
};

struct Freer
{
	// free는 소멸자 호출하지 않으므로 void*를 사용해도 됩니다.
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
public:
	inline unique_ptr(T* p = 0) : obj(p) {}
	inline ~unique_ptr() 
	{ 
		std::cout << "default delete" << std::endl;
		D d;
		d(obj); 
	}
	inline T* operator->() { return obj; };
	inline T& operator*() { return *obj; }

	// 복사 생성자와 대입 연산자를 삭제 합니다.
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};

int main()
{
	unique_ptr<int> p1(new int);
	unique_ptr<void> p2(malloc(100)); // malloc으로 생성된 것은 소멸자로 delete하면 안됨, 
	unique_ptr<void, Freer> p2((int*)malloc(100)); 

	//std::unique_ptr<

	// 아래 2개는 다른타입? 같은타입? - 동일한 타입이라 같은 컨테이너에 들어갈 수 있다. 유니크 보다 shared_ptr의 장점이나 성능은 unique_ptr이 장점임
	//std::shared_ptr<int> sp1(new int);
	//std::shared_ptr<int> sp2(new int, foo);
}