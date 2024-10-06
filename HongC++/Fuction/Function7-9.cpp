#include <iostream>
#include <array>
#include <functional>	// c++ 11

using namespace std;

// �Լ� ������

int func()
{
	return 5;
}

int func(int x)
{
	return x;
}

int goo()
{
	return 10;
}

int main7_9_1()
{
	// �Լ��� �޸� �ּҰ� ��µȴ�.
	// �Լ� �����ε��� ��� �Ʒ��� ���� ȣ�� �� ��� �������� � �� ���� 
	// ���� ���� ���Ѵ�.
	//cout << func << endl;

	//��� �޸𸮿� �ִ� �ּ����� �˰� �� �ּҿ� �ִ� �Լ��� ȣ���ϴ°�
	// �Լ��� �ּҸ� ������ �ִ�.
	func();	

	// �Լ��� ������ ���� ���(�ʱ�ȭ)
	int (*fcnptr)() = func;
	int (*fcnptr2)(int) = func;	// �Ű����� �ִ� ��Ȳ
	cout << fcnptr() << endl;

	fcnptr = goo;

	cout << fcnptr() << endl;

	return 0;

}


bool isEven(const int& number)
{
	if (number % 2 == 0) return true;

	return false;
}

bool isOdd(const int& number)
{
	if (number % 2 != 0) return true;
	return false;
}


//typedef���� Ÿ�� ����
typedef bool (*check_fcn_t1)(const int&);
// using���� Ÿ�� ����
using check_fcn_t2 = bool (*)(const int&);

// �Լ� �����͸� �Ű������� �־� ��� �� �� �ִ�.(�׸��� default parameter�� �ʱ�ȭ �����ϴ�.)
// (typedef�� �Լ� �Ű����� �ޱ�)
void printNumbers(const array<int, 10>& my_array ,
	check_fcn_t1 check_fcn = isEven)
{
	for (auto& element : my_array)
	{
		if (check_fcn(element) == true) cout << element << " ";
	}
	cout << endl;
}

// functional�� �Լ� �Ű����� �ޱ�
void printNumbers1(const array<int, 10>& my_array,
	function<bool(const int&)> check_fcn)
{
	for (auto& element : my_array)
	{
		if (check_fcn(element) == true) cout << element << " ";
	}
	cout << endl;
}


int main7_9()
{
	std::array<int, 10> my_array = { 0,1,2,3,4,5,6,7,8,9 };

	// �Լ��� �̸� ��ü�� �������̱� ������ & ������ �ʾƵ� �ȴ�.
	printNumbers(my_array);
	printNumbers(my_array,isOdd);

	std::function<bool(const int&) > fcnptr = isEven;

	printNumbers1(my_array, fcnptr);

	fcnptr = isOdd;

	printNumbers1(my_array, fcnptr);
	return 0;
}