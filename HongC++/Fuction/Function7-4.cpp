#include <iostream>

using namespace std;
// �ּҿ� ���� �μ� ���� 
// call by Address

// ������ ������ ������.
// �׷��� ������ ���� ���� ������ �Ǿ� �Լ��� ȣ��ɶ� 
// ������ ���ڰ����� �ʱ�ȭ �Ͽ� �� ���簡 �Ͼ�� �ȴ�.
// ������ ���� �����̴�.
void foo(/*const*/ int* ptr)
{
	cout <<" In foo : " << *ptr << " " << ptr << " " << &ptr << endl;

	// call by referenceó�� ���ڷ� �Ѿ�� ���� ���� �� �� �ִ�.
	*ptr = 10;	// const�� ������ dereference�� ���� ���� �� �� �ִ�.
}

void foo(const double degrees, double* sin_out, double* cos_out)
{
	*sin_out = 1.0;
	*cos_out = 2.0;
}

void foo(int* arr, int length)
{
	arr[0] = 100;

	cout << *arr << endl;	// ù��° �μ�
	cout << arr << endl;	// �Ѱ��� �迭�� �ּ�
	cout << &arr << endl;	// int *arr�� �ּ�

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
	// foo(5);	�ּҰ� ���� ���ͷ��� ���ڷ� ���� �� ����. 

	double degrees = 30;
	double sin, cos;

	// �Լ����� �ٲ� ���� �ݿ��� �ȴ�.
	foo(degrees, &sin, &cos);
	
	cout << sin << " " << cos << endl;

	int arr[5]{ 1,2,3,4,5 };

	cout << "In main arr adress : " << &arr << endl;
	cout << arr << endl;

	foo(arr, 5);

	return 0;
}