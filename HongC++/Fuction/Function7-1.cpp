#include <iostream>

using namespace std;

// 7-1.�Ű������� �������� ����


int foo(int x, int y);

int foo(int x, int y)
{
	return x + y;
} // x and y are destroyed here


int main7_1()
{
	int x = 1, y = 2;

	foo(6, 7);	// 6, 7 : arguments (acutal parameters) // ������
	foo(x, y + 1);

	return 0;
}