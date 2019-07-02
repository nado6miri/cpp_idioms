// casting 3.cpp

/*
 reinterpret_cast 
 -  ptr <-> ptr
 -  ptr <-> ����
 -  ���δٸ� Ÿ�Կ� ���� ����
 -  �ַ� embedded programming�� �ʿ��� �� ���� - static_cast�� ������ ��쿡...
*/

int main()
{
	int n = 10;
	double *p1 = static_cast<double*>(&n); // error
	double *p2 = reinterpret_cast<double*>(&n); // OK

	// ���� -> ptr �� ������ case
	int *p3 = static_cast<int*>(10);  // error
 	int *p4 = reinterpret_cast<int*>(10); // ok 

	// ����
	char &r1 = static_cast<char&>(n); //error
	char &r2 = reinterpret_cast<char*>(n); // ok

	// ǥ�� Ÿ���� �� ���� ĳ����
	double d1 = n; //ok
 	double d2 = reinterpret_cast<double>(n); // ���� ���� ������.
}


// ��Ӱ� ĳ����
struct A { int a; }
struct B { int b; }
struct C : public A, public B { int c; }

int main()
{
	C cc;
	A* pA = &cc;
	B* pB = &cc;
	B* pB = (B*)&cc; // 1004

	// cc�� �ּҿ��� B�� ã�ƶ�. �����Ͻ�.. B�� ������ error, ������ B�� ��ġ �ּ� ��ȯ, �����Ͻ� ����, &cc + sizeof(A)
	B* pB = static_cast<B*>(&cc); // 1004

	// cc�� �ּҸ� ������ Bó�� �ؼ��ϰڴ�. �����Ͻ� ĳ���� ����, �޸� �� �ؼ�... pB->b = 100 �ϰ�� �ᱹ cc.a�� �ִ°��̴�. 
	B* pB = reinterpret_cast<B*>(&cc); // 1000 

	std::cout << &cc << std::endl; // 1000 ������� �Ҷ�
	std::cout << pA << std::endl;  // 1000
	std::cout << pB << std::endl;  // 1004
}
