#include<iostream>
#include<type_traits>

// 코드 재확인 필요 - 안되네..?

struct Point
{
	int x;
	int y;
};

template<typename T, T> class check {};  // 타입을 하나 받고 타입에 해당하는 값을 받을게...

// check<int, 0> //
// check<<int Point::*, &Point::x>  // check 두번째 param 은 포인트의  멤버보내면 됨.

template<typename T> struct has_member_x
{
	typedef char YES[1];
	typedef short NO[2];

	template<typename U> static YES& test(check << int U::*, &U::x>* p);
	template<typename U> static NO& test(...);
	static constexpr bool value = (sizeof(test<T>(0)) == sizeof(YES));
};


int main()
{
	bool b = has_member_x<Point>::value;
	std::cout << b << std::endl;
}


