#include <iostream>

using namespace std;

// 함수 포인터 활용 예제

void greet()
{
	cout << "Hello!" << endl;
}

void fareWell()
{
	cout << "Goodbye!" << endl;
}

void callFunction(void (*func)())
{
	// 전달 받은 함수 호출
	func();
}

int mainFunctionPtr1()
{
	callFunction(greet);	
	callFunction(fareWell);

	return 0;
}