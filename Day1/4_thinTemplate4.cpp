// 4_thinTemplate - 237page

// 코드 size 를 줄이기 위해  thin template을 사용하지만 실제 처리는 template 함수에서 이루어 지기 때문에 실제 코드가 많이 안줄어 듬.
// 따라서 기초 클래스로 다 옮기고 실제 template class에서는 컴파일 단계에서 template 변환 처리만 하도록 하면 코드 사이즈가 줄어듬.
// android source 에서 platform_system_core/libutils/include/utils/Vector.h를 열어 보세요.

class VectorBase
{
protected:
	int size;
	void** buff;

public:
	VectorBase(int sz) : size(sz) { buff = new void*[sz];  }
	~VectorBase() { delete[] buff; }
	int getSize() const { return size; }
	void* front() { return buff[0]; }
	void* last() { return buff[size - 1]; }
};


// 2개 타입에 대해 vector사용 -> 총 10개의 멤버 함수 생성됨. code bloat 현상
template<typename T> class Vector : public VectorBase
{
public:
	Vector(int sz) : VectorBase(sz) { }
	T& front() { return static_cast<T&>(front()); }
	T& last() { return static_cast<T&>(last()); }
};

int main()
{
	Vector<int> v1(10);
	Vector<double> v2(10);
}