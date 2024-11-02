#include <iostream>

using namespace std;

// ���ø� ��Ÿ ���α׷������� ������ Ÿ�� ��� ���� �ڵ� 2

// ¦���� Ȧ���� ���� �ٸ� ����� ��ȯ�ϴ� ���ø� ����ü
template<int N>
struct IsEven
{
	static const bool value = (N % 2 == 0);
};

// ���� N�� ���� �ٸ� �ڵ� ����
template<int N>
struct CheckEvenOdd
{
	static void print()
	{
		// ������ �ð��� ������ Ȯ��
		if constexpr (IsEven<N>::value)
		{
			cout << N << "is even." << endl;
		}
		else
		{
			cout << N << "is odd." << endl;
		}

	}
};

int mainTest2()
{
	CheckEvenOdd<5>::print();	// 5�� Ȧ���̹Ƿ� "5 is odd." ���	
	CheckEvenOdd<10>::print();	// 10�� ¦���̹Ƿ� "10 is even." ���
	return 0;
}

