template<typename T> class Test
{
public:
	// �Ʒ� �ڵ�� forwarding reference �ϱ�� ?
	// �ƴմϴ�. Ŭ������ ���ø� ���� �Լ� ��ü�� ���ø��� �ƴմϴ�.
	// Ŭ���� ������ �̹� T�� Ÿ���� �����˴ϴ�.
	void foo(T&& arg) { }

	// �Ʒ� �ڵ尡 forwarding reference �Դϴ�.
	template<typename U> void goo(U&& arg) {}
};
int main()
{
	int n = 0;
	Test<int> t;
	t.foo(10);
	t.foo(n);
}