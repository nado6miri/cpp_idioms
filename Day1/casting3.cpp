// casting 3.cpp

/*
 reinterpret_cast 
 -  ptr <-> ptr
 -  ptr <-> 정수
 -  서로다른 타입에 대한 참조
 -  주로 embedded programming시 필요할 때 있음 - static_cast로 에러날 경우에...
*/

int main()
{
	int n = 10;
	double *p1 = static_cast<double*>(&n); // error
	double *p2 = reinterpret_cast<double*>(&n); // OK

	// 정수 -> ptr 를 변경한 case
	int *p3 = static_cast<int*>(10);  // error
 	int *p4 = reinterpret_cast<int*>(10); // ok 

	// 참조
	char &r1 = static_cast<char&>(n); //error
	char &r2 = reinterpret_cast<char*>(n); // ok

	// 표준 타입의 값 형식 캐스팅
	double d1 = n; //ok
 	double d2 = reinterpret_cast<double>(n); // 값대 값은 에러임.
}


// 상속과 캐스팅
struct A { int a; }
struct B { int b; }
struct C : public A, public B { int c; }

int main()
{
	C cc;
	A* pA = &cc;
	B* pB = &cc;
	B* pB = (B*)&cc; // 1004

	// cc의 주소에서 B를 찾아라. 컴파일시.. B가 없으면 error, 있으면 B의 위치 주소 반환, 컴파일시 수행, &cc + sizeof(A)
	B* pB = static_cast<B*>(&cc); // 1004

	// cc의 주소를 무조건 B처럼 해석하겠다. 컴파일시 캐스팅 수행, 메모리 재 해석... pB->b = 100 일경우 결국 cc.a에 넣는것이다. 
	B* pB = reinterpret_cast<B*>(&cc); // 1000 

	std::cout << &cc << std::endl; // 1000 번지라고 할때
	std::cout << pA << std::endl;  // 1000
	std::cout << pB << std::endl;  // 1004
}
