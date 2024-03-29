// 8_enable_if 77page

template<bool b, typename T = void> struct enable_if
{
	typedef T type;
};

// 부분 특수화시에는 default값을 표기하지 않는다.
template<typename T> struct enable_if<false, T>
{
};


int main()
{
	// 아래 코드에서 각 변수의 타입을 적어 보세요.
	enable_if<true, int>::type n1; //int
	enable_if<true, double>::type n2; // double
	enable_if<true>::type n3;  // void는 변수 선언 안됨.에러

	// 1번째 인자가 false 인경우 type 은 없습니다.
	enable_if<false, int>::type n4; // type이 없어 error
	enable_if<false, double>::type n5; // error
	enable_if<false>::type n6; // error
}