// casting 2.cpp

/*
 c style casting이 문제가 많아 c++에서는 static_cast제공함. 
 즉 static_cast는 논리적으로 말이 되는 것만 허용하는 것임
 1. 연관성이 있는 타입끼리 캐스팅
 2. 표준 타입을 값으로 캐스팅
 3. void* -> 다른 타입으로 캐스팅
*/

int main()
{
	double d = 3.4;

	// double -> int로 변경함 : ok
	int n = static_cast<int>(d); 

	// double *를 int *로 변경 : error
	int *p1 = static_cast<int*>(&d);

	// void *를 int *로 변경 : ok
	int *p2 = static_cast<int*>(malloc(100));

	// const int *를 int *로 변경 : error
	const int c = 10;
	int *p3 = static_cast<int*>(&c);
}