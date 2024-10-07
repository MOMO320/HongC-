#include <iostream>

using namespace std;

// 재귀적 함수 호출 (Recursive Function Call)
// 자기가 자기를 호출하는 함수
// 재귀 함수를 너무 어렵게 생각하지 말고 공식을 만들면 원하는 결과 값이 나온다.

/*
	ㅁ 스택과 재귀 함수의 관련성
	: 재귀 함수와 스택은 밀접한 관련이 있습니다.
	  재귀 함수는 함수가 자기 자신을 호출하면서 호출 정보를 스택에 저장하고,
	  호출이 완료되면 스택 호출 정보를 꺼내어 이전 상태로 돌아갑니다.
	  스택은 재귀 함수의 호출과정을 관리하는데 사용되며,
	  재귀 함수를 이해하고 디버깅하는데 도움을 줍니다.

*/ 


void countDown(int count)
{
	cout << count << endl;

	// 재귀 함수를 호출 할때는 종료 조건을 넣어야 합니다.
	
	if (count > 0) 
		countDown(count - 1);

}

int value = 0;
static int sum = 0;
int total = 0;
int sumTo(int sumto)
{
	++value;
	if (sumto <= 0)
		return 0;
	else if (sumto <= 1)
		return 1;
	else
	{	
		// 선생님 코드
		// return sumTo(sumto -1) +sumto;

		sum = sumTo(sumto - 1);
		total = sum + sumto;
		// 재귀호출의 경우 함수를 호출이 다 돌고 끝나면 return 해서 하나씩 값을 배출 합니다.
		return sum + sumto;
	}
}

// 재귀 함수를 이용한 합 구하기 (1부터 n까지)
int recursiveSum(int n)
{
	if (n <= 1)
		return 1;
	else
		return n + recursiveSum(n - 1);
}

// 0, 1, 2 , 3 , 5, 8, 13, 21 ... (쭉쭉 앞에 값과 합하는걸 피보나치 수열이라고 한다.)
// 내가 짠 코드 아님(솔직히 잘 모르겠음.. .아무리 봐도)
int fibonacci(int n)
{
	if (n <= 1)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

// 팩토리얼 구하기
// 팩토리얼의 정의 n! = n*(n-1)!
int factorial(int n)
{
	int value = 0;
	cout << "factorial(" << n << ")";
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		value = n * factorial(n - 1);
		return value;
	}
}


int main7_12()
{
	//countDown(5);

	//cout << sumTo(10) << endl;
	cout << fibonacci(6) << endl;

	//cout << factorial(3) << endl;

	//cout << recursiveSum(3) << endl;

	return 0;
}