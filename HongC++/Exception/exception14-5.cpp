#include <iostream>

using namespace std;

// �Լ� try

class A
{
private:
	int m_x;
public:
	A(int x) : m_x(x)
	{
		if (x <= 0)
			throw 1;
	}

};

class B : public A
{
	// �����ڿ��� ����ó�� �Լ� ����ϴ� ���
public:
	//B(int x)
	//	: A(x)
	//{

	//}
	B(int x) try : A(x)
	{
		//do initialization
	}
	catch (...)
	{
		cout << "Catch in B constructor" << endl;
		// throw;  // throw�� �������� throw�� �ȴ�.(�����ڿ��� �Ҷ� re-throw�� �ȴ�.)	
	}
};


void doSomething()
try {
	throw - 1;
}
catch (...)
{
	cout << "Catch in doSomething()" << endl;
}

int main14_5()
{
	try
	{
		//doSomething();
		B b(0);
	}
	catch (...)
	{	// �����ڿ��� ���� �Լ��� ����ϸ� �Լ� ������
		//catch�� �ص� �ѹ� �� re-throw�� �ȴ�.
		cout << "Catch in main() " << endl;
	}

	return 0;
}
