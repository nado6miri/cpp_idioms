// casting4.cpp

int main()
{
	const int c = 10;

	// ������� �����ϴ� ĳ����	
	int* p1 = static_cast<int*>(&c); // error

	int* p2 = reinterpret_cast<int*>(&c); // error
				// ������� �����Ҽ� ����

	int* p3 = const_cast<int*>(&c); // ok


	volatile int n = 10;
	int* p4 = static_cast<int*>(&n); // error
	int* p5 = const_cast<int*>(&n);  // ok

	// const_cast : const �Ӽ��� volatile �Ӽ� ����
}

// ����. �Ʒ� �ڵ� �ϼ��� ������
int main()
{
	const int c = 10;

//	char* p = &c; // error. 

	// c�� �ּҸ� char* �� ��� ������.- C++ ĳ���� ���

	char* p =  reinterpret_cast<char*>( 
			const_cast<int*>(&c));

	char* p = (char*)&c; // ok.. C ��Ÿ�� ĳ����.

}
//dynamic_cast<>


















