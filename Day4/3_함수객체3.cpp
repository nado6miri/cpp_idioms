//#include <iostream>

// 함수객체 : () 연산자를 재정의 해서 함수처럼 사용 가능한 것
// ---> 함수객체는 함수의 param으로 함수를 전달시 유용함.

// 함수객체 장점 1. 상태를 가지는 함수
// 일반함수는 동작만 있고 상태를 가질 수 없다.
// 함수 객체는 클래스(구조체)이므로 멤버 데이터와 멤버 함수 활용 가능함.


// 함수객체 장점 2.
// 다른 함수의 인자로 전달되는 함수를 만들때
// - 일반함수를 보내면 다시 호출시 인라인 치환되지 못한다.
// - 함수 객체를 보내면 다시 호출시 인라인 치환된다.

// 1. inline 함수는 컴파일할때 치환이 이루어 진다.
inline int Add(int a, int b) { return a + b; }

struct Plus
{
	inline int operator() (int a, int b) { return a + b; }
};

template<typename T> void foo(T f)
{
	//std::cout << __FUNCSIG__ << std::endl;
	int n = f(1, 2); // 이 순간을 잘 생각해 보세요. f.operator()(1,2)
}


int main()
{
	Plus p;
	foo(Add); // 함수 포인터 전달 - (int(*f)(int, int) - inline을 썼을때와 안섰을때 비교 --> 함수의 ptr이 넘어가기 때문에 타입을 알 수 없어 타입 치환이 불가.
	foo(p);		// Plus 타입으로 전달됨. - inline을 썼을때와 안섰을때 비교  ---> 모두다 됨. 타입으로 보내야 치환이 자유롭다.
}

// cl 3_함수객체3.cpp /FAs ==> ASM FILE 만들어짐
// cl 3_함수객체3.cpp /FAs /Ob1 ===> inline함수를 치환여부 확인 call 이있냐 없냐?  치환되도록 옵션 추가