// 3_int2type1.cpp       115 page

/*
class A
{
	int data;
public:
	void foo(int a)
	{
		*a = 10;	// error
	}
};
*/
// 템플릿 : 클래스를 만드는 틀
//          사용하지 않으면 클래스가 생성되지 않는다.
// lazy instantiation : 사용된 템플릿만 
//					인스턴스화(실제 C++코드생성) 된다.

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
	A<int> a;
	a.foo(0);
}



