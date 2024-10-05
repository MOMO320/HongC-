#include <iostream>
#include <array>
#include <tuple>
using namespace std;

// return value
int  getValue(int x)
{
	int value = x;
	return value;
}

// return address
int* getValuePtr(int x)
{
	int value = x * 2;
	return &value;
}

int* allocateMemory(int size)
{
	return new int[size];
}

// return reference
int& getValueRef(int x)
{
	int value = x * 2;
	
	cout << "getValueRef : " << &value << endl;
	return value;
}

int main7_5_1()
{
	// �Ʒ��� ���� �ϸ��� ȣ���� �Լ��� �ܶ��� ������ 
	// ������ �ּҸ� �޾ƿ��� ������ ������ �߻� �մϴ�.
	// �ֳ��ϸ� �ܶ��� ����Ǹ� �Լ� ���� ������ ������ ������� �����Դϴ�.
	//
	//int *value = getValuePtr(3);
	//cout << *value << endl; 

	int* array = allocateMemory(1024);
	delete[] array;

	int value = getValueRef(5);
	//int &value = getValueRef(5); -> ������ ���

	cout <<"main : " << &value << endl;
	cout << value << endl;
	cout << value << endl;
	cout << value << endl;

	return 0;
}

// �迭�ȿ� �ʿ��� �ε����� ������ �Ѱ� �޴� ���
int& get(std::array<int, 100>& my_array, int ix)
{
	return my_array[ix];
}

// return by reference Ȱ���ϴ� ���
int main7_5_2()
{
	std::array<int, 100> my_array;
	my_array[30] = 10;

	//�����ϰ� ���� �����
	// �迭�ȿ� �ʿ��� �ε����� �ּҸ� �Ѱ� �޾� 
	// �ȿ� �ִ� �����͸� �����ϰ� �ִ�.
	get(my_array, 30) *= 10;

	cout << my_array[30] << endl;

	return 0;
}

struct S
{
	int a, b, c, d;
};

// return struct
S getStruct()
{
	S my_s{ 1,2,3,4 };
	return my_s;
}

int main7_5_3()
{
	S my_s = getStruct();
	my_s.b;

	return 0;
}

// tuple�� ���� ��ȯ���� ��� �������ִ� �÷���
tuple<int, double> getTuple()
{
	int a = 10;
	double d = 3.14;
	return std::make_tuple(a, d);
}

int main7_5()
{
	// c++ version 14
	//std::tuple<int, double> my_tp = getTuple();
	//int a = std::get<0>(my_tp);	// a
	//double b = std::get<1>(my_tp);	// d

	// c++ version 17
	auto [a, b] = getTuple();
	cout << a << endl;
	cout << b << endl;

	return 0;
}