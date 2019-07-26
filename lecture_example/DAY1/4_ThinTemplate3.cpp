// 4_thinTemplate1 - 237 page

// 템플릿 인자와 관련 없는 모든 멤버는 기반 클래스(템플릿이 아닌)로 제공한다.
class VectorBase
{
protected:
	int  size;
public:
	VectorBase(int sz) : size(sz) {}

	int getSize() const { return size; }
};

template<typename T> class Vector : public VectorBase
{
	T* buff;
public:
	Vector(int sz) : VectorBase(sz) { buff = new T[size]; }
	~Vector() { delete[] buff; }

	
	T&  front() { return buff[0]; }
	T&  last() { return buff[size - 1]; }
};
int main()
{
	Vector<int>    v1(10);
	Vector<double> v2(10);
}

