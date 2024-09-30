#include <iostream>

using namespace std;

// 6-14. reference Variable 참조 변수
/*
	reference : 변수의 또다른 별명 또는 이름

	주의 사항
	1. reference는 초기화가 필수 이다.
	2. 초기화시 리터럴 값은 안되고 오로지 변수만 가능하다.

*/
int main6_14_1()
{
	int value = 5;
	int* ptr = nullptr;
	ptr = &value;


	int& ref = value;	// reference는 변수의 다른 별명 같은것

	cout << ref << endl;

	ref = 10;

	cout << value << " " << ref << endl;
	cout << &value << endl;		// 그렇기 때문에 value와 ref의 주소가 같다.(레퍼런스는 변수의 다른 별명 또는 이름 같은것)
	cout << &ref << endl;
	cout << ptr << endl;
	cout << &ptr << endl;


	int x = 5;
	int& refX = x;			// reference는 변수만 넣을 수 있음 , 리터럴은 넣으면 안됨

	const int y = 8;
	const int& refY = y;	// 일반적으로 그냥 레퍼런스로는 안되고 const를 넣어야 한다.
	return 0;
}

void doSomething(int n)
{
	n = 10;
	cout << "In doSomething address : " << &n << "/ value : " << n<<endl;
}

void doSomethingRef(int& n)
{
	// 레퍼런스로 넘기게 되면 함수 인자의 주소가 넘어갑니다.(변수 자체가 넘어간다.)
	// 그렇기 때문에 효율이 더 좋습니다.
	n = 20;
	cout << "In doSomethingRef address : " << &n << "/ value : " << n << endl;
}

int main6_14_2()
{

	int n = 5;
	
	cout << n << endl;	// n = 5;

	cout << "In main address: " << &n << endl;

	doSomething(n);
	
	cout << n << endl;	// n = 5;

	doSomethingRef(n);

	cout << n << endl; // n = 20;
	return 0;
}

void printElements(int (&arr)[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main6_14_3()
{
	const int length = 5;
	int arr[length] = { 1,2,3,4,5 };

	printElements(arr);
	return 0;
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};


int main6_14_4()
{
	Other ot;

	// 아래와 같이 레퍼런스로 타고 들어가는 변수의 주소를 받아서 사용하면 효율적이다.
	int &v1 = ot.st.v1;
	v1 = 1;

	return 0;
}


int main6_14_5()
{
	int value = 5;
	int* const ptr = &value;		// int *const ptr -> 주소 변경 불가능 하다.
	int& ref = value;

	// 둘다 변경 가능 하다.
	*ptr = 10;
	ref = 10;

	return 0;
}
