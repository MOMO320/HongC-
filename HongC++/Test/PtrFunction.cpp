#include <iostream>

using namespace std;

// �Լ� ������ Ȱ�� ����

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
	// ���� ���� �Լ� ȣ��
	func();
}

int mainFunctionPtr1()
{
	callFunction(greet);	
	callFunction(fareWell);

	return 0;
}