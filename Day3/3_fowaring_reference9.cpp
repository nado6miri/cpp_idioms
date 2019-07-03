
// class�� ���ø�.  foo�� ���ø��� �ƴ�.
template<typename T> class Test
{
public:
	// �Ʒ� �ڵ�� forwarding reference�ϱ��? - forwarding reference �ƴ� - class�� ���ø�.  foo�� ���ø��� �ƴ�.
	// class ������ �̹� T type�� �����˴ϴ�.
	void foo(T&& arg) { std::cout << __FUNCSIG__ << std::endl; }

	// �Ʒ� �ڵ尡 forwarding reference �Դϴ�.
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