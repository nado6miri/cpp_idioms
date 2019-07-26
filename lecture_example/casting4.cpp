// casting4.cpp

int main()
{
	const int c = 10;

	// 상수성을 제거하는 캐스팅	
	int* p1 = static_cast<int*>(&c); // error

	int* p2 = reinterpret_cast<int*>(&c); // error
				// 상수성을 제거할수 없다

	int* p3 = const_cast<int*>(&c); // ok


	volatile int n = 10;
	int* p4 = static_cast<int*>(&n); // error
	int* p5 = const_cast<int*>(&n);  // ok

	// const_cast : const 속성과 volatile 속성 제거
}

// 질문. 아래 코드 완성해 보세요
int main()
{
	const int c = 10;

//	char* p = &c; // error. 

	// c의 주소를 char* 에 담아 보세요.- C++ 캐스팅 사용

	char* p =  reinterpret_cast<char*>( 
			const_cast<int*>(&c));

	char* p = (char*)&c; // ok.. C 스타일 캐스팅.

}
//dynamic_cast<>


















