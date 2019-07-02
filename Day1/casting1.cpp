// casting1.cpp

// c style casting 문제점
int main()
{
	int n = 5;
	
	// c는 warning, c++ 은 error  발생
	double *p = &n; 
	
	// c style casting - c/c++ ok
	// int 는 4 바이트, double은 8 바이트이기 때문에 4바이트 할당된 영역을 8바이트로 access (Read/Write) 하기 때문에 overrun 발생함. -  c style casting 문제점임.

	double *p = (double *) &n; 
	*p = 3.4;
}


// 문제점 2
int main()
{
	const int c = 10;

	// read only 영역의 address를  p 가 가리키도록 함. c에서는 warning,  c++ 에서는 error발생
	int *p = &c;

	// c style casting하면 c/c++ 모두 OK 임..
	int *p = (int *)&c;

	*p = 20;

	print("%d\n", c);  // undefined / compiler마다 다름
	print("%d\n", *p); // 20
}


결론은 c style casting은 사용 지양할 것 - 오동작 하거나 컴파일러마다 다르게 동작할 수 있음.

따라서 c++에서 4가지 type casting을 지원할테니 사용
