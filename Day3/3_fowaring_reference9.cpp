
// class는 템플릿.  foo는 템플릿이 아님.
template<typename T> class Test
{
public:
	// 아래 코드는 forwarding reference일까요? - forwarding reference 아님 - class는 템플릿.  foo는 템플릿이 아님.
	// class 생성시 이미 T type이 결정됩니다.
	void foo(T&& arg) { std::cout << __FUNCSIG__ << std::endl; }

	// 아래 코드가 forwarding reference 입니다.
	template<typename U> void goo(U&& arg) { std::cout << __FUNCSIG__ << std::endl; }
};

int main()
{
	int n = 0;
	Test<int> t;
	t.foo(10);
	t.foo(n);
	t.goo(10);
	t.goo(n);
}