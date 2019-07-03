int main()
{
	int n = 10;
	int& r = n; // ok
//	int& & r2 = r;  // & & - c++에서 reference의  reference를 직접 코드로 표현할 수 없다. 하지만 아래처럼 using / typedef 이용하면 가능함.

	using LREF = int&;
	using RREF = int&&;

	// reference  collapsing 규칙 (참조붕괴)
	LREF& ll = n ; // & & => &
	LREF&& lr = n ; // & && => &
	RREF& rl = n ; // && & => &
	RREF&& rr = 10 ; // && && => &&
}