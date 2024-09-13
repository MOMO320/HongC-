#include <iostream>
using namespace std;

// 6-5. 정적 다차원 배열

int main6_5()
{
	const int num_rows = 3;
	const int num_colums = 5;

	int test_array[num_rows][num_colums] = {0};

	// 다차원 배열 선언하는 방법
	//row-major <-> column-major
	// num_colums는 꼭 넣어줘야 한다.(row는 안넣어도 괜찮다.)
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

	// 다차원 배열이라고 해도 메모리를 보면 알다싶이 일차원으로 주소를 사용하고 있다.
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
	
	// 3차원 배열
	int array_three[5][4][3];
	
	
	return 0;
}