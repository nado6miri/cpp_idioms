
class Vector
{
public:
	//따라서 생성자 만들시 explicit 생성자 - 복사 초기화를 사용할 수 없다.직접 초기화만 가능하다.
	//생성자 만들때 가능하면 explicit를 붙이자.
	explicit Vector(int size) {}
};

void foo(Vector v) {} // foo(10) 호출시 Vector v = 10 로 됨 문제없이 동작하나 사용하지 말자... 

int main()
{
	Vector v1(10);  // 직접 초기화 direct initialization
	Vector v2 = 10; // copy initialization
	Vector v3{ 10 }; // direct initialization

	foo(v1); // ok
	foo(10); // explict를 사용하면 에러, 사용하지 많으면 ng 따라서 explict 를 쓰자.
}; 
