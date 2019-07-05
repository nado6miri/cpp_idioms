// 43 page

/*
class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}
};
*/
template<typename T> class Point
{
	T x, y;
public:
	Point(T a = T(), T b = T()) : x(a), y(b) {}
};


int main()
{
	//Point p1(3.4, 4.5);

	Point<int> p1(1, 2); // 일반생성자
	Point<int> p2 = p1; // 복사생성자 ok

	Point<double> p3 = p1; // error - 다른타입간에 복사 불가, 복사 생성자를 사용할 수 없다.

	// 하지만 int type은 double에 들어갈 수 있다. 그럼 들어가도록 만들어 보자. 2번 파일로 이동함.

}