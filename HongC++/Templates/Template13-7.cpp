#include<iostream>
using namespace std;
// 포인터에 대한 템플릿 특수화
 
template<class T>
class A
{
private:
	T m_value;

public:
	A(const T input) : m_value(input)
	{

	}

	void print()
	{
		cout << m_value << endl;
	}
};

template<class T>
class A<T*>
{
private:
	T* m_value;

public:
	A(T* input) : m_value(input)
	{

	}

	void print()
	{
		cout << *m_value << endl;
	}
};

int main13_7()
{
	A<int> a_int(123);
	a_int.print();

	int temp = 456;

	A<int*> a_int_ptr(&temp);
	a_int_ptr.print();

	double temp_d = 3.15413;
	A<double*> a_double_ptr(&temp_d);
	a_double_ptr.print();

	return 0;
}