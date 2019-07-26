// casting3.cpp
// reinterpret_cast : ������ <-> ������
//		      ������ <-> ����
//		      ���� �ٸ� Ÿ�Կ� ���� ����
/*
int main()
{
	int n = 10;

	double* p1 = static_cast<double*>(&n); //error
	double* p2 = reinterpret_cast<double*>(&n); //ok

	// ���� => ������
	int* p3 = static_cast<int*>(10); // error
	int* p4 = reinterpret_cast<int*>(10); // ok

	// ����
	char& r1 = static_cast<char&>(n); // error
	char& r2 = reinterpret_cast<char&>(n); // ok

	// ǥ�� Ÿ���� ������ ĳ����
	double d1 = n; // ok
	double d2 = reinterpret_cast<double>(n); // error
}
*/
// ��Ӱ� ĳ����
struct A { int a; };
struct B { int b; };
struct C : pubic A, public B { int c; };

int main()
{
	C cc;

	A* pA = &cc;  	// 1000
//	B* pB = &cc;	// 1004
//	B* pB = (B*)&cc;// 1004

//	B* pB = static_cast<B*>(&cc);// 1004
			// cc�� �ּҿ��� B�� ã�ƶ�.
			// B�� ������ error. 
			// ������ B��ġ���ּ� ��ȯ
			// ������ �ð� ����.
			// &cc + sizeof(A)


	B* pB = reinterpret_cast<B*>(&cc);// 1000
			// cc �� �ּҸ� ������ Bó�� �ؼ��ϰڴ�.
			// �޸��� ���ؼ�!
			// ������ �ð� ĳ����

	pB->b = 100; // �ᱹ cc.a �� �ְ� �˴ϴ�.


	std::cout << &cc << std::endl; // 1000 �̶�� �Ҷ�
	std::cout << pA  << std::endl; // ?
	std::cout << pB  << std::endl; // ?
}
















