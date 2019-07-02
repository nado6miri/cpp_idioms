// 4_thinTemplate - 237page

class VectorBase
{
protected :
	int size;
public :
	VectorBase(int sz) : size(sz) {}
	int getSize() const { return size; }
};


// 2개 타입에 대해 vector사용 -> 총 10개의 멤버 함수 생성됨. code bloat 현상
template<typename T> class Vector : public VectorBase
{
	T* buff;

public:
	Vector(int sz) : VectorBase(sz) { buff = new T[size]; }
	~Vector() { delete[] buff; }

	T& front() { return buff[0]; }
	T& last() { return buff[size - 1]; }
};

int main()
{
	Vector<int> v1(10);
	Vector<double> v2(10);
}