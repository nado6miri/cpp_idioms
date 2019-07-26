//#include <iostream>

// 함수 객체의 장점 2.
// 다른 함수의 인자로 전달되는 함수를 만들때
// 1. 일반 함수를 보내면 다시 호출시 인라인 치환되지 못한다.
// 2. 함수 객체를 보내면 다시 호출시 인라인 치환된다.



// 1. 인라인 함수는 컴파일 할때 이루어 진다.

inline int Add(int a, int b) { return a + b; }

struct Plus
{
	inline int operator()(int a, int b) { return a + b; }
};

template<typename T> void foo(T f)
{
	//std::cout << __FUNCSIG__ << std::endl;

	int n = f(1, 2); // 이순간을 잘 생각해 보세요
		// f.operator()(1,2)
}
int main()
{
	Plus p;
	foo(Add);  // 함수 포인터 전달 foo(int(*f)(int, int))
//	foo(Sub);  // 함수 포인터 전달 foo(int(*f)(int, int))

	foo(p);    // Plus 타입으로 전달  foo(Plus f)
//	Minus m;
//	foo(m);     // foo(Minus)
}


// cl 3_함수객체3.cpp    /FAs      => 3_함수객체3.asm
// cl 3_함수객체3.cpp    /FAs /Ob1

// g++ 3_함수객체3.cpp -S         => 3_함수객체3.s



