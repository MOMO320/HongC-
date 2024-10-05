#include <iostream>

using namespace std;

// 7-1.매개변수와 실인자의 구분


int foo(int x, int y);

int foo(int x, int y)
{
	return x + y;
} // x and y are destroyed here


int main7_1()
{
	int x = 1, y = 2;

	foo(6, 7);	// 6, 7 : arguments (acutal parameters) // 실인자
	foo(x, y + 1);

	return 0;
}