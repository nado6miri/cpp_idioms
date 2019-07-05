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

	Point<int> p1(1, 2); // �Ϲݻ�����
	Point<int> p2 = p1; // ��������� ok

	Point<double> p3 = p1; // error - �ٸ�Ÿ�԰��� ���� �Ұ�, ���� �����ڸ� ����� �� ����.

	// ������ int type�� double�� �� �� �ִ�. �׷� ������ ����� ����. 2�� ���Ϸ� �̵���.

}