// ����
template<typename T> struct Test
{
	typedef T type;
	template<typename U> struct Object {};
};
template<typename T> void foo(T a)
{
	// T�ȿ� type ������ ���� n ����� ������.
	// T     Object ""      o
	typename T::type n;
	//typename T::Object<double> o; // error. Object ��			
								// ���ø� �̶�� ����� �𸥴�.
	typename T::template Object<double> o; // ok
}
int main()
{
	Test<int>::type n;  // int
	Test<int>::Object<double> o;

	Test<int> t;
	foo(t);
}
