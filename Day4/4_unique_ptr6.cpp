#include <iostream>
#include <memory>

// 재확인 필요 - 왜이리 빠르냐...

class Empty {};

template<typename T
	, typename U
	, bool b = std::is_empty<T>::value>
struct PAIR
{};

// 결국 위의 pair는 사용하지 않고 아래 2개만 사용됩니다. 이 경우에는 선언만 해도 됩니다.
// 아래 소스가 boost lib 의 "compress_pair" 입니다.
// c++  표준인 unique_ptr 만들때 이 기술이 사용된다.

template<typename T, typename U> struct PAIR<T, U, false> // 부분 특수화
{
	T v1;
	U v2;
	T& getValue1() { return v1; };
	U& getValue2() { return v2; };

	template<typename A, typename B>
	PAIR(A&& a, B&& b) : v1(std::forward(<A>(a)), v2(std::forward<B>(b)) {};

	PAIR() = default; // default 생성자를 만들어라.  PAIR {} 와 동일 의미
};

template<typename T, typename U> struct PAIR : public T
{
	U v2;
	T& getValue1() { return *this; };
	U& getValue2() { return v2; };

	template<typename A, typename B>
	PAIR(A&& a, B&& b) : T(std::forward(<A>(a)),  // 기반 클래스 생성자 호출
		v2(std::forward<B>(b)) {};

	PAIR() = default; // default 생성자를 만들어라.  PAIR {} 와 동일 의미
};



template<typename T> struct default_delete
{
	inline void operator()(T* p)
	{
		std::cout << "default delete" << std::endl;
		delete p;
	}
};

template<typename T> struct default_delete<T[]>
{
	inline void operator()(T* p)
	{
		std::cout << "default [] delete" << std::endl;
		delete []p;
	}
};


struct Freer
{
	inline void operator()(void* p)
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};


template<typename T, typename D = default_delete<T> >
class unique_ptr
{
	// main 2번째 줄처럼 사용하면 T ==> int[] 이므로 아래 코드가 오른쪽 주석처럼 됩니다. 그래서 에러 발생함. -> 다음 unitque_ptr7에서 에러 해결하자.
	PAIR<D, T*> m;  // PAIR(D, int[]*> 형태로 치환 ---> 에러 발생
public:
	inline unique_ptr(T* p = 0, const D& del = D())
		: m(del, p) {}
	inline ~unique_ptr()
	{
		m.getValue1()(m.getValue2());
	}

	inline T* operator->() { return (m.getValue2()); }
	inline T& operator*() { return *(m.getValue2()); }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};

int main()
{
	unique_ptr<int>  p1(new int);
	unique_ptr<int[]>  p1(new int[10]);

}



