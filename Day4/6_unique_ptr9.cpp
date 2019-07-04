#include <iostream>
#include <memory>

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
	PAIR(A&& a, B&& b) : v1(std::forward<A>(a)), v2(std::forward<B>(b)) {};

	PAIR() = default; // default 생성자를 만들어라.  PAIR {} 와 동일 의미
};

template<typename T, typename U> struct PAIR : public T
{
	U v2;
	T& getValue1() { return *this; };
	U& getValue2() { return v2; };

	template<typename A, typename B>
	PAIR(A&& a, B&& b) : T(std::forward<A>(a)), v2(std::forward<B>(b)) {};

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
		delete[]p;
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
	//inline unique_ptr(T* p = 0, const D& del = D()) :  m(del, p) {}
	template<typename Dx = D> inline unique_ptr(T* p = 0, const D& del = Dx())
		: m(std::forward<Dx>(del), p) {}

	inline ~unique_ptr()
	{
		m.getValue1()(m.getValue2());
	}

	inline T* operator->() { return (m.getValue2()); }
	inline T& operator*() { return *(m.getValue2()); }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};



template<typename T, typename D>
class unique_ptr<T[], D>
{
	// main 2번째 줄처럼 사용하면 T ==> int[] 이므로 아래 코드가 오른쪽 주석처럼 됩니다. 그래서 에러 발생함. -> 다음 unitque_ptr7에서 에러 해결하자.
	PAIR<D, T*> m;  // PAIR(D, int*> m , 형태로 치환 ---> ok
public:
	//inline unique_ptr(T* p = 0, const D& del = D()) : m(del, p) {}
	template<typename Dx = D> inline unique_ptr(T* p = 0, const D& del = Dx()) 
		: m(std::forward<Dx>(del), p) {}

	inline ~unique_ptr()
	{
		m.getValue1()(m.getValue2());
	}

	// 배열 버전에서는 []를 제공하는 것이 좋습니다.
	T& operator[](int idx)
	{
		// m.getValue2() : 보관된 포인터 꺼네기
		return m.getValue2()[idx];
	}

	inline T* operator->() { return (m.getValue2()); }
	inline T& operator*() { return *(m.getValue2()); }

	// 복사계열 금지 - 복사 정책을 변경하면 move도 만들어 줘야 함.
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

	// move 계열 제공
	inline unique_ptr(unique_ptr&& p) noexcept
		: m(std::move(p.m)) {}

	inline unique_ptr& operator=(unique_ptr&& p) noexcept
	{
		m = std::move(p.m);
		return *this;
	}
};

/*
int main()
{
	unique_ptr<int>  p1(new int);
	unique_ptr<int[]>  p1(new int[10]);

}
*/

int main()
{
	// 이번에 소스 변한것 
	// 1. 생성자 변경 - forwarding reference 사용
	// 2. unique_ptr에 move 생성자를 넣었다. (move 지원)
	Freer f;
	unique_ptr<int, Freer> p1(new int, std::move(f));
	unique_ptr<int> p2(new int);
	//unique_ptr<int> p3 = p2; //error
	//unique_ptr<int> p4 = std::move(p2); // 되어야 한다.
}

//=======이 소스는 강사 소스를 참고하자... 뭔말인지...

 