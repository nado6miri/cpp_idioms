// casting 2.cpp

/*
 c style casting�� ������ ���� c++������ static_cast������. 
 �� static_cast�� �������� ���� �Ǵ� �͸� ����ϴ� ����
 1. �������� �ִ� Ÿ�Գ��� ĳ����
 2. ǥ�� Ÿ���� ������ ĳ����
 3. void* -> �ٸ� Ÿ������ ĳ����
*/

int main()
{
	double d = 3.4;

	// double -> int�� ������ : ok
	int n = static_cast<int>(d); 

	// double *�� int *�� ���� : error
	int *p1 = static_cast<int*>(&d);

	// void *�� int *�� ���� : ok
	int *p2 = static_cast<int*>(malloc(100));

	// const int *�� int *�� ���� : error
	const int c = 10;
	int *p3 = static_cast<int*>(&c);
}