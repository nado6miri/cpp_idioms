// casting1.cpp
// C ��Ÿ�� ĳ������ ������ 1
/*
int main()
{
	int n = 5;
	//double* p = &n;   // C��� ���,  C++ : ������ ����
	double* p = (double*)&n; // C style ĳ���� ok.
			// �� ĳ������ �ʹ� �����մϴ�.
	*p = 3.4;
}
*/
// ������ 2.
int main()
{
	const int c = 10;
	//c = 20;
	//int* p = &c;  // C���, C++ ����

	int* p = (int*)&c;  // C style ĳ�����ϸ� ok.

	*p = 20; // ok

	printf("%d\n", c); // 10 ? 20
	printf("%d\n", *p);// 20
}













