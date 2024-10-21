#include <iostream>


using namespace std;

/*
	1. variadic templates
	: ���� ���� ���ø��� ����ϸ� �Լ��� �������� ���� ���ڸ� ���� �� �־��ϴ�.

*/

template<typename T>
void print(T value)
{
	std::cout << value << endl;
}

template<typename T, typename...Args>
void print(T value, Args... args)
{
	std::cout << value << ", ";
	print(args...);	// ���� ���ڵ��� ��������� ó��
}

int main1()
{
	print(1, 2.6, "Hello", 'A');

	return 0;
}