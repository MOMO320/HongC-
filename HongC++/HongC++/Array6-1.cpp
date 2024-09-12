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
#pragma region array ����

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
	//student_scores[5] = 30;		// 6th element  --> error �߻�!

	cout << student_scores[0] << endl;
	cout << student_scores[1] << endl;
	cout << student_scores[2] << endl;
	cout << student_scores[3] << endl;
	cout << student_scores[4] << endl;
	//cout << student_scores[5] << endl;


	//cout << sizeof(one_student_score) << endl;
	//cout << sizeof(student_scores) << endl;

	cout << (student_scores[0] + student_scores[1]) / 2.0 << endl;
#pragma endregion array ����

#pragma region struct array

	cout << "------------------------- struct array -------------------------------------" << endl;

	cout << sizeof(Rectangle) << endl;

	Rectangle rect_arr[10];

	cout << sizeof(rect_arr) << endl;

	rect_arr[0].length = 1;
	rect_arr[0].width = 2;

#pragma endregion

#pragma region  array �ʱ�ȭ �ϴ� ���

	cout << "------------------------- array �ʱ�ȭ �ϴ� ��� -------------------------------------" << endl;
	//int my_array[] = { 1,2, };
	int my_array[]{ 1,2,3,4,5 };	
	//int student_scores[NUM_STUDENTS];

	// enum�� ���� ���� ���ǵ� ����
	//student_scores[JACKJACK] = 0;
	//student_scores[DASH] = 100;

	cout << my_array[JACKJACK] << endl;
	cout << my_array[DASH] << endl;
	cout << my_array[VIOLET] << endl;
	cout << my_array[3] << endl;
	cout << my_array[4] << endl;

	int num_students = 0;
	cin >> num_students;

	// ������ Ÿ�ӿ� �迭 ����� ������ �Ǿ� �־���Ѵ�.
	// �� ó�� ��Ÿ�� �߿� ���� �޾� �迭 ����� �� �� ����.
	// int students_scores[num_students]; // ���� �߻�! ��Ÿ�� �߿� ����� �޾Ƽ� ����� �� ����.

	const int num_size = 5;

	// ������ array ����� �������� const Ű���带 �־���� �Ѵ�.
	int student_score[num_size]{};

#pragma endregion


	return 0;
}