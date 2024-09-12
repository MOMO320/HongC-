#include <iostream>

using namespace std;

// 함수 매개변수로 배열을 받을때는 컴파일러가 포인터로 처리 합니다.
// 매개변수의 배열은 포인터로 받아 오는데 넘겨 받는 배열의 첫번째 주소를 받아 옵니다.
void doSomething(int student_socres[20])
{
	// 그렇기 때문에 매개변수의 첫 주소에 인자로 받은 배열의 주소를 받아 옵니다.
	// 한마디로 매개변수의 배열의 첫 주소를 받아와 데이터를 읽습니다.
	cout << (int)&student_socres << endl;

	cout << "---------- 주소 확인1----------------" << endl;

	cout << student_socres[0] << endl;
	cout << student_socres[1] << endl;
	cout << student_socres[2] << endl;
	cout << student_socres[3] << endl;

	// 주소 자체를 받아오기 때문에 함수내에서 변경해도 값이 유지 됩니다.
	student_socres[0] = 100;
	student_socres[1] = 200;
	student_socres[2] = 300;
	student_socres[3] = 400;

	cout << "---------- 주소 확인2----------------" << endl;
	cout << (int)&student_socres << endl;
	cout << (int)&(student_socres[0]) << endl;
	cout << (int)&(student_socres[1]) << endl;
	cout << (int)&(student_socres[2]) << endl;

	int* test;
	cout << "pointer size : " << sizeof(test) << endl;
		 
	// 사이즈가 8 -> 포인터 사이즈
	cout << "size in doSomething : " << sizeof(student_socres) << endl;
}


int main6_2()
{
	const int num_students = 20;

	// 배열의 식별자(변수) 자체가 내부적으로 주소로 사용 됩니다.
	int students_scores[num_students] = { 1,2,3,4,5, };

	cout << (int)students_scores << endl;

	cout << (int)&students_scores << endl;
	cout << (int)&(students_scores[0]) << endl;
	cout << (int)&(students_scores[1]) << endl;
	cout << (int)&(students_scores[2]) << endl;
	cout << (int)&(students_scores[3]) << endl;
	cout << (int)&(students_scores[4]) << endl;

	cout << "size of main : " << sizeof(students_scores) << endl;

	doSomething(students_scores);

	cout << " doSomething 함수 실행 후" << endl;

	cout << (students_scores[0]) << endl;
	cout << (students_scores[1]) << endl;
	cout << (students_scores[2]) << endl;
	cout << (students_scores[3]) << endl;
	cout << (students_scores[4]) << endl;

	return 0;

}