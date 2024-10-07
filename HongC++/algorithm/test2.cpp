#include <iostream>

using namespace std;

/*
	57.재귀함수 이진수 출력

	10진수 N이 입력되면 2진수로 변환하여 출력하는 프로그램을 작성하세요.
	단 재귀함수를 이용해서 출력해야 합니다.

	- 입력설명
	: 첫 번째 줄에 10진수 N(1 <= N <= 1,000)이 주어집니다.

	- 출력설명
	: 첫 번째 줄에 이진수를 출력하세요.

	- 입력 예제 1
	: 11

	- 출력 예제 1
	: 1 0 1 1

*/

// 힌트를 얻고서 내 코드 작성 완료
void to2Print(int x)
{
	if (x <= 0)return;

	to2Print((int)x/2);
	cout << x % 2 << " ";
}

int main()
{
	int input;
	cout << "10 진수 수를 입력 해주세요 : ";
	//cin >> input;

		to2Print(11);
	
	return 0;
}