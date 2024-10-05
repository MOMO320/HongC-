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
	// 아래와 같이 하면은 호출한 함수의 단락이 끝나는 
	// 변수의 주소를 받아오기 때문에 문제가 발생 합니다.
	// 왜냐하면 단락이 종료되면 함수 내에 선언한 변수는 사라지기 때문입니다.
	//
	//int *value = getValuePtr(3);
	//cout << *value << endl; 

	int* array = allocateMemory(1024);
	delete[] array;

	int value = getValueRef(5);
	//int &value = getValueRef(5); -> 안좋은 방법

	cout <<"main : " << &value << endl;
	cout << value << endl;
	cout << value << endl;
	cout << value << endl;

	return 0;
}

// 배열안에 필요한 인덱스를 참조로 넘겨 받는 방법
int& get(std::array<int, 100>& my_array, int ix)
{
	return my_array[ix];
}

// return by reference 활용하는 방법
int main7_5_2()
{
	std::array<int, 100> my_array;
	my_array[30] = 10;

	//유용하게 많이 사용함
	// 배열안에 필요한 인덱스의 주소를 넘겨 받아 
	// 안에 있는 데이터를 변경하고 있다.
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

// tuple은 여러 반환값을 묶어서 내보내주는 컬렉션
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