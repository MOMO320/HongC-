#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;

// 6-17. for-each문

int main6_17_1()
{
	 int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	// change array values
	// 값이 변경 되지 않는 이유는 number에 값이 그냥 복사된것이기 때문에 
	// 기존 값이 변경 되지 않는다. 새로운 변수를 만들어 값을 복사 한 후 수정한것뿐
	for (int number : fibonacci)
		number = 10;	// 값이 변경 되질 않음

	// 값이 변경 된 이유는 참조를 통해 해당 값에 직접적으로 접근 하고 있기 때문이다.
	for (int& number : fibonacci)
		number = 20;	// 값이 변경 됨

	for (auto& number : fibonacci)
		number *= 10;	// auto 키로 편리하게 변경됨

	for (int number : fibonacci)
		cout << number << " ";

	cout << endl;


	return 0;
}

// 가장 큰 숫자 찾는 방법
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
	// 동적 할당 배열
	vector<int> fibonacci = { 0,1,1,2,300,5,8,13,21,34,55,89 };

	int max_number = std::numeric_limits<int>::lowest();

	for (const auto& n : fibonacci)
		max_number = max(max_number, n);

	cout << max_number << endl;

	return 0;
}

