// 4_coercion    43 page
template<typename T> class Point
{
	T x, y;
public:
	Point(T a = T(), T b = T()) : x(a), y(b) {}
};
int main()
{
	Point<int> p1(1, 2);  // 일반 생성자
	Point<int> p2 = p1;   // 복사 생성자 ok

	Point<double> p3 = p1; // error
						// p3와 p1은 다른 타입이므로 
						// 복사 생성자를 사용할수 없다.
}