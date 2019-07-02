// casting 4.cpp

/*
 const_cast는 const / volatile속성을 제거하기 위해 사용한다.
*/

int main()
{
	const int c = 10;

	// 상수성을 제거하는 캐스팅
	int *p1 = static_cast<int*>(&c); //error

	// 서로다른 타입의 캐스팅은 되는데 상수성은 제거할 수 없다.
	int *p2 = reinterpret_cast<int*>(&c); //error

	// 
	int *p3 = const_cast<int*>(&c); // ok

	volatile int n = 10;
	int *p4 = static_cast<int*>(&n); // error
	int *p4 = const_cast<int*>(&n); // ok
}


// 질문 - 아래 코드를 완성해 보세요.

int main()
{
	const int c = 10;
	//char *p = &c; // error

	// c의 주소를 char*에 담아 보세요 - c++ casting사용
	char *p = reinterpret_cast<char*>(const_cast<int*>(&c)); // char *p = (char*)&c; c style개발자는 이렇게 쓰면 쉬운데..... 잠재 defect 제거를 위해 c++ 명확화 하여 캐스팅 필요.
}