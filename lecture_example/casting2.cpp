// casting2.cpp
// C++ 스타일 캐스팅 1. static_cast

// 1. 연관성이 있는 타입 끼리의 캐스팅
// 2. 표준 타입을 값으로 캐스팅
// 3. void* => 다른 타입 캐스팅

int main()
{
	double d = 3.4;
	int n = static_cast<int>(d); // double => int : ok

	int* p1 = static_cast<int*>(&d);          // double*=>int* : error
	int* p2 = static_cast<int*>(malloc(100)); // void* => int* : ok     
	
	const int c = 10;
	int* p3 = static_cast<int*>(&c); // const int* => int* : error
}



