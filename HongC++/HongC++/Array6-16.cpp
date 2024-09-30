#include <iostream>

using namespace std;

// 6_16. �����Ϳ� ������ ��� ���� ������

struct Person
{
	int age;
	double weight;
};

int main6_16()
{

	Person person;

	person.age = 5;
	person.weight = 30;

	Person& ref = person;
	ref.age = 15;

	Person* ptr = &person;
	ptr->age = 25;
	(*ptr).age = 20;

	Person& ref2 = *ptr;
	ref2.age = 45;

	cout << &person << endl;	// �ּ� ����
	cout << &ref2 << endl;		// �ּ� ����
	cout << ptr << endl;		// �ּ� ����
	cout << &ptr << endl;		// ������ ������ �ּ�
	return 0;
}