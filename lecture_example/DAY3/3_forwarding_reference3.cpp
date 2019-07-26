int main()
{
	int n = 10;
	int& r = n;    //ok
//	int& & r2 = r; // error. reference 의 reference를					
					// 직접 코드로 표현할수 없다.

	using LREF = int&;
	using RREF = int&&;

	// 레퍼런스 붕괴(reference collapsing) 규칙
	LREF&  ll = n ; // & & => &
	LREF&& lr = n ; // & && => &
	RREF&  rl = n ; // && & => &
	RREF&& rr = 10 ; // && && => &&
}