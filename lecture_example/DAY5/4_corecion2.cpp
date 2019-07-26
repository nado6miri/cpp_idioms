// 4_coercion    43 page
template<typename T> class Point
{
	T x, y;
public:
	Point(T a = T(), T b = T()) : x(a), y(b) {}

	// generic (����) ������
//	template<typename U>
//	Point(const Point<U>& p) : x(p.x), y(p.y) {}

	template<typename U>
	Point(const Point<U>& p);

	template<typename> friend class Point;
};
// Ŭ���� ���ø��� ��� ���ø��� �ܺ� ����
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