/*
	6_4. 배열과 선택 정렬

*/
#include <iostream>
using namespace std;

void printArray(const int array[], int length)
{
	for (int index = 0; index < length; ++index)
		cout << array[index] << " ";

	cout << endl;
}


int main6_4()
{
	/*		선택 정렬			value	index

		3	5	2	1	4		  1       3
		1	5	2	3	4		  2		  2
		1	2	5	3	4		  3		  3
		1	2	3	5	4		  4		  4
		1	2	3	4	5
	*/

	const int length = 5;

	int my_array[length] = { 3,5,2,1,4 };

	printArray(my_array, length);

#pragma region 내가 만든 sort 코드
	int minValue = my_array[0];
	int tempIndex = 0;
	int tempValue = 0;
	for (int i = 0; i < length-1; ++i)
	{
		minValue = my_array[i];

		for (int j = i+1; j < length; ++j)
		{
			if (minValue > my_array[j])
			{
				minValue = my_array[j];
				tempIndex = j;
			}
		}

		tempValue = my_array[i];
		my_array[i] = minValue;
		my_array[tempIndex] = tempValue;
	}
#pragma endregion

#pragma region 강의 sort 코드

	//for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	//{
	//	int smallestIndex = startIndex;

	//	for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
	//	{
	//		if (my_array[smallestIndex] > my_array[currentIndex])
	//		{
	//			smallestIndex = currentIndex;
	//		}
	//	}

	//	// swap two values int the array
	//	// std::swap(array[smallestIndex], array[startIndex]);
	//	{	
	//		int temp = my_array[smallestIndex];
	//		my_array[smallestIndex] = my_array[startIndex];
	//		my_array[startIndex] = temp;
	//	}
	//}

#pragma endregion

	//	swap  == std::swap(...) <- swap 해주는 함수
	//int temp = my_array[0];
	//my_array[0] = my_array[1];
	//my_array[1] = temp;

	printArray(my_array, length);

	return 0;
}