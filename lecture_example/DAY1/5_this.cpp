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
	p1.set(10, 20);  // set(&p1, 10, 20)의 의미로 전달 됩니다.
					// push 20
					// push 10		 진짜 인자는 스택으로
					// mov  ecx, &p1  객체 주소는 레지스터에
					// call Point::set
					
}


