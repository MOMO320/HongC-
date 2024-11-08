#include<iostream>
using namespace std;
// ���ø��� �κ������� Ư��ȭ�ϱ�(Partical Speacializer)

template<class T, int size>
class StaticArray_BASE
{
private:
	T m_array[size];

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}

	void print()
	{
		for (int count = 0; count < size; ++count)
		{
			cout << (*this)[count] << ' ';
		}
		cout << endl;
	}

};

// ��� �Լ� spesicalizer �ϴ� ���
// ����� �̿���
template<class T, int size>
class StaticArray : public StaticArray_BASE<T,size>
{

};

// char���� Ư��ȭ ��
// ����� ���ؼ� ó�� �ϱ� ������ �ʿ��� �κи� ���� �����ؼ� ����� �� �ִ�.
template<int size>
class StaticArray<char,size> : public StaticArray_BASE<char, size>
{
public:
	void print()
	{
		for (int count = 0; count < size; ++count)
		{
			cout << (*this)[count];
		}
		cout << endl;
	}
};

// ���� ���� �ϳ��� speacializer�� ���ִ� ���
//template<int size>
//void print(StaticArray<char, size>& array)
//{
//	for (int count = 0; count < size; ++count)
//	{
//		cout << array[count];
//	}
//	cout << endl;
//}

int main13_6()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	int4.print();

	StaticArray<char, 14> char14;
	char14[0] = 'H';
	char14[1] = 'e';

	strcpy_s(char14.getArray(), 14, "Hello, world");

	char14.print();

	return 0;
}