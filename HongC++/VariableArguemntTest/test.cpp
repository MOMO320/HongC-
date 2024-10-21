#include <iostream>


using namespace std;

/*
	1. variadic templates
	: 가변 인자 템플릿을 사용하면 함수가 가변적인 수의 인자를 받을 수 있씁니다.

*/

template<typename T>
void print(T value)
{
	std::cout << value << endl;
}

template<typename T, typename...Args>
void print(T value, Args... args)
{
	std::cout << value << ", ";
	print(args...);	// 남은 인자들을 재귀적으로 처리
}

int main1()
{
	print(1, 2.6, "Hello", 'A');

	return 0;
}