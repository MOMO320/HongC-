/*
	�迭�� �ݺ���
*/
#include <iostream>

using namespace std;

int main()
{	
	int scores[] = { 84,92,76,81,56 };
	
	// array�� ������ ���ϴ� ���
	const int num_students = sizeof(scores) / sizeof(int);

	int max_score = 0;
	int min_score = 1000;
	int total_score = 0;

	for (int i = 0; i < num_students; ++i)
	{
		// �� �ڵ�
		/*if (max_score < scores[i])
			max_score = scores[i];*/

		total_score += scores[i];

		max_score = (max_score < scores[i]) ? scores[i] : max_score;
		min_score = (min_score > scores[i]) ? scores[i] : min_score;
	}

	// ������ �ϱ� ���� �������� ���� ���ִ� ���� ����.
	double avg_score = static_cast<double>(total_score) / num_students;
	// Note : double(total_score) / num_students != double(total_score) / num_students);

	cout << "max_score : " << max_score << endl;
	cout << "min_score : " << min_score << endl;

	return 0;
}
