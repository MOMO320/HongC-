#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;

// 6-17. for-each��

int main6_17_1()
{
	 int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	// change array values
	// ���� ���� ���� �ʴ� ������ number�� ���� �׳� ����Ȱ��̱� ������ 
	// ���� ���� ���� ���� �ʴ´�. ���ο� ������ ����� ���� ���� �� �� �����Ѱͻ�
	for (int number : fibonacci)
		number = 10;	// ���� ���� ���� ����

	// ���� ���� �� ������ ������ ���� �ش� ���� ���������� ���� �ϰ� �ֱ� �����̴�.
	for (int& number : fibonacci)
		number = 20;	// ���� ���� ��

	for (auto& number : fibonacci)
		number *= 10;	// auto Ű�� ���ϰ� �����

	for (int number : fibonacci)
		cout << number << " ";

	cout << endl;


	return 0;
}

// ���� ū ���� ã�� ���
int main6_17_2()
{

	int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55, 89 };

	int max_number = std::numeric_limits<int>::lowest();


	for (const auto& n : fibonacci)
		max_number = max(max_number, n);

	cout << max_number << endl;

	return 0;
}

int main6_17_3()
{
	// ���� �Ҵ� �迭
	vector<int> fibonacci = { 0,1,1,2,300,5,8,13,21,34,55,89 };

	int max_number = std::numeric_limits<int>::lowest();

	for (const auto& n : fibonacci)
		max_number = max(max_number, n);

	cout << max_number << endl;

	return 0;
}

