// 43 page

template<typename T> class Point
{
	T x, y;
public:
	Point(T a = T(), T b = T()) : x(a), y(b) {}

	// ��������� (generic ���� ������)
	// member template��. --> class�ܺη� �̾ƺ���.
	// template<typename U> Point(const Point<U>& p) : x(p.x), y(p.y) {}
	// friend�� ����ؼ� �����ǵ��� ��. U���� ������ - �˷��ֱ⸸ �ϸ� ��.
	template<typename U> friend class Point;
};

// Class template�� ��� ���ø��� �ܺ� ���� - �̰� �Ʒ� �ڵ� ���� �ʿ�  - ���� ��...
template<typename T> template<typename U>
Point<T>::Point(const Point<U>& p) : x(p.x), y(p.y) {}


int main()
{
	// ������ int type�� double�� �� �� �ִ�. �׷� ������ ����� ����.
	Point<int> p1(1, 2); // �Ϲݻ�����
	Point<int> p2 = p1; // ��������� ok
	Point<double> p3 = p1; // error - �ٸ�Ÿ�԰��� ���� �Ұ�, ���� �����ڸ� ����� �� ����. - ��������ڸ� ������.


}