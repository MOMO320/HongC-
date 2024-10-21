#include <iostream>
#include <cstdarg>

using namespace std;

void print(int count, ...)
{
	va_list args;
	va_start(args, count);	// args 초기화

	cout << "갯수 : " << count << endl;

	for (int i = 0; i < count; ++i)
	{
		cout << va_arg(args, int) << ", ";	// 인자 가져오기
	}

	va_end(args);	//args 종료
	cout << endl;
}

int main2()
{
	print(4, 1, 2, 4, 10);
	return 0;
}