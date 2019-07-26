// casting2.cpp
// C++ ��Ÿ�� ĳ���� 1. static_cast

// 1. �������� �ִ� Ÿ�� ������ ĳ����
// 2. ǥ�� Ÿ���� ������ ĳ����
// 3. void* => �ٸ� Ÿ�� ĳ����

int main()
{
	double d = 3.4;
	int n = static_cast<int>(d); // double => int : ok

	int* p1 = static_cast<int*>(&d);          // double*=>int* : error
	int* p2 = static_cast<int*>(malloc(100)); // void* => int* : ok     
	
	const int c = 10;
	int* p3 = static_cast<int*>(&c); // const int* => int* : error
}



