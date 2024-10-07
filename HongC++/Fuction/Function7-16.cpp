#include <iostream>
#include <cstdarg>	// for ellipsis
using namespace std;

// ������ȣ Ellipsis

// argument�� ������ ���� �ȴ�.
double findAverage(int count, ...)
{
	double sum = 0;
	
	// char * = va_list
	va_list list;

	// count - �Ű������� ��� �˷��ִ� ��
	va_start(list, count);

	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int);

	va_end(list);

	return sum / count;
}

int main()
{
	cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl;		// 1
	cout << findAverage(3, 1, 2, 3) << endl;					// 2
	cout << findAverage(5, 1, 22, 39, 41, 52) << endl;			// 3
	cout << findAverage(10, 1, 2, 3, 4, 5) << endl;

	return 0;
}