// 5_this

class Point
{
	int x, y;
public:
	void set(int a, int b) // set(Point* this, int a, int b)
	{
		x = a;			// this->x = a
		y = b;			// this->y = b;
	}
	void print() const   // print( const Point* this)
	{
		x = 10;		// this->x = 10; // error
	}
};
int main()
{
	Point p1, p2;
	p1.print();
	p1.set(10, 20);  // set(&p1, 10, 20)�� �ǹ̷� ���� �˴ϴ�.
					// push 20
					// push 10		 ��¥ ���ڴ� ��������
					// mov  ecx, &p1  ��ü �ּҴ� �������Ϳ�
					// call Point::set
					
}


