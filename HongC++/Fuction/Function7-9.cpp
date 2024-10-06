#include <iostream>
#include <array>
#include <functional>	// c++ 11

using namespace std;

// 함수 포인터

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
	// 함수의 메모리 주소가 출력된다.
	// 함수 오버로딩의 경우 아래와 같이 호출 할 경우 컴파일이 어떤 걸 고를지 
	// 결정 하지 못한다.
	//cout << func << endl;

	//어느 메모리에 있는 주소인지 알고 그 주소에 있는 함수를 호출하는것
	// 함수도 주소를 가지고 있다.
	func();	

	// 함수의 포인터 선언 방법(초기화)
	int (*fcnptr)() = func;
	int (*fcnptr2)(int) = func;	// 매개변수 있는 상황
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


//typedef으로 타입 선언
typedef bool (*check_fcn_t1)(const int&);
// using으로 타입 선언
using check_fcn_t2 = bool (*)(const int&);

// 함수 포인터를 매개변수로 넣어 사용 할 수 있다.(그리고 default parameter로 초기화 가능하다.)
// (typedef로 함수 매개변수 받기)
void printNumbers(const array<int, 10>& my_array ,
	check_fcn_t1 check_fcn = isEven)
{
	for (auto& element : my_array)
	{
		if (check_fcn(element) == true) cout << element << " ";
	}
	cout << endl;
}

// functional로 함수 매개변수 받기
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

	// 함수는 이름 자체가 포인터이기 때문에 & 붙이지 않아도 된다.
	printNumbers(my_array);
	printNumbers(my_array,isOdd);

	std::function<bool(const int&) > fcnptr = isEven;

	printNumbers1(my_array, fcnptr);

	fcnptr = isOdd;

	printNumbers1(my_array, fcnptr);
	return 0;
}