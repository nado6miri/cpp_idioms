#include <iostream>
#include <type_traits>

// pointer를 제외한 type
// typename std::remove_pointer<T>::type t;

// 위 코드가 복잡함. 따라서 c++14부터 아래 코드를 제공함
template<typename T> using remove_pointer_t = typename std::remove_pointer<T>::type;

// C++ 17옵션 - variable template라는 문법임.
template<typename T> bool is_pointer_v = std::is_pointer<T>::valule;

std::remove_

template<typename T> void foo(T a)
{
	bool b = std::is_pointer<T>::valule;
	//bool b = std::is_pointer_v<T>; // 위를 간단히...

	// pointer를 제외한 type
	//typename std::remove_pointer<T>::type t;  // 복잡해서 아래 c++14 style로...
	remove_pointer_t<T> t;
}

int main()
{
	int n;
	foo(&n);
}