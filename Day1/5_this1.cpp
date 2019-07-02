// 5_this

class Point
{
	int x = 0;
	int y = 0;

public :
	void set(int a, int b)  // set(Point* this, int a, int b)
	{
		x = a;		// this->x = a
		y = b;		// this->y = b
	}

	void print() const  // print(const Point* this)
	{
		x = 10;		// const this->x = 10  ------ error 
	}
};

int main()
{
	Point p1, p2;
	p1.set(10, 20);  // set(&p1, 10, 20)의 의미로 전달됩니다. push 20; push 10; mov ecx, &p1; call Point::set
}