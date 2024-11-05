// 함수 템플릿 특수화(Specialization)
#include <iostream>
#include "Storage.h"
using namespace std;

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

// char형 템플릿 특수화 작업
//template< >
//char getMax(char x, char y)
//{
//	cout << "Warning : comparing chars " << endl;
//
//	return (x > y) ? x : y;
//}

int main13_4_1()
{
	cout << getMax(1, 2) << endl;
	cout << getMax<double>(1, 2) << endl;
	cout << getMax('a', 'b') << endl;

	return 0;
}

int main13_4()
{
	Storage<int> nValue(5);
	Storage<double> dValue(7.5);

	nValue.print();
	dValue.print();
 
	return 0;
}