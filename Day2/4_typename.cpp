// 4_typename
class AAA
{
public:
	enum { value = 10 };
	typedef int DWORD;
};

int p = 0;

template<typename T> void foo(T a)
{
	// 컴파일러는 아래 한줄을 어떻게 해석할까요?
	// (1) DWORD는 값(static 변수 또는 enum 상수)이다.
	// (2) DWORD는 T안에 내포된 타입이다.
	//T::DWORD *p; // DWORD를 값으로 보고 곱하기 p하는 코드임  :: 뒤에는 변수 값으로 간주
	typename T::DWORD *p; // DWORD를 type으로 해석해 달라라는 의미임. 포인터로 간주함.

	// 핵심 : 템플릿 인자(T)의 의존된 타입을 사용할때 반드시 앞에 typename을 붙여야 한다.!!!
	typename AAA::DWORD *p2; //  typename이 필요없다.  T가 아니라 명혹한 이름(AAA) 를 사용했기 때문에....
}

int main()
{
	AAA aaa;
	foo(aaa);
}