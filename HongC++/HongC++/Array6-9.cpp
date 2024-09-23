#include <iostream>
using namespace std;

// 6-9. ������ ����� �迭 �ε���
// �������� : while���� break���� �̿��Ͽ� nullcharater�� �������� ���� ����Ʈ �ϵ���
void arrayPrint(char data[])
{
	int index = 0;
	while (true)
	{
		cout << *(data + index) << " " << index;
		++index;

		if (*(data + index) == 0) break;
		else
			cout << " , ";
	}
}

int main()
{
	int value = 7;
	int* ptr = &value;

	cout << uintptr_t(ptr) << endl;
	cout << uintptr_t(ptr + 1) << endl;
	cout << uintptr_t(ptr + 2 )<< endl;
	cout << uintptr_t(ptr + 3 )<< endl;

	int array[] = { 9,7,5,3,1 };
	cout << array[0] << " " << (uintptr_t)&array[0] << endl;
	cout << array[1] << " " << (uintptr_t) & array[1] << endl;
	cout << array[2] << " " << (uintptr_t) & array[2] << endl;
	cout << array[3] << " " << (uintptr_t) & array[3] << endl;
	cout << array[4] << " " << (uintptr_t)&array[4] << endl;

	int* ptrArray = array;

	for (int i = 0; i < 5; ++i)
	{
		//	cout << array[i] << " " << (uintptr_t) & array[i] << endl;
		cout << *(ptrArray + i) << " " << (uintptr_t)(ptrArray + i) << endl;

	}

	// ���ڿ�
	char name[] = "Jack Jack";

	const int n_name = sizeof(name) / sizeof(char);

	char *charPtr = name;

	for (int i = 0; i < n_name; ++i)
	{
		cout << i << ":" << *(charPtr + i) <<",";
	}cout << "!" << endl;

	arrayPrint(name);

	return 0; 
}