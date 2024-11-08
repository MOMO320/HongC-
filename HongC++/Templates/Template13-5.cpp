#include <iostream>
#include <array>
#include "Storage8.h"
// Ŭ���� ���ø� Ư��ȭ
using namespace std;

template<typename T>
class A
{
public:
	A(const T& input) {}
	void doSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void test()
	{}
};

// Ŭ���� ���ø� Ư��ȭ
// ���ø��� ���������� ���� �����ϰ� �ϴ� ����̴�.
template <>
class A<char>
{
public:
	A(const char& temp) {}
	void doSomething()
	{
		cout << "Char type specialization" << endl;
	}
};
int main13_5_1()
{
	A<int> a_int(1);
	A<double> a_double(3.14);
	A<char> a_char('a');

	a_int.test();
	a_double.test();
	//a_char.test();	// �ٸ� Ŭ������� �����ϸ� �ȴ�.

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	return 0;
}

int main13_5_2()
{
	Storage8<int> intStorage;

	for (int count = 0; count < 8; ++count)
	{
		intStorage.set(count, count);
	}

	for (int count = 0; count < 8; ++count)
	{
		cout << intStorage.get(count) << endl;
	}

	cout << "Sizeof Storage8<int> " << sizeof(Storage8<int>) << endl;

	// Define a Storage8 for bool
	Storage8<bool> boolStorage;
	for (int count = 0; count < 8; ++count)
	{
		boolStorage.set(count, count &3);
	}

	for (int count = 0; count < 8; ++count)
		cout << (boolStorage.get(count)? "true" : "false") << endl;

	cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << endl;

	return 0;
}
