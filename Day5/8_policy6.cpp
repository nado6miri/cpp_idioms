template<typename T> struct MyAlloc {};

// Mordern C++ Designå - �ȵ巹�� �˷���巹��ť  

template<typename T, 
	int N,
	typename<typename> class AT>
class Test
{
	AT a; // error, AT�� Ÿ���� �ƴ� ���ø� �Դϴ�.
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
	//AT ax; // error. AT�� ���ø�
	//AT<T> ax; // MyAlloc<int>
	AT<Node> ax; // MyAlloc<Node>
};


int main()
{
	//List<int, MyAlloc<int>> s; // type����...

	List<int, MyAlloc> s; // MyAlloc - Ʋ ����
}