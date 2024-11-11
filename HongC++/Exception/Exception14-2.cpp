#include <iostream>

using namespace std;

// 14.2 예외처리와 스택 되감기 (Stack Unwinding)

//(예외를 던질 가능성이 있는 함수다.라는 표현)
void last() throw(int) //int타입의 exception을 할 수도 있다
{
	// void last() throw() <-- 처럼 throw 괄호안에 데이터 타입이 없으면
	// 예외를 던지지 않는다고 지정 했다고 생각합니다.

	cout << "last " << endl;
	cout << "Throws exception" << endl;

	throw 'a';
	cout << "end last" << endl;
}


void third()
{
	cout << "Third" << endl;
	last();

	cout << "end Third" << endl;
}

void second()
{
	cout << "Second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "Second caught double exception" << endl;
	}

	cout << "End second" << endl;
}

void first()
{
	cout << "first" << endl;

	try
	{
		second();
	}
	catch (double)
	{
		cerr << "first caught int exception" << endl;
	}

	cout << "End first" << endl;
}

int main14_2()
{	
	cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		// std::cerr , std::clog , std::cout
		cerr << "main caught int eception" << endl;
	}
	catch (...)	//catch-all handlers (ellipses)// 못 잡는 예외처리
	{
		cerr << "main caught ellipses exception" << endl;
	}
	


	cout << "End main" << endl;

	return 0;
}