// 3_int2type.cpp 115 page

/*
class A
{
	int data;
public :
	void foo(int a)
	{
		*a = 10; // error
	}
};
*/

// 템플릿은 클래스를 만드는 툴임. - template를 사용하지 않으면 컴파일 되지 않음.
// lazy instantiation : 사용된 템플릿만 인스턴스화 (실제 C++코드생성) 된다.
template<typename T>
class A
{
	T data;
public:
	void foo(T a)
	{
		*a = 10; 
	}
};


int main()
{
	// 아래 코드는 에러가 나지 않는다. foo() 함수를 호출하지 않았기 때문.. 따라서 사용하지 않았다면 컴파일 되지 않음.
	A<int> a;
	// 아래에서 foo 호출시 컴파일 단계에서 문제 발생함.
	a.foo(4);
}