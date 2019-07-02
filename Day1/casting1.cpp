// casting1.cpp

// c style casting ������
int main()
{
	int n = 5;
	
	// c�� warning, c++ �� error  �߻�
	double *p = &n; 
	
	// c style casting - c/c++ ok
	// int �� 4 ����Ʈ, double�� 8 ����Ʈ�̱� ������ 4����Ʈ �Ҵ�� ������ 8����Ʈ�� access (Read/Write) �ϱ� ������ overrun �߻���. -  c style casting ��������.

	double *p = (double *) &n; 
	*p = 3.4;
}


// ������ 2
int main()
{
	const int c = 10;

	// read only ������ address��  p �� ����Ű���� ��. c������ warning,  c++ ������ error�߻�
	int *p = &c;

	// c style casting�ϸ� c/c++ ��� OK ��..
	int *p = (int *)&c;

	*p = 20;

	print("%d\n", c);  // undefined / compiler���� �ٸ�
	print("%d\n", *p); // 20
}


����� c style casting�� ��� ������ �� - ������ �ϰų� �����Ϸ����� �ٸ��� ������ �� ����.

���� c++���� 4���� type casting�� �������״� ���
