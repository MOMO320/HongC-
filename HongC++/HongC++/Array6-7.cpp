#include <iostream>
#include <typeinfo>
using namespace std;

int* doSomething(int* ptr_a)
{
	return nullptr;
}

struct something
{
	int a, b, c, d;
};

int main()
{
	int x = 5;

	cout << x << endl;
	cout << &x << endl;
	cout << (int)&x << endl;

	// de-reference operator (*)
	// de-reference는 포인터가 "저쪽 주소에 가면 이 데이터가 있어요."라고
	// 간접적으로 가리키기만 하는 것에 대해서,
	// "그럼 거기에 진짜 뭐가 있는지 내가 들여다볼께" 라며 직접적으로 접근하겠다는 의미입니다.

	cout <<  *(&x) << endl;

	// pointer는 변수이다.
	// 메모리 주소를 담는 변수 이다.

	//typedef int* pint;
	 int *ptr_x = &x , *ptr_y = &x;	// pointer에 변수의 주소를 넣어 줍니다.
	//pint ptr_x = &x, ptr_y = &x;

	 cout << ptr_x << endl; // x의 주소를 가지고 있음
	 cout << *ptr_x << endl;	// pointer의 de-reference를 하여 주소에 있는 값을 가져옴

	/*
		- pointer를 가져오는 이유

		1).array 때문에 pointer가 아닌 일반적으로 데이터를 가져오면 전체 복사를 하게 되어
		  쓸데 없이 메모리를 차지 하게 되는데, pointer를 사용하면 array의 첫번째 주소값을
		  받고 사이즈를 알게 되면 array의 데이터가 있는 주소에 접근하여 직접적으로 값을 사용 
		  할 수 있어 메모리를 아낄 수 있습니다.

		2). 변수를 여기저기 사용해야 할 상황에서 매번 복사하는것 보다, 포인터를 통해 변수의 
		    주소를 보내면 메모리를 아낄 수 있습니다.
	*/

	 double d = 123.0;

	 //*ptr_y = &d;	//error! type이 다름

	 double* ptr_d = &d;
	 
	 cout << ptr_d << endl;
	 cout << *ptr_d << endl;

	 cout << sizeof(x) << endl;
	 cout << sizeof(d) << endl;
	 cout << sizeof(&x) << " "  << sizeof(ptr_x)<< endl; // pointer의 메모리의 사용량은 (64bit)일 경우 8바이트 사용한다.
	 cout << sizeof(&d) << " " << sizeof(ptr_d) << endl; // pointer의 메모리의 사용량은 (64bit)일 경우 8바이트 사용한다.

	 something ss;
	 something* ptr_s;

	 cout << sizeof(something) << endl;
	 cout << sizeof(ptr_s) << endl;


#pragma region typeInfo 사용법
	 {
		 int x = 5;
		 double d = 123.0;

		 int* ptr_x = &x;

		cout << typeid(ptr_x).name() << endl;
		 
	 }

#pragma endregion

#pragma region pointer문제점(초기화 안된 포인터 변수 사용으로 인한)
	 {
		 int x = 5;

		 int* ptr_x;

		 // 초기화 안된 pointer를 호출 하고 있어 문제가 발생한다.
		 //cout << *ptr_x << endl;
	 }
#pragma endregion

	return 0;
}