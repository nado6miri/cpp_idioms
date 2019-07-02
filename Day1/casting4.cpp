// casting 4.cpp

/*
 const_cast�� const / volatile�Ӽ��� �����ϱ� ���� ����Ѵ�.
*/

int main()
{
	const int c = 10;

	// ������� �����ϴ� ĳ����
	int *p1 = static_cast<int*>(&c); //error

	// ���δٸ� Ÿ���� ĳ������ �Ǵµ� ������� ������ �� ����.
	int *p2 = reinterpret_cast<int*>(&c); //error

	// 
	int *p3 = const_cast<int*>(&c); // ok

	volatile int n = 10;
	int *p4 = static_cast<int*>(&n); // error
	int *p4 = const_cast<int*>(&n); // ok
}


// ���� - �Ʒ� �ڵ带 �ϼ��� ������.

int main()
{
	const int c = 10;
	//char *p = &c; // error

	// c�� �ּҸ� char*�� ��� ������ - c++ casting���
	char *p = reinterpret_cast<char*>(const_cast<int*>(&c)); // char *p = (char*)&c; c style�����ڴ� �̷��� ���� ���..... ���� defect ���Ÿ� ���� c++ ��Ȯȭ �Ͽ� ĳ���� �ʿ�.
}