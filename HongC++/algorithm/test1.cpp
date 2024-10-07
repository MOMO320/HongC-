#include <iostream>

using namespace std;

/*
	56.재귀함수 분석

	자연수 N이 주어지면 아래와 같이 출력하는 프로그램을 작성하세요.
	재귀함수를 이용해서 출력해야 합니다.

	- 입력설명
	: 첫 번째 줄에 자연수 N(1<=N<=20)이 주어집니다.

	- 출력설명
	: 첫 번째 줄에 재귀함수를 이용해서 출력하세요.

	- 입력 예제 1
	: 3

	- 출력 예제 1
	: 1 2 3

*/

// 내 코드
void printMyNum(int n)
{
	static int value = 1;

	if (n < 1) return;
	else
	{
		cout << value << endl;
		value++;
	}
	printMyNum(n-1);
}


// 재귀함수 호출된 시점의 라인을 저장해 뒀다가 최상위 함수 호출이 끝나면
// 이전 함수 호출 라인으로 돌아가 다음 라인을 진행 합니다.
// 반복 하면 1, 2, 3 이렇게 거꾸로 값이 출력 됩니다.


// 선생님 코드
void recur(int x)
{
	if (x == 0) return;
	else
		cout << x << endl;	// 3, 2, 1
		recur(x - 1);		// 호출 타임에 따른 출력 순서 변화(오마갓)
		cout << "-------------------------------" << endl;
		cout << x << endl;	// 1, 2, 3 
}

int main_test1()
{
	printMyNum(8);
	cout << "-------------------" << endl;
	recur(5);
	return 0;
}