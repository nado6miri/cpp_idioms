// 4_thinTemplate1 - 237 page

// 2개 타입에 대해 Vector사용 => 총 10개의 멤버 함수 생성.
template<typename T> class Vector
{
	T* buff;
	int  size;
public:
	Vector(int sz) : sz(size) { buff = new T[size]; }
	~Vector() { delete[] buff; }

	int getSize() const { return size; }
	T&  front() { return buff[0]; }
	T&  last() { return buff[size - 1]; }
};
int main()
{
	Vector<int>    v1(10);
	Vector<double> v2(10);
}

