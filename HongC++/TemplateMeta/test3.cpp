#include <iostream>
#include <type_traits>

// 템플릿 메타 프로그래밍 예제 코드
// 템플릿 메타 프로그래밍을 통해 컴파일 타임에 타입을 결정하는 예제

using namespace std;

// 컴파일 타임 팩토리 함수
template <typename T>
struct TypeTraits;

// 타입에 따른 특화
template<>
struct TypeTraits<int>
{
	static void info()
	{
		cout << "Integer type \n";
	}
};

template<>
struct TypeTraits<double>
{
	static void info()
	{
		cout << "Double type\n";
	}
};


// 일반 함수
template <typename T>
void printType()
{
	TypeTraits<T>::info();	// T의 타입에 따라 적절한 info() 호출
}

int maintTemplateMetaTest3()
{
	printType<double>();
	printType<int>();

	return 0;
}