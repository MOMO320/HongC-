#include<iostream>

using namespace std;

// 예외 클래스와 상속

class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "Array exception" << endl; 
	}
};

class MyArray
{
private:
	int m_data[5];

public:
	// 멤버 함수에서도 exepction을 할 수 있다.
	int& operator[] (const int& index)
	{
		if (index < 0 || index >= 5)
		{
			ArrayException e;
			cout << "MyArray 객체 생성 : " << &e << endl;
			throw e;
		}

		return m_data[index];
	}
};

void doSomething14_3()
{
	MyArray my_array;

	try
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cerr << "Exception" << x << endl;
	}
	//catch (ArrayException& e)
	//{
	//	cout << "doSomething()" << endl;
	//	e.report();
	//	throw e;	// re-throw 하면 main에 있는 catch가 받는다.
	//}
	catch (Exception& e)
	{
		cout << "doSomething() :" ;
		cout << &e << endl;
		e.report();
		throw;
	}

}

int main14_3()
{
	try
	{
		doSomething14_3();
	}
	catch(ArrayException& e)
	{
		cout << "main() ArrayException : " ;
		cout << &e << endl;
		e.report();
	}
	catch (Exception& e)
	{
		cout << "main() Exception : ";
		cout << &e << endl;
		e.report();
	}


	return 0;
}