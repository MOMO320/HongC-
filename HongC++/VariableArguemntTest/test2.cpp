#include <iostream>
#include <cstdarg>

using namespace std;

void print(int count, ...)
{
	va_list args;
	va_start(args, count);	// args �ʱ�ȭ

	cout << "���� : " << count << endl;

	for (int i = 0; i < count; ++i)
	{
		cout << va_arg(args, int) << ", ";	// ���� ��������
	}

	va_end(args);	//args ����
	cout << endl;
}

int main2()
{
	print(4, 1, 2, 4, 10);
	return 0;
}