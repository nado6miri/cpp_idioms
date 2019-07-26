#include <iostream>

struct Point
{
	int x;
	int y;
};
int main()
{
	int n = 0;
	int* p1 = &n;	 // ok.
	//int* p2 = &Point::y; // error 
	int Point::*p2 = &Point::y; // ok.. 멤버 의 주소
								// pointer to member
	//std::cout << p2 << std::endl; // 4 의미 그런데, 1

	printf("%d\n", p2); // 4

	Point pt;
	pt.*p2 = 10; // 결국 p2.y = 10 과 같은 의미.
				// .* : pointer to member operator

	p2 = &Point::x;
	//p2 = p2 + 1; // 

}



