// 8_enable_if 77page

template<bool b, typename T = void> struct enable_if
{
	typedef T type;
};

// �κ� Ư��ȭ�ÿ��� default���� ǥ������ �ʴ´�.
template<typename T> struct enable_if<false, T>
{
};


int main()
{
	// �Ʒ� �ڵ忡�� �� ������ Ÿ���� ���� ������.
	enable_if<true, int>::type n1; //int
	enable_if<true, double>::type n2; // double
	enable_if<true>::type n3;  // void�� ���� ���� �ȵ�.����

	// 1��° ���ڰ� false �ΰ�� type �� �����ϴ�.
	enable_if<false, int>::type n4; // type�� ���� error
	enable_if<false, double>::type n5; // error
	enable_if<false>::type n6; // error
}