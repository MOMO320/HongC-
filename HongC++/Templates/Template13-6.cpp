#include<iostream>
using namespace std;
// 템플릿을 부분적으로 특수화하기(Partical Speacializer)

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

// 멤버 함수 spesicalizer 하는 방법
// 상속을 이용함
template<class T, int size>
class StaticArray : public StaticArray_BASE<T,size>
{

};

// char형만 특수화 함
// 상속을 통해서 처리 하기 때문에 필요한 부분만 새로 정의해서 사용할 수 있다.
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

// 인자 둘중 하나만 speacializer를 해주는 방법
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
