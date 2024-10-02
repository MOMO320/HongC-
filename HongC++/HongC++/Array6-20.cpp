#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

// 6-20. std::array

// 일반 변수도 파라미터로 넘기면 복사를 하게 된다.
// 그럴땐 reference를 하면 복사하지 않고 원본 데이터 주소가 넘어간다.
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


	// [ ]은 인덱스(사이즈)가 넘는지 안넘는지 확인하지 않는다.
	cout << my_arr[0] << endl;
	cout << my_arr[1] << endl;
	cout << my_arr[2] << endl;
	cout << my_arr[3] << endl;

	// .at()멤버 함수는 인덱스(사이즈)가 넘는지 확인 후 문제가 있으면 예외처리 한다.
	// 그렇기 때문에 .at( )멤버 함수가 좀 더 느리다.
	cout << my_arr.at(4) << endl;

	cout << my_arr.size() << endl;	// 배열의 사이즈를 알 수 있다.

	printLength(my_arr);

	for (auto& element : my_arr)
		cout << element << " ";
	cout << endl;

	// 정렬해주는 함수
	sort(my_arr.begin(), my_arr.end());

	sort(my_arr.rbegin(), my_arr.rend());
	return 0;
}