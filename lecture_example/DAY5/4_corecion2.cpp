// 4_coercion    43 page
template<typename T> class Point
{
	T x, y;
public:
	Point(T a = T(), T b = T()) : x(a), y(b) {}

	// generic (복사) 생성자
//	template<typename U>
//	Point(const Point<U>& p) : x(p.x), y(p.y) {}

	template<typename U>
	Point(const Point<U>& p);

	template<typename> friend class Point;
};
// 클래스 템플릿의 멤버 템플릿의 외부 구현
template<typename T> template<typename U>
Point<T>::Point(const Point<U>& p) : x(p.x), y(p.y)
{
}




int main()
{
	Point<int> p1(1, 2);  
	Point<int> p2 = p1;   


	Point<double> p3 = p1; 
}