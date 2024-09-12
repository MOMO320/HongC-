#include <iostream>

using namespace std;

#define NUM_STUDENT 10000 

struct Rectangle
{
	int length;
	int width;
};

enum StudentName
{
	JACKJACK,	// = 0
	DASH,		// = 1
	VIOLET,		// = 2
	NUM_STUDENTS, // = 3
};

int mainArray()
{
#pragma region array 기초

	int jackjack_score;
	int dash_score;
	int violet_score;

	int one_student_score;	// 1 variable
	int student_scores[5];	// 5 int

	one_student_score = 100;
	student_scores[0] = 100;	// 1st element , index
	student_scores[1] = 80;		// 2nd element
	student_scores[2] = 90;		// 3rd element
	student_scores[3] = 50;		// 4th element
	student_scores[4] = 0;		// 5th element
	//student_scores[5] = 30;		// 6th element  --> error 발생!

	cout << student_scores[0] << endl;
	cout << student_scores[1] << endl;
	cout << student_scores[2] << endl;
	cout << student_scores[3] << endl;
	cout << student_scores[4] << endl;
	//cout << student_scores[5] << endl;


	//cout << sizeof(one_student_score) << endl;
	//cout << sizeof(student_scores) << endl;

	cout << (student_scores[0] + student_scores[1]) / 2.0 << endl;
#pragma endregion array 기초

#pragma region struct array

	cout << "------------------------- struct array -------------------------------------" << endl;

	cout << sizeof(Rectangle) << endl;

	Rectangle rect_arr[10];

	cout << sizeof(rect_arr) << endl;

	rect_arr[0].length = 1;
	rect_arr[0].width = 2;

#pragma endregion

#pragma region  array 초기화 하는 방법

	cout << "------------------------- array 초기화 하는 방법 -------------------------------------" << endl;
	//int my_array[] = { 1,2, };
	int my_array[]{ 1,2,3,4,5 };	
	//int student_scores[NUM_STUDENTS];

	// enum의 값을 통해 정의도 가능
	//student_scores[JACKJACK] = 0;
	//student_scores[DASH] = 100;

	cout << my_array[JACKJACK] << endl;
	cout << my_array[DASH] << endl;
	cout << my_array[VIOLET] << endl;
	cout << my_array[3] << endl;
	cout << my_array[4] << endl;

	int num_students = 0;
	cin >> num_students;

	// 컴파일 타임에 배열 사이즈가 결정이 되어 있어야한다.
	// 위 처럼 런타임 중에 값을 받아 배열 사이즈를 쓸 수 없다.
	// int students_scores[num_students]; // 에러 발생! 런타임 중에 사이즈를 받아서 사용할 수 없다.

	const int num_size = 5;

	// 변수로 array 사이즈를 받으려면 const 키워드를 넣어줘야 한다.
	int student_score[num_size]{};

#pragma endregion


	return 0;
}