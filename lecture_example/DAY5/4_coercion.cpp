// 4_coercion    43 page
template<typename T> class Point
{
	T x, y;
public:
	Point(T a = T(), T b = T()) : x(a), y(b) {}
};
int main()
{
	Point<int> p1(1, 2);  // �Ϲ� ������
	Point<int> p2 = p1;   // ���� ������ ok

	Point<double> p3 = p1; // error
						// p3�� p1�� �ٸ� Ÿ���̹Ƿ� 
						// ���� �����ڸ� ����Ҽ� ����.
}