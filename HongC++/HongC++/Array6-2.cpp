#include <iostream>

using namespace std;

// �Լ� �Ű������� �迭�� �������� �����Ϸ��� �����ͷ� ó�� �մϴ�.
// �Ű������� �迭�� �����ͷ� �޾� ���µ� �Ѱ� �޴� �迭�� ù��° �ּҸ� �޾� �ɴϴ�.
void doSomething(int student_socres[20])
{
	// �׷��� ������ �Ű������� ù �ּҿ� ���ڷ� ���� �迭�� �ּҸ� �޾� �ɴϴ�.
	// �Ѹ���� �Ű������� �迭�� ù �ּҸ� �޾ƿ� �����͸� �н��ϴ�.
	cout << "variable address in doSomething() : " << (int)&student_socres << endl;
	cout << "---------- �ּ� Ȯ��----------------" << endl;
	cout << "in doSomething() , : "<< (int)&(student_socres) << endl;
	cout << "in doSomething() , [0] : " << (int)&(student_socres[0]) << endl;
	cout << "in doSomething() , [1] : " << (int)&(student_socres[1]) << endl;
	cout << "in doSomething() , [2] : " << (int)&(student_socres[2]) << endl;
	cout << "in doSomething() , [3] : " << (int)&(student_socres[3]) << endl;

	cout << "---------- �� Ȯ�� ----------------" << endl;

	cout <<  student_socres[0] << endl;
	cout << student_socres[1] << endl;
	cout << student_socres[2] << endl;
	cout << student_socres[3] << endl;

	// �ּ� ��ü�� �޾ƿ��� ������ �Լ������� �����ص� ���� ���� �˴ϴ�.
	student_socres[0] = 100;
	student_socres[1] = 200;
	student_socres[2] = 300;
	student_socres[3] = 400;


	int* test;
	cout << "pointer size : " << sizeof(test) << endl;
		 
	// ����� 8 -> ������ ������
	cout << "size in doSomething : " << sizeof(student_socres) << endl;
}


int main6_2()
{
	const int num_students = 20;

	// �迭�� �ĺ���(����) ��ü�� ���������� �ּҷ� ��� �˴ϴ�.
	int students_scores[num_students] = { 1,2,3,4,5, };

	cout << (int)students_scores << endl;

	cout << "variable address in main() : " << (int)&students_scores << endl;
	cout << "in main() , [0] : " <<(int)&(students_scores[0]) << endl;
	cout << "in main() , [1] : " <<(int)&(students_scores[1]) << endl;
	cout << "in main() , [2] : " <<(int)&(students_scores[2]) << endl;
	cout << "in main() , [3] : " <<(int)&(students_scores[3]) << endl;
	cout << "in main() , [4] : " <<(int)&(students_scores[4]) << endl;

	cout << "size of main : " << sizeof(students_scores) << endl;

	doSomething(students_scores);

	cout << " doSomething �Լ� ���� ��" << endl;

	cout << (students_scores[0]) << endl;
	cout << (students_scores[1]) << endl;
	cout << (students_scores[2]) << endl;
	cout << (students_scores[3]) << endl;
	cout << (students_scores[4]) << endl;

	return 0;

}