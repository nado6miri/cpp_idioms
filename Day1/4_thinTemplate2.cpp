// 4_thinTemplate - 237page

// 2�� Ÿ�Կ� ���� vector��� -> �� 10���� ��� �Լ� ������. code bloat ����
template<typename T> class Vector
{
	T* buff;
	int size;

public:
	Vector(int sz) : size(sz) { buff = new T[size]; }
	~Vector() { delete[] buff; }

	int getSize() const { return size; }
	T& front() { return buff[0]; }
	T& last() { return buff[size - 1]; }
};

int main()
{
	Vector<int> v1(10);
	Vector<double> v2(10);
}