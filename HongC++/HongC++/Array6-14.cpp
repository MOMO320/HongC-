#include <iostream>

using namespace std;

// 6-14. reference Variable ���� ����
/*
	reference : ������ �Ǵٸ� ���� �Ǵ� �̸�

	���� ����
	1. reference�� �ʱ�ȭ�� �ʼ� �̴�.
	2. �ʱ�ȭ�� ���ͷ� ���� �ȵǰ� ������ ������ �����ϴ�.

*/
int main6_14_1()
{
	int value = 5;
	int* ptr = nullptr;
	ptr = &value;


	int& ref = value;	// reference�� ������ �ٸ� ���� ������

	cout << ref << endl;

	ref = 10;

	cout << value << " " << ref << endl;
	cout << &value << endl;		// �׷��� ������ value�� ref�� �ּҰ� ����.(���۷����� ������ �ٸ� ���� �Ǵ� �̸� ������)
	cout << &ref << endl;
	cout << ptr << endl;
	cout << &ptr << endl;


	int x = 5;
	int& refX = x;			// reference�� ������ ���� �� ���� , ���ͷ��� ������ �ȵ�

	const int y = 8;
	const int& refY = y;	// �Ϲ������� �׳� ���۷����δ� �ȵǰ� const�� �־�� �Ѵ�.
	return 0;
}

void doSomething(int n)
{
	n = 10;
	cout << "In doSomething address : " << &n << "/ value : " << n<<endl;
}

void doSomethingRef(int& n)
{
	// ���۷����� �ѱ�� �Ǹ� �Լ� ������ �ּҰ� �Ѿ�ϴ�.(���� ��ü�� �Ѿ��.)
	// �׷��� ������ ȿ���� �� �����ϴ�.
	n = 20;
	cout << "In doSomethingRef address : " << &n << "/ value : " << n << endl;
}

int main6_14_2()
{

	int n = 5;
	
	cout << n << endl;	// n = 5;

	cout << "In main address: " << &n << endl;

	doSomething(n);
	
	cout << n << endl;	// n = 5;

	doSomethingRef(n);

	cout << n << endl; // n = 20;
	return 0;
}

void printElements(int (&arr)[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main6_14_3()
{
	const int length = 5;
	int arr[length] = { 1,2,3,4,5 };

	printElements(arr);
	return 0;
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};


int main6_14_4()
{
	Other ot;

	// �Ʒ��� ���� ���۷����� Ÿ�� ���� ������ �ּҸ� �޾Ƽ� ����ϸ� ȿ�����̴�.
	int &v1 = ot.st.v1;
	v1 = 1;

	return 0;
}


int main6_14_5()
{
	int value = 5;
	int* const ptr = &value;		// int *const ptr -> �ּ� ���� �Ұ��� �ϴ�.
	int& ref = value;

	// �Ѵ� ���� ���� �ϴ�.
	*ptr = 10;
	ref = 10;

	return 0;
}
