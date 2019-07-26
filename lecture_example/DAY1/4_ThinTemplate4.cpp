// 4_thinTemplate1 - 237 page

// void* 기반 컨테이너.!
class VectorBase
{
protected:
	int  size;
	void** buff;
public:
	VectorBase(int sz) : size(sz) { buff = new void*[sz]; }
	~VectorBase() { delete[] buff; }

	int getSize() const { return size; }
	
	void* front() { return buff[0]; }
	void* last()  { return buff[size-1]; }
};

// android 소스에서
// platform_system_core/libutils/include/utils/Vector.h 열어 보세요.
template<typename T> class Vector : public VectorBase
{
public:
	Vector(int sz) : VectorBase(sz) {}

	T&  front() { return static_cast<T&>(buff[0]); }
	T&  last() { return static_cast<T&>(buff[size - 1]); }
};

int main()
{
	Vector<int>    v1(10);
	Vector<double> v2(10);
}


// shared_ptr<int> sp(new int) : ok
//					// 참조 계수를 스마트 포인터가 관리

// AutoPtr<int> sp(new int) :  error
				// 
// AutoPtr<Car> sp(new Car) :  ok
//					// 참조 계수를 객체가 관리.