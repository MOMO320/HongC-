#include <iostream>

using namespace std;

class ATest;

class BTest
{
public:
	void somePrint(ATest& _a);
};

class ATest
{
private:
	int m_value;
	void doSomething()
	{
		cout << "doSomething()" << endl;
	}

	friend void print(ATest& a);
	friend void BTest::somePrint(ATest& _a);
};


void BTest::somePrint(ATest &_a)
{
	_a.doSomething();
}

// �Լ��� friend Ű���带 �̿��� ����
void print(ATest& a)
{
	cout << a.m_value << endl;
}

void testDown();
void testUp()
{
	cout << "testUp" << endl;
}

int main2()
{
	testUp();
	testDown();


	return 0;
}

void testDown()
{
	cout << "testDown" << endl;
}