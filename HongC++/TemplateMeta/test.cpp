#include <iostream>

using namespace std;

// 템플릿 메타 프로그래밍 
// 1. 컴파일 시간 계산 : 프로그램의 일부를 컴파일 시간에 미리 계산하여,
// 런타임에서의 계산 비용을 줄입니다.

// 팩토리얼 계산을 위한 템플릿 메타 프로그래밍
// Factorial<N> 템플릿 구조체는 N이 0이 아닐 때 팩토리얼 계산을 재귀적으로 수행 합니다.
template<int N>
struct Factorial
{
	static const int value = N * Factorial<N - 1>::value;
};

// 종료 조건
// Factorial<0> 특수화된 템플릿은 재귀 호출의 종료 조건으로, 0!을 1로 정의 합니다.
template<>
struct Factorial<0>
{
	static const int value = 1;
};

int maintest1()
{
	std::cout << "Factorial of 5: " << Factorial<5>::value << endl;
	return 0;
}

