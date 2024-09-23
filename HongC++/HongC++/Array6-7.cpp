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
	// de-reference�� �����Ͱ� "���� �ּҿ� ���� �� �����Ͱ� �־��."���
	// ���������� ����Ű�⸸ �ϴ� �Ϳ� ���ؼ�,
	// "�׷� �ű⿡ ��¥ ���� �ִ��� ���� �鿩�ٺ���" ��� ���������� �����ϰڴٴ� �ǹ��Դϴ�.

	cout <<  *(&x) << endl;

	// pointer�� �����̴�.
	// �޸� �ּҸ� ��� ���� �̴�.

	//typedef int* pint;
	 int *ptr_x = &x , *ptr_y = &x;	// pointer�� ������ �ּҸ� �־� �ݴϴ�.
	//pint ptr_x = &x, ptr_y = &x;

	 cout << ptr_x << endl; // x�� �ּҸ� ������ ����
	 cout << *ptr_x << endl;	// pointer�� de-reference�� �Ͽ� �ּҿ� �ִ� ���� ������

	/*
		- pointer�� �������� ����

		1).array ������ pointer�� �ƴ� �Ϲ������� �����͸� �������� ��ü ���縦 �ϰ� �Ǿ�
		  ���� ���� �޸𸮸� ���� �ϰ� �Ǵµ�, pointer�� ����ϸ� array�� ù��° �ּҰ���
		  �ް� ����� �˰� �Ǹ� array�� �����Ͱ� �ִ� �ּҿ� �����Ͽ� ���������� ���� ��� 
		  �� �� �־� �޸𸮸� �Ƴ� �� �ֽ��ϴ�.

		2). ������ �������� ����ؾ� �� ��Ȳ���� �Ź� �����ϴ°� ����, �����͸� ���� ������ 
		    �ּҸ� ������ �޸𸮸� �Ƴ� �� �ֽ��ϴ�.
	*/

	 double d = 123.0;

	 //*ptr_y = &d;	//error! type�� �ٸ�

	 double* ptr_d = &d;
	 
	 cout << ptr_d << endl;
	 cout << *ptr_d << endl;

	 cout << sizeof(x) << endl;
	 cout << sizeof(d) << endl;
	 cout << sizeof(&x) << " "  << sizeof(ptr_x)<< endl; // pointer�� �޸��� ��뷮�� (64bit)�� ��� 8����Ʈ ����Ѵ�.
	 cout << sizeof(&d) << " " << sizeof(ptr_d) << endl; // pointer�� �޸��� ��뷮�� (64bit)�� ��� 8����Ʈ ����Ѵ�.

	 something ss;
	 something* ptr_s;

	 cout << sizeof(something) << endl;
	 cout << sizeof(ptr_s) << endl;


#pragma region typeInfo ����
	 {
		 int x = 5;
		 double d = 123.0;

		 int* ptr_x = &x;

		cout << typeid(ptr_x).name() << endl;
		 
	 }

#pragma endregion

#pragma region pointer������(�ʱ�ȭ �ȵ� ������ ���� ������� ����)
	 {
		 int x = 5;

		 int* ptr_x;

		 // �ʱ�ȭ �ȵ� pointer�� ȣ�� �ϰ� �־� ������ �߻��Ѵ�.
		 //cout << *ptr_x << endl;
	 }
#pragma endregion

	return 0;
}