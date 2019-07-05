template<typename T> struct MyAlloc {};

// Mordern C++ Design책 - 안드레이 알렉산드레스큐  

template<typename T, 
	int N,
	typename<typename> class AT>
class Test
{
	AT a; // error, AT는 타입이 아닌 템플릿 입니다.
	AT<T> ax;
};


Test<int, 10, MyAlloc> t; 


template<typename T> struct MyAlloc {};

/*
template<typename T, typename Ax) class List
{

};
*/

template<typename T, typename<typename> class AT> class List
{
	//AT ax; // error. AT는 템플릿
	//AT<T> ax; // MyAlloc<int>
	AT<Node> ax; // MyAlloc<Node>
};


int main()
{
	//List<int, MyAlloc<int>> s; // type전달...

	List<int, MyAlloc> s; // MyAlloc - 틀 전달
}