#include <iostream>

using namespace std;

// ���ø� ��Ÿ ���α׷��� 
// 1. ������ �ð� ��� : ���α׷��� �Ϻθ� ������ �ð��� �̸� ����Ͽ�,
// ��Ÿ�ӿ����� ��� ����� ���Դϴ�.

// ���丮�� ����� ���� ���ø� ��Ÿ ���α׷���
// Factorial<N> ���ø� ����ü�� N�� 0�� �ƴ� �� ���丮�� ����� ��������� ���� �մϴ�.
template<int N>
struct Factorial
{
	static const int value = N * Factorial<N - 1>::value;
};

// ���� ����
// Factorial<0> Ư��ȭ�� ���ø��� ��� ȣ���� ���� ��������, 0!�� 1�� ���� �մϴ�.
template<>
struct Factorial<0>
{
	static const int value = 1;
};

int maintest1()
{
	std::cout << "Factorial of 5: " << Factorial<5>::value << endl;
	return 0;
}

