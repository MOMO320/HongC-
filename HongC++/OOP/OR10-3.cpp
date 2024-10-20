#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"

// 10.3 집합 관계(Association)
// Teacher.h , Student.h, Lecture.h

// 포인터로 데이터를 공유하면 다른곳에서 값을 변경해도 공유가 된다.
int main()
{
	using namespace std;

	Student std1("Jack Jack", 0);
	Student std2("Dash", 1);
	Student std3("Violet", 2);

	Student* ptr_std1 = new Student("Jack Jack", 0);
	Student* ptr_std2 = new Student("Dash", 1);
	Student* ptr_std3 = new Student("Violet", 2);

	Teacher teacher1("Prof. Hong");
	Teacher teacher2("Prof. Good");

	//Composition Relationship
	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(&teacher1);
	lec1.registerStudent(&std1);
	lec1.registerStudent(&std2);
	lec1.registerStudent(&std3);

	Lecture lec2("Computational Thinking");
	lec2.assignTeacher(&teacher2);
	lec2.registerStudent(&std1);

	// TODO : implement Aggregation Relationship

	// test
	{
		cout << lec1 << endl;
		cout << lec2 << endl;
		
		// event
		lec2.study();

		cout << lec1 << endl;
		cout << lec2 << endl;
	}

	delete ptr_std1;
	delete ptr_std2;
	delete ptr_std3;

	return 0;
}