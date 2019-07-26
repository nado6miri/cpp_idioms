// casting1.cpp
// C 스타일 캐스팅의 문제점 1
/*
int main()
{
	int n = 5;
	//double* p = &n;   // C언어 경고,  C++ : 컴파일 에러
	double* p = (double*)&n; // C style 캐스팅 ok.
			// 이 캐스팅은 너무 위험합니다.
	*p = 3.4;
}
*/
// 문제점 2.
int main()
{
	const int c = 10;
	//c = 20;
	//int* p = &c;  // C경고, C++ 에러

	int* p = (int*)&c;  // C style 캐스팅하면 ok.

	*p = 20; // ok

	printf("%d\n", c); // 10 ? 20
	printf("%d\n", *p);// 20
}













