
template<typename T> struct Test
{
	typedef T type;
	template<typename U> struct Object {};
};

template<typename T> void foo(T a)
{
	// T�ȿ� type������ ���� n�� ����� ������.
	// T Object ""   o
	typename T::type n; // ok
	//typename T::Object<double> o; // error, Object�� ���ø��̶�� ����� �𸥴�. ���� �Ʒ��� ���� ���� �ʿ�
	typename T::template Object<double> o;
}

int main()
{
	Test<int>::type n;  // int n
	Test<int>::Object<double> o; // double o

	Test<int> t;
	foo(t);
}