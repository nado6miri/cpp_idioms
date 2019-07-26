// 2_explicit

class Vector
{
public:
	// explicit 생성자 : 복사 초기화를 사용할수 없다.
	//					직접 초기화만 가능하다.
	explicit Vector(int size) {}
};
void foo(Vector v) {} // Vector v = 10
					// Vector v = v1

int main()
{
	Vector v1(10);  // direct initialization
	//Vector v2 = 10; // copy initialization
	Vector v3{ 10 }; // direct

	foo(v1); // ok
	foo(10); // ?
}






