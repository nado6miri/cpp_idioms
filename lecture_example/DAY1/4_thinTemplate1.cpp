// 4_thinTemplate1 - 237 page
class Vector
{
	int* buff;
	int  size;
public:
	Vector(int sz) : sz(size) { buff = new int[size]; }
	~Vector() { delete[] buff; }

	int getSize() const { return size; }
	int&  front() { return buff[0]; }
	int&  last()  { return buff[size-1]; }
};
int main()
{
}

