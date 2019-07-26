// 참고
template<typename T> struct Test
{
	typedef T type;
	template<typename U> struct Object {};
};
template<typename T> void foo(T a)
{
	// T안에 type 형태의 변수 n 만들어 보세요.
	// T     Object ""      o
	typename T::type n;
	//typename T::Object<double> o; // error. Object 가			
								// 템플릿 이라는 사실을 모른다.
	typename T::template Object<double> o; // ok
}
int main()
{
	Test<int>::type n;  // int
	Test<int>::Object<double> o;

	Test<int> t;
	foo(t);
}
