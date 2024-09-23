#include <iostream>

using namespace std;

/*
	6-8. �����Ϳ� ���� �迭
*/

// �Լ� ���ڷ� array[]�� �Ѱ�������, ���������� �������̴�. 
// (int *array)�� ����. �ᱹ�� �����ͷ� ����ϰ� �ȴ�.
void printArray(int array[])
{
	cout << "sizeof printArray : " << sizeof(array) << endl;	// 8
	cout << *array << endl;

	*array = 100;	// �Լ��ȿ��� ������ �����ϴ�.(������ �ϴ°� �� ����.)
}

struct MyStruct
{
	int array[5] = { 9,7,5,3,1 };
};

void doSomething(MyStruct ms)
{
	cout << sizeof(ms.array) << endl;
}

// array�� class�� struct �ȿ� ���������� �����ͷ� ���� ��ȯ ���� �ʴ´�.
void doSomethingPtr(MyStruct* ms)
{
	//pointer�� �ƴ� array�� ���� �Ǳ� ������ sizeof���� 20�� ���´�.
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

	// ���� array�� �ᱹ�� �����ʹ�.
	int array[5] = {9,7,5,3,1};

	cout << "array sizeof : " << sizeof(array) << endl;	// 20

	int* aPtr = array;

	cout << "aPtr sizeof : " << sizeof(aPtr) << endl;	//8

	cout << array[0] << " " << array[1] << " " << array[2] << " " << array[3] << " " << array[4] << endl;
	cout << array << endl;		// array�� ù��° ���� �ּҸ� ������ ����
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

	// pointer ����
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