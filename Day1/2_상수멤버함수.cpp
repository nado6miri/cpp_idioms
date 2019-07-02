// 2_상수 멤버함수

class Rect
{
	int x = 0, y = 0, w = 10, h = 10; // c++11부터 초기화 가능함
public:
	// 상수 멤버함수 - 함수 내에서 값을 변경하면 에러임.
	int getArea() const
	{
		// x = 10; // error - 상수 멤버함수라 값을 변경하면 안됨.
		return w * h;
	}

	void setX(int a) { x = a; }
};

int main()
{

	Rect r; // 생성자로 초기화 되었다고 가정하고...
	int n = r.getArea();

	// 상수 객체는 멤버 함수 호출 불가 -  부를 수 있게 하려면 상수 멤버 함수를 컴파일러에게 알려주기 위해 const를 붙여 줘야 함.(선언부에)
	const Rect r1; // 생성자로 초기화 되었다고 가정하고...
	//r1.setX(100); // error
}