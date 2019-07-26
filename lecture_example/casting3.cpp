// casting3.cpp
// reinterpret_cast : 포인터 <-> 포인터
//		      포인터 <-> 정수
//		      서로 다른 타입에 대한 참조
/*
int main()
{
	int n = 10;

	double* p1 = static_cast<double*>(&n); //error
	double* p2 = reinterpret_cast<double*>(&n); //ok

	// 정수 => 포인터
	int* p3 = static_cast<int*>(10); // error
	int* p4 = reinterpret_cast<int*>(10); // ok

	// 참조
	char& r1 = static_cast<char&>(n); // error
	char& r2 = reinterpret_cast<char&>(n); // ok

	// 표준 타입의 값형식 캐스팅
	double d1 = n; // ok
	double d2 = reinterpret_cast<double>(n); // error
}
*/
// 상속과 캐스팅
struct A { int a; };
struct B { int b; };
struct C : pubic A, public B { int c; };

int main()
{
	C cc;

	A* pA = &cc;  	// 1000
//	B* pB = &cc;	// 1004
//	B* pB = (B*)&cc;// 1004

//	B* pB = static_cast<B*>(&cc);// 1004
			// cc의 주소에서 B를 찾아라.
			// B가 없으면 error. 
			// 있으면 B위치의주소 반환
			// 컴파일 시간 수행.
			// &cc + sizeof(A)


	B* pB = reinterpret_cast<B*>(&cc);// 1000
			// cc 의 주소를 무조건 B처럼 해석하겠다.
			// 메모리의 재해석!
			// 컴파일 시간 캐스팅

	pB->b = 100; // 결국 cc.a 에 넣게 됩니다.


	std::cout << &cc << std::endl; // 1000 이라고 할때
	std::cout << pA  << std::endl; // ?
	std::cout << pB  << std::endl; // ?
}
















