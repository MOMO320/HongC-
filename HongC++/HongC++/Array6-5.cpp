#include <iostream>
using namespace std;

// 6-5. ���� ������ �迭

int main6_5()
{
	const int num_rows = 3;
	const int num_colums = 5;

	int test_array[num_rows][num_colums] = {0};

	// ������ �迭 �����ϴ� ���
	//row-major <-> column-major
	// num_colums�� �� �־���� �Ѵ�.(row�� �ȳ־ ������.)
	int array[num_rows][num_colums] =
	{
		{1,2,3,4,5} ,		//	row 0
		{6,7,8,9,10},		//	row 1
		{11,12,13,14,15},	//	row 2
	};

	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_colums; ++col)
		{
			cout << array[row][col] << '\t';
		}
			//cout << '[' << row << ']' << '[' << col << ']' << '\t';

		cout << endl;
	}

	cout << endl;

	// ������ �迭�̶�� �ص� �޸𸮸� ���� �˴ٽ��� ���������� �ּҸ� ����ϰ� �ִ�.
	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_colums; ++col)
		{
			cout << (int)&array[row][col] << '\t';
		}
		//cout << '[' << row << ']' << '[' << col << ']' << '\t';

		cout << endl;
	}

	cout << endl;
	
	// 3���� �迭
	int array_three[5][4][3];
	
	
	return 0;
}