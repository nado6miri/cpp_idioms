template<typename T> class Test
{
public:
	// 아래 코드는 forwarding reference 일까요 ?
	// 아닙니다. 클래스가 템플릿 이지 함수 자체가 템플릿이 아닙니다.
	// 클래스 생성시 이미 T의 타입이 결정됩니다.
	void foo(T&& arg) { }

	// 아래 코드가 forwarding reference 입니다.
	template<typename U> void goo(U&& arg) {}
};
int main()
{
	int n = 0;
	Test<int> t;
	t.foo(10);
	t.foo(n);
}