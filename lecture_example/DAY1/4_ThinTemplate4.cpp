// 4_thinTemplate1 - 237 page

// void* ��� �����̳�.!
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

// android �ҽ�����
// platform_system_core/libutils/include/utils/Vector.h ���� ������.
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
//					// ���� ����� ����Ʈ �����Ͱ� ����

// AutoPtr<int> sp(new int) :  error
				// 
// AutoPtr<Car> sp(new Car) :  ok
//					// ���� ����� ��ü�� ����.