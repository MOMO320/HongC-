#include <iostream>

using namespace std;

// 6-15.  ������ const

// const�� &�� ���̸� ��� ���� �׳� ���� �� �ִ�.(���� ���۷����� �ʱ�ȭ�� ������ �����ߴ�.)
void doSomething(const int& x)
{
	cout << "doSomething address : " << &x << "/ value : " << x << endl;
}

int main()
{
	int x = 5;
	const int &ref_x = x;	// �� ���� �Ұ���

	const int& ref_2 = ref_x;

	// ���ͷ�(���)�δ� �ʱ�ȭ�� ���� ������ const�� ���̸� �����ϴ�.
	// ����� ������ ���Ƿ� �ּҸ� �Ҵ��Ͽ� �ִ°� ����.
	const int& ref_v = 3 + 4;	
	cout << "in main address ref_v : " << &ref_v << endl;

	cout << "in main address x : " << &x << endl;
	doSomething(1);
	doSomething(x + 3);
	doSomething(3 * 4);

	return 0;
}