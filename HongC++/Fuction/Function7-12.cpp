#include <iostream>

using namespace std;

// ����� �Լ� ȣ�� (Recursive Function Call)
// �ڱⰡ �ڱ⸦ ȣ���ϴ� �Լ�
// ��� �Լ��� �ʹ� ��ư� �������� ���� ������ ����� ���ϴ� ��� ���� ���´�.

/*
	�� ���ð� ��� �Լ��� ���ü�
	: ��� �Լ��� ������ ������ ������ �ֽ��ϴ�.
	  ��� �Լ��� �Լ��� �ڱ� �ڽ��� ȣ���ϸ鼭 ȣ�� ������ ���ÿ� �����ϰ�,
	  ȣ���� �Ϸ�Ǹ� ���� ȣ�� ������ ������ ���� ���·� ���ư��ϴ�.
	  ������ ��� �Լ��� ȣ������� �����ϴµ� ���Ǹ�,
	  ��� �Լ��� �����ϰ� ������ϴµ� ������ �ݴϴ�.

*/ 


void countDown(int count)
{
	cout << count << endl;

	// ��� �Լ��� ȣ�� �Ҷ��� ���� ������ �־�� �մϴ�.
	
	if (count > 0) 
		countDown(count - 1);

}

int value = 0;
static int sum = 0;
int total = 0;
int sumTo(int sumto)
{
	++value;
	if (sumto <= 0)
		return 0;
	else if (sumto <= 1)
		return 1;
	else
	{	
		// ������ �ڵ�
		// return sumTo(sumto -1) +sumto;

		sum = sumTo(sumto - 1);
		total = sum + sumto;
		// ���ȣ���� ��� �Լ��� ȣ���� �� ���� ������ return �ؼ� �ϳ��� ���� ���� �մϴ�.
		return sum + sumto;
	}
}

// ��� �Լ��� �̿��� �� ���ϱ� (1���� n����)
int recursiveSum(int n)
{
	if (n <= 1)
		return 1;
	else
		return n + recursiveSum(n - 1);
}

// 0, 1, 2 , 3 , 5, 8, 13, 21 ... (���� �տ� ���� ���ϴ°� �Ǻ���ġ �����̶�� �Ѵ�.)
// ���� § �ڵ� �ƴ�(������ �� �𸣰���.. .�ƹ��� ����)
int fibonacci(int n)
{
	if (n <= 1)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

// ���丮�� ���ϱ�
// ���丮���� ���� n! = n*(n-1)!
int factorial(int n)
{
	int value = 0;
	cout << "factorial(" << n << ")";
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		value = n * factorial(n - 1);
		return value;
	}
}


int main7_12()
{
	//countDown(5);

	//cout << sumTo(10) << endl;
	cout << fibonacci(6) << endl;

	//cout << factorial(3) << endl;

	//cout << recursiveSum(3) << endl;

	return 0;
}