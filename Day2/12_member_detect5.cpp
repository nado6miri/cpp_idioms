#include <iostream>

// member variable detection

struct Point
{
	int x;
	int y;
};

int main()
{
	// Point의 객체를 만들지는 않았음...따라서 Point의 구조체에서 offset 을 얻어옴.

	int n = 0;
	int* p1 = &n;  // OK
	//int* p2 = &Point::y;   // error
	int Point::*p2 = &Point::x;   // OK...  멤버의 x주소 -   pointer to member
	int Point::*p3 = &Point::y;   // OK...  멤버의 y주소 -   pointer to member

	std::cout << p2 << std::endl; // 0 의미, 그런데 1이 나옴. - cout을 사용하지 말고  printf를 써야 제대로 나옴
	printf("%d\n", p2); // 4

	std::cout << p3 << std::endl; // 4 의미, 그런데 1이 나옴. - cout을 사용하지 말고  printf를 써야 제대로 나옴
	printf("%d\n", p3); // 4

	Point pt;
	pt.*p2 = 10; // pt.x = 10과 같은 의미임. - .* : pointer to member operator

}