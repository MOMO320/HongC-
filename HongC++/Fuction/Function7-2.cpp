#include <iostream>

using namespace std;

// ���� ���� �μ� ����
// Call By Value

// Call By Value�� �ܺο� ������ ���� �ʴ´�.

// �Լ� ���ڷ� �� ���� �� ���(call by value)
// �Ű� ���� ������ ����Ǹ鼭 �Ѱ��� ������ �ʱ�ȭ �ϰ� �ȴ�.
// �׷��鼭 �� ���簡 �Ͼ�� �Ǵ°� �̴�.
void doSomething(int y)	
{
	// doSomething�� �Լ��� ����Ǹ鼭 int y �� ����Ǹ鼭
	cout << " In func " << y << " " << &y << endl;
}

int main7_2()
{
	// y�� ���� �޸𸮿� �� 5�� �ʱ�ȭ�� �ȴ�.
	doSomething(5);

	int x = 6;	

	cout << " In main " << x << " " << &x << endl;

	// ������ ����'x'�� �Ѿ�� ���� �ƴ� ���� �Ѱ��ִ°�
	doSomething(x);	
	doSomething(x + 1);

	return 0;
}