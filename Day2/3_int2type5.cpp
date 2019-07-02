#include<iostream>
#include<type_traits>

template<int N> struct int2type   // 115 page code
{
	enum { value = N };
};

int main()
{
	// foo(0) foo(1)은 같은 함수를 호출함.
	foo(0);
	foo(1);

	// t0 / t1은 다른타입,   foo(t0), foo(t1)은 다른함수 호출됨.
	// int2type 을 이용하면 동일한 정수 타입도 다르게 함수를 호출할 수 있다. 90년대 말에 ....
	int2type<0> t0;
	int2type<1> t1;
	foo(t0);
	foo(t1);
}

