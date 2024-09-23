#include <iostream>

using namespace std;

/*
	6-8. 포인터와 정적 배열
*/

// 함수 인자로 array[]를 넘겨주지만, 실질적으론 포인터이다. 
// (int *array)랑 같다. 결국엔 포인터로 사용하게 된다.
void printArray(int array[])
{
	cout << "sizeof printArray : " << sizeof(array) << endl;	// 8
	cout << *array << endl;

	*array = 100;	// 함수안에서 변경이 가능하다.(참조로 하는게 더 좋다.)
}

struct MyStruct
{
	int array[5] = { 9,7,5,3,1 };
};

void doSomething(MyStruct ms)
{
	cout << sizeof(ms.array) << endl;
}

// array가 class나 struct 안에 들어있을경우 포인터로 강제 변환 되지 않는다.
void doSomethingPtr(MyStruct* ms)
{
	//pointer가 아닌 array로 전달 되기 때문에 sizeof값이 20이 나온다.
	cout << "(*ms).array : " << sizeof((*ms).array) << endl;	// sizeof : 20

	cout << " ms->array : " <<  sizeof(ms->array)<< endl;		// sizeof : 20
}

void test(int& data)
{
	data = 100;
}

void testPtr(int* data)
{
	*data = 200;
}
int main6_8_1() // 6_8_1
{

	// 정적 array도 결국엔 포인터다.
	int array[5] = {9,7,5,3,1};

	cout << "array sizeof : " << sizeof(array) << endl;	// 20

	int* aPtr = array;

	cout << "aPtr sizeof : " << sizeof(aPtr) << endl;	//8

	cout << array[0] << " " << array[1] << " " << array[2] << " " << array[3] << " " << array[4] << endl;
	cout << array << endl;		// array의 첫번째 값의 주소를 가지고 있음
	cout << &array[0] << endl;

	cout <<"*array : " << *array << endl;

	char name[] = "jackjack";
	cout << "*name : " << *name << endl;
	cout << "name : " <<name << endl;

	int* ptr = nullptr;
	cout << ptr << endl;
	cout << &ptr << endl;

	ptr = array;
	
	cout << ptr << endl;
	cout << &ptr << endl;

	cout << *ptr << endl;
	cout << &ptr << endl;

	printArray(array);

	cout << array[0] << " " << *array << endl;

	// pointer 연산
	cout << *ptr << " " << *(ptr + 1) << endl;

	return 0;
}

int main6_8_2()
{
	MyStruct ms;
	cout << ms.array[0] << endl;

	cout << sizeof(ms.array) << endl;

	doSomething(ms);
	doSomethingPtr(&ms);
	return 0;
}

int main6_8_test()
{
	int a = 10;

	test(a);

	cout << "test : " << a << endl;

	testPtr(&a);

	cout << "testPtr : " << a << endl;

	int* ptr = &a;

	cout << "&a : " << &a << endl;
	cout << "ptr : " << ptr << endl;
	cout << "&ptr : " << &ptr << endl;
	cout << "*ptr : " << *ptr << endl;
	//cout << "**ptr : " << *(*ptr) << endl;
	return 0;
}