// 2_상수멤버함수

class Rect
{
	int x = 0, y = 0, w = 10, h = 10; // C++11 부터 초기화가능
public:
	int getArea() const // 상수 멤버 함수
	{
		//x = 10; // error. 상수 멤버함수 안에서는 멤버값 변경안됨
		return w * h;
	}

	void setX(int a) { x = a; }
};
//void foo(Rect r) 
void foo(const  Rect& r)
{
	int n = r.getArea();
}

int main()
{
	//const Rect r; // 생성자로 초기화했다고 가정하고..
				// 상수 객체

	Rect r;
	foo(r);
	r.setX(100); // error

	int n = r.getArea();
			// 핵심 : 상수 객체는 상수 함수만 호출가능합니다.
			//       "객체의 상태를 변경하지 않는 
			//			모든 멤버함수(getter)는 반드시 
			//			상수 멤버 함수가 되어야 합니다."
}

