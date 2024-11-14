#include <iostream>

using namespace std;

// ������-�� ����
// R-value References
// move semantics�� ����� �� �ִ��� �Ǻ�

int getResult()
{
	return 100 * 100;
}

// �����ε��� L-value�� R-value�� �ٸ��� ����� �� �ֵ��� ������ �ش�.
void doSomething(int& lref)
{
	cout << "L-value ref" << endl;
}

void doSomething(int&& ref)
{
	cout << "R-value ref" << endl;
}

int main15_2()
{
	// x�� �޸𸮸� ������ �ִ� ���̰�
	// 5�� ������ ������ ����� ���
	// : �� ����� r-value�� ���ʿ� l-value, 
	// �޸𸮸� �����ϰ� �ִ� ������ ������ �־ �� ���� ���
	// ���Ŀ� ����ϰڴٶ�� �ǹ�
	int x = 5;	
	int y = getResult();
	const int cx = 6;
	const int cy = getResult();

	// L-value references
	{
		int& lr1 = x;		// Modifiable l-values
		
		// ������ �ȵ�
		//int& lr2 = cx;	// Non-Modifiable l-values
		//int& lr3 = 5;		// R-values(R-value���� references�� ���� �� �ִ�.)

		const int& lr4 = x;		// Modifiable l-values
		const int& lr5 = cx;	// Non-Modifiable l-values
		const int& lr6 = 5;		// R-values(const�� �����ϴ�.)
	}

	// R-value references (R-value�� &�� �ΰ��� -> &&) -> Rvalue�� ���� �� �ִ�.
	{ // �� �ƴϸ� ��¥ ������ �� ����, �׸��� ���� ���� �ٲٰų� ���� ����� �� �־��� �ǹ�

		// ������ �ȵ�
		//int&& rr1 = x;		// Modifiable l-values
		//int&& rr2 = cx;		// Non-modifiable l-values
		int&& rr3 = 5;			// R-values (�� ������� �ֵ鸸 ���� �� �ִ�.)
		int&& rrr = getResult();
		
		cout << rr3 << endl;
		rr3 = 10;
		cout << rr3 << endl;

		// ������ �ȵ�
		//const int&& rr4 = x;	// Modifiable l-values
		//const int&& rr5 = cx;	// Non-modifiable l-values
		const int&& rr6 = 5;	// R-values
	}

	// L/R-value reference parameters
	doSomething(x);
	//doSomething(cx);
	doSomething(5);
	doSomething(getResult());

	return 0;
}