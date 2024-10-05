#include <iostream>

using namespace std;
// 주소에 의한 인수 전달 
// call by Address

// 포인터 변수도 변수다.
// 그렇기 때문에 값에 의한 전달이 되어 함수가 호출될때 
// 변수가 인자값으로 초기화 하여 값 복사가 일어나게 된다.
// 포인터 또한 변수이다.
void foo(/*const*/ int* ptr)
{
	cout <<" In foo : " << *ptr << " " << ptr << " " << &ptr << endl;

	// call by reference처럼 인자로 넘어온 값을 변경 할 수 있다.
	*ptr = 10;	// const가 있으면 dereference한 값을 변경 할 수 있다.
}

void foo(const double degrees, double* sin_out, double* cos_out)
{
	*sin_out = 1.0;
	*cos_out = 2.0;
}

void foo(int* arr, int length)
{
	arr[0] = 100;

	cout << *arr << endl;	// 첫번째 인수
	cout << arr << endl;	// 넘겨준 배열의 주소
	cout << &arr << endl;	// int *arr의 주소

	for (int i = 0; i < length; ++i)
		cout << arr[i] << endl;

}

int main7_4()
{
	int value = 5;
	int* ptr = &value;

	cout << " In main value : " << value << " " << &value << endl;
	cout << " In main ptr : " << ptr << " " << &ptr << endl;	

	foo(&value);
	foo(ptr);
	// foo(5);	주소가 없는 리터럴은 인자로 넣을 수 없다. 

	double degrees = 30;
	double sin, cos;

	// 함수에서 바꾼 값이 반영이 된다.
	foo(degrees, &sin, &cos);
	
	cout << sin << " " << cos << endl;

	int arr[5]{ 1,2,3,4,5 };

	cout << "In main arr adress : " << &arr << endl;
	cout << arr << endl;

	foo(arr, 5);

	return 0;
}