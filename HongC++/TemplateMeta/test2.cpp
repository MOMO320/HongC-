#include <iostream>

using namespace std;

// 템플릿 메타 프로그래밍으로 컴파일 타임 계산 예제 코드 2

// 짝수와 홀수에 따라 다른 결과를 반환하는 템플릿 구조체
template<int N>
struct IsEven
{
	static const bool value = (N % 2 == 0);
};

// 정수 N에 따라 다른 코드 생성
template<int N>
struct CheckEvenOdd
{
	static void print()
	{
		// 컴파일 시간에 조건을 확인
		if constexpr (IsEven<N>::value)
		{
			cout << N << "is even." << endl;
		}
		else
		{
			cout << N << "is odd." << endl;
		}

	}
};

int mainTest2()
{
	CheckEvenOdd<5>::print();	// 5는 홀수이므로 "5 is odd." 출력	
	CheckEvenOdd<10>::print();	// 10은 짝수이므로 "10 is even." 출력
	return 0;
}

