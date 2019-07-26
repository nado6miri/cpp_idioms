int main()
{
	int n = 10;
	int& r = n;    //ok
//	int& & r2 = r; // error. reference �� reference��					
					// ���� �ڵ�� ǥ���Ҽ� ����.

	using LREF = int&;
	using RREF = int&&;

	// ���۷��� �ر�(reference collapsing) ��Ģ
	LREF&  ll = n ; // & & => &
	LREF&& lr = n ; // & && => &
	RREF&  rl = n ; // && & => &
	RREF&& rr = 10 ; // && && => &&
}