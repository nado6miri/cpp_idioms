
template<typename T> struct Test
{
	typedef T type;
	template<typename U> struct Object {};
};

template<typename T> void foo(T a)
{
	// T안에 type형태의 변수 n을 만들어 보세요.
	// T Object ""   o
	typename T::type n; // ok
	//typename T::Object<double> o; // error, Object가 템플릿이라는 사실을 모른다. 따라서 아래와 같이 수정 필요
	typename T::template Object<double> o;
}

int main()
{
	Test<int>::type n;  // int n
	Test<int>::Object<double> o; // double o

	Test<int> t;
	foo(t);
}