#include <iostream>
using namespace std;
// ����(Derived)�� Ŭ�������� ������ �ʱ�ȭ
 
class Mother
{
private:
	int m_i;
public:
	Mother(const int& i_in = 0)
		:m_i(i_in)
	{
		cout << "Mother construction" << endl;
	}
};

class Child :public Mother
{
public:
	double m_d;

public:
	Child()
		:m_d(1.0), Mother(1024)
	{
		cout << "Child construction" << endl;
	}
};

int main11_4_1()
{
	Child ch1;

	// child�� �θ��� �����ͱ��� �޸𸮸� ��� ������ �� ũ��.
	cout << sizeof(Mother) << endl;	// 4
	cout << sizeof(Child) << endl;	// 16


	return 0;
}

class A
{
public:
	A(int a)
	{
		cout << "A : " << a << endl;
	}
	~A()
	{
		cout << "Destructor A" << endl;
	}
};

class B : public A
{
public:
	B(int a, double b) : A(a)
	{
		cout << "B : " << b << endl;
	}
	~B()
	{
		cout << "Destructor B" << endl;
	}
};

class C : public B
{
public:
	C(int a, double b, char c) : B(a, b)
	{
		cout << "C : " << c << endl;
	}
	~C()
	{
		cout << "Destructor C" << endl;
	}
};

int main11_4()
{
	C c(1034, 3.14, 'a');

	return 0;
}

