#include <iostream>

using namespace std;

// 함수 try

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
	// 생성자에서 예외처리 함수 사용하는 방법
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
		// throw;  // throw를 안했지만 throw가 된다.(생성자에서 할땐 re-throw가 된다.)	
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
	{	// 생성자에서 예외 함수를 사용하면 함수 내에서
		//catch를 해도 한번 더 re-throw가 된다.
		cout << "Catch in main() " << endl;
	}

	return 0;
}
