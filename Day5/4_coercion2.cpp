// 43 page

template<typename T> class Point
{
	T x, y;
public:
	Point(T a = T(), T b = T()) : x(a), y(b) {}

	// 복사생성자 (generic 복사 생성자)
	// member template임. --> class외부로 뽑아보자.
	// template<typename U> Point(const Point<U>& p) : x(p.x), y(p.y) {}
	// friend를 사용해서 공유되도록 함. U삭제 가능함 - 알려주기만 하면 됨.
	template<typename U> friend class Point;
};

// Class template의 멤버 템플릿의 외부 구현 - 이거 아래 코드 수정 필요  - 에러 남...
template<typename T> template<typename U>
Point<T>::Point(const Point<U>& p) : x(p.x), y(p.y) {}


int main()
{
	// 하지만 int type은 double에 들어갈 수 있다. 그럼 들어가도록 만들어 보자.
	Point<int> p1(1, 2); // 일반생성자
	Point<int> p2 = p1; // 복사생성자 ok
	Point<double> p3 = p1; // error - 다른타입간에 복사 불가, 복사 생성자를 사용할 수 없다. - 복사생성자를 만들자.


}