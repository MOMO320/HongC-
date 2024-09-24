#include <iostream>

using namespace std;

// 6-12.동적 할당 배열

int main6_12()
{
	int length;

	cin >> length;

	int* array = new int[length] {1,2,3};

	//array[0] = 1;
	//array[1] = 2;

	for (int i = 0; i < length; ++i)
	{
		cout << &array[i] << endl;
		cout << array[i] << endl;
	}

	delete[] array;

	int fixedArray[] = { 1,2,3,4,5 };

	//int* array = new int[3] {1, 2, 3};

	// resizing


	delete[] array;

	return 0;
}