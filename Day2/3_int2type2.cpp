#include<iostream>
#include<type_traits>

template<typename T> void printv(T a)
{
	if (std::is_pointer<T>::value)  //포인터 인지 조사 - 컴파일할때 알고 있다. true 인지 false 인지...
	{
		std::cout << a << " : " << *a << std::endl;
	}
	else
	{
		std::cout << a << std::endl;
	}
}

int main()
{
	int n = 0;
	printv(n); // 1 - error 
	printv(&n); // 2
}

// ? 채워보세요. 왜 컴파일 에러일까요? - 컴파일러에서 if(false) 로 이미 알고 있지만  if문은 runtime문이기 때문에 코드 포함시키다 보니 에러 발생함.
// 1, 2중 어느곳이 문제일까요? 1번