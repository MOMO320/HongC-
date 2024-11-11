#include <iostream>

using namespace std;

// 14.2 ����ó���� ���� �ǰ��� (Stack Unwinding)

//(���ܸ� ���� ���ɼ��� �ִ� �Լ���.��� ǥ��)
void last() throw(int) //intŸ���� exception�� �� ���� �ִ�
{
	// void last() throw() <-- ó�� throw ��ȣ�ȿ� ������ Ÿ���� ������
	// ���ܸ� ������ �ʴ´ٰ� ���� �ߴٰ� �����մϴ�.

	cout << "last " << endl;
	cout << "Throws exception" << endl;

	throw 'a';
	cout << "end last" << endl;
}


void third()
{
	cout << "Third" << endl;
	last();

	cout << "end Third" << endl;
}

void second()
{
	cout << "Second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "Second caught double exception" << endl;
	}

	cout << "End second" << endl;
}

void first()
{
	cout << "first" << endl;

	try
	{
		second();
	}
	catch (double)
	{
		cerr << "first caught int exception" << endl;
	}

	cout << "End first" << endl;
}

int main14_2()
{	
	cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		// std::cerr , std::clog , std::cout
		cerr << "main caught int eception" << endl;
	}
	catch (...)	//catch-all handlers (ellipses)// �� ��� ����ó��
	{
		cerr << "main caught ellipses exception" << endl;
	}
	


	cout << "End main" << endl;

	return 0;
}