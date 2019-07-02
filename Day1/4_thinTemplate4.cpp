// 4_thinTemplate - 237page

// �ڵ� size �� ���̱� ����  thin template�� ��������� ���� ó���� template �Լ����� �̷�� ���� ������ ���� �ڵ尡 ���� ���پ� ��.
// ���� ���� Ŭ������ �� �ű�� ���� template class������ ������ �ܰ迡�� template ��ȯ ó���� �ϵ��� �ϸ� �ڵ� ����� �پ��.
// android source ���� platform_system_core/libutils/include/utils/Vector.h�� ���� ������.

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


// 2�� Ÿ�Կ� ���� vector��� -> �� 10���� ��� �Լ� ������. code bloat ����
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