#include <iostream>

using namespace std;

// 6.19 ���� �����Ϳ� ���� ������ �迭

int main6_19_1()
{
	int* ptr = nullptr;
	int** ptrptr = nullptr;

	int value = 5;

	ptr = &value;
	ptrptr = &ptr;

	cout << ptr << " " << *ptr << " " << &ptr << endl;
	cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
	cout << **ptrptr << endl;	// value : 5

	return 0;
}


// ���� �����ͷ� 2���� ��� ����� ���
int main6_19_2()
{
	const int row = 3;
	const int col = 5;

	const int s2da[row][col] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};

	//�����ͷ� array ����
	int* r1 = new int[col] {1, 2, 3, 4, 5};
	int* r2 = new int[col] {6, 7, 8, 9, 10};
	int* r3 = new int[col] {11, 12, 13, 14, 15};

	int** rows = new int* [row] {r1, r2, r3};

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << rows[r][c] << " ";
		cout << endl;
	}

	delete[] r1;
	delete[] r2;
	delete[] r3;
	delete[] rows;


	return 0;
}

// ���� �����ͷ� 2���� ��� ����� ���2
int main6_19_3()
{
	const int row = 3;
	const int col = 5;

	int** matrix = new int* [row];
	
	for (int r = 0; r < row; ++r)
		matrix[r] = new int[col];

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			matrix[r][c] = ((r * col) + c)+1;
		}
	}

	//print all element
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << matrix[r][c] << " ";
		cout << endl;
	}

	// delete 
	for (int r = 0; r < row; ++r)
		delete[] matrix[r];

	delete[] matrix;
	return 0;
}

// 1�������� ������ �迭�� 2����ó�� ���̰� �ϴ� ���
int main()
{
	const int row = 3;
	const int col = 5;

	int* matrix = new int[row * col];

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			matrix[c + col * r] = ((r * col) + c) + 1;
	}

	//print
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << matrix[c + col * r] << " ";

		cout << endl;
	}


	return 0;
}