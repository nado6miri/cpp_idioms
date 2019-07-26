// int2type5.cpp

// 템플릿 인자로는 "타입" 뿐 아니라 "정수"를 보낼수도 있습니다.
template<int N> struct int2type    // 115 page 코드입니다.
{
	enum { value = N};
};
int main()
{
	foo(0);
	foo(1); // 0, 1은 같은 타입. foo(0),foo(1)는 동일한 함수호출
	int2type<0> t0;
	int2type<1> t1;
	foo(t0);
	foo(t1); // t0, t1 는 다른 타입. foo(t0), foo(t1)은 
			// 다른 함수 호출.
}