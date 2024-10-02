#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

// 6-20. std::array

// �Ϲ� ������ �Ķ���ͷ� �ѱ�� ���縦 �ϰ� �ȴ�.
// �׷��� reference�� �ϸ� �������� �ʰ� ���� ������ �ּҰ� �Ѿ��.
void printLength(const array<int,5>& myArr)
{
	for (int i = 0; i < myArr.size(); ++i)
		cout << myArr[i] << endl;

}

int main6_20()
{
	//int array[5] = { 1,2,3,4,5 };

	array<int, 5> my_arr = { 1,2,3,4,5 };
	my_arr = { 1,21,3,50,32 };


	// [ ]�� �ε���(������)�� �Ѵ��� �ȳѴ��� Ȯ������ �ʴ´�.
	cout << my_arr[0] << endl;
	cout << my_arr[1] << endl;
	cout << my_arr[2] << endl;
	cout << my_arr[3] << endl;

	// .at()��� �Լ��� �ε���(������)�� �Ѵ��� Ȯ�� �� ������ ������ ����ó�� �Ѵ�.
	// �׷��� ������ .at( )��� �Լ��� �� �� ������.
	cout << my_arr.at(4) << endl;

	cout << my_arr.size() << endl;	// �迭�� ����� �� �� �ִ�.

	printLength(my_arr);

	for (auto& element : my_arr)
		cout << element << " ";
	cout << endl;

	// �������ִ� �Լ�
	sort(my_arr.begin(), my_arr.end());

	sort(my_arr.rbegin(), my_arr.rend());
	return 0;
}