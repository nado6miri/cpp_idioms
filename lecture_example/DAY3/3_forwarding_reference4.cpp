// 함수 인자로
// int&  : int 의 lvalue 만 전달 가능
// int&& : int 의 rvalue 만 전달 가능
// T&    : 모든 타입의 lvalue만 전달 가능.

// T&&   : 모든 타입의 lvalue와 rvalue 전달 가능.

// lvalue(n) 을 보내면 T : int&     함수(int& )
// rvalue(0) 을 보내면 T : int      함수(int&& )

void f1(int&  a) {}
void f2(int&& a) {}

template<typename T> void f3(T&  a) {}
//f3<int>( n );
//f3<int&>( n );
//f3<int&&>( n );

template<typename T> void f4(T&& a) {}

int main()
{
	int n = 0;
	// 사용자가 타입을 직접 전달하면 어떤 함수가 생성될지
	// 생각해 봅시다. 생성되는 함수의 모양을 예측해 보세요
	f4<int>(0);   // T : int   T&& : int&&      f4(int&& )
	f4<int&>(n);  // T : int&  T&& : int& &&    f4(int&)
	f4<int&&>(0); // T : int&& T&& : int&& &&   f4(int&&)

	// 사용자가 타입을 지정하지 않으면 컴파일러가 타입을 결정해야
	// 합니다. 어떻게 결정할지 생각해 보세요
	f4(n);  // T : int& 로 결정하고.. 최종 함수 f4(int&)로 생성
	f4(0);  // T : int  로 결정하고,  최종 함수 f4(int&&)로 생성
}




