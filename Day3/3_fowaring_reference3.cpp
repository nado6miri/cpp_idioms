int main()
{
	int n = 10;
	int& r = n; // ok
//	int& & r2 = r;  // & & - c++���� reference��  reference�� ���� �ڵ�� ǥ���� �� ����. ������ �Ʒ�ó�� using / typedef �̿��ϸ� ������.

	using LREF = int&;
	using RREF = int&&;

	// reference  collapsing ��Ģ (�����ر�)
	LREF& ll = n ; // & & => &
	LREF&& lr = n ; // & && => &
	RREF& rl = n ; // && & => &
	RREF&& rr = 10 ; // && && => &&
}