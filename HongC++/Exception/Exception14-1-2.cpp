#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
	14.1-2 예외처리의 기본


*/

int main14_1_2()
{
	// try, catch, throw
	// 주의 사항 : auto casting을 안해줌
	double x;
	cin >> x;

	try
	{
		if (x < 0.0) throw std::string("Negative input");

		cout << std::sqrt(x) << endl;
	}     
	catch (std::string error_message) // 예외 처리에서는 형변환을 엄격하게 한다.
	{
		//do something to respond
		cout << error_message << endl;
	}

	try
	{
		// something happend
		//throw - 1.0;
		throw "My error message";
	}
	catch (int x)	// double 데이터형이라 int로 예외처리하면 에러가 발생한다.
	{
		cout << "Catch interger " << x << endl;
	} 
	catch (double x)
	{
		cout << "Catch double " << x << endl;
	}
	catch (const char* error_message)
	{
		cout << "Char * " << error_message << endl;
	}
	return 0;
}