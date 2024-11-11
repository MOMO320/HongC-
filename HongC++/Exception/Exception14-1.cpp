#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ���� ó���� �⺻(Exception Handling)
/*
	�� ����ó���� �ϴ� ��Ȳ
	- ���� ���� ���� ���
	- ������ �� ���� ��Ȳ�� ������
*/

int findFirstChar(const char* string, char ch)
{
	for (std::size_t index = 0; index < strlen(string); ++index)
	{
		if (string[index] == ch)
			return index;
	}

	return -1;	// no match
}

double divide(int x, int y, bool& success)
{
	if (y == 0)
	{
		success = false;
		return 0.0;
	}

	success = true;
	return static_cast<double>(x) / y;
}

int main14_1_1()
{
	bool success;	// flag ������ �������
	double result = divide(5, 3, success);

	// bool ������ flag ������ ���� ���������� 
	// �ڵ尡 �۵��ߴ��� ����ó���� ���ݴϴ�.
	if (!success)
		std::cerr << "An error occurred" << std::endl;
	else
		std::cout << "Result is " << result << std::endl;

	
	std::ifstream input_file("temp.txt");
	// pointer�� nullptr���� Ȯ������ üũ �մϴ�.
	if (!input_file)	
		std::cerr << "Cannot open file" << std::endl;

	return 0;
}