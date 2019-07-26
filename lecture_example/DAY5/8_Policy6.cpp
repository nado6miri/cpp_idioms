/*
template<typename T, 
		 int N,
		 template<typename> class AT > 
class Test 
{
	//AT a; // error. AT 는 타입이 아닌 템플릿 입니다.
	AT<T> ax;

};

Test<int, 10, MyAlloc >  t;
*/
	   	 

template<typename T> struct MyAlloc {};

/*
template<typename T, typename Ax> class List
{
	// Node 의 Allocator가 필요.!
};
*/
// Modern C++ Design 책 - 안드레이 알렉산드레스큐
template<typename T, template<typename> class AT> class List
{
	struct Node {};

//	AT ax; // error. AT 는 템플릿
//	AT<T> ax; // MyAlloc<int> 
	AT<Node> ax; // MyAlloc<Node>
};

int main()
{
	//List<int, MyAlloc<int>> s;

	List<int, MyAlloc > s;
}





