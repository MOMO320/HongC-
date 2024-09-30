#include <iostream>

using namespace std;

// 6_16. 포인터와 참조의 멤버 선택 연산자

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

	cout << &person << endl;	// 주소 같음
	cout << &ref2 << endl;		// 주소 같음
	cout << ptr << endl;		// 주소 같음
	cout << &ptr << endl;		// 포인터 변수의 주소
	return 0;
}