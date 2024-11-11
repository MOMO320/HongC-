#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
	14.1-2 ����ó���� �⺻


*/

int main14_1_2()
{
	// try, catch, throw
	// ���� ���� : auto casting�� ������
	double x;
	cin >> x;

	try
	{
		if (x < 0.0) throw std::string("Negative input");

		cout << std::sqrt(x) << endl;
	}     
	catch (std::string error_message) // ���� ó�������� ����ȯ�� �����ϰ� �Ѵ�.
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
	catch (int x)	// double ���������̶� int�� ����ó���ϸ� ������ �߻��Ѵ�.
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