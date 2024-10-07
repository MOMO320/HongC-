#include <iostream>
#include <cassert>	// assert.h
#include <array>

using namespace std;

// 단언하기 assert
// assert는 런타임에 알려준다.

void printValue(const std::array<int, 5>& my_array, const int& ix)
{
	// 아래와 같이 에러 위치를 알 수 있다.
	assert(ix >= 0);
	//Assertion failed: ix <= my_array.size() - 1, file
	//  C:\Users\owner\Desktop\HongC++\HongC++\Fuction\Function7-14.cpp, line 11
	assert(ix <= my_array.size() - 1);

	cout << my_array[ix] << endl;
}

// assert
int main7_14_1()
{
	int number = 5;

	// number should be 5
	assert(number == 5);

	array<int, 5> my_array{ 1,2,3,4,5 };

	printValue(my_array, 100);

	return 0;
}

// static_assert
int main7_14_2()
{
	int x = 5;
	const int y = 20;

	assert(x == 5);

	// static_assert에는 변하는 값은 안된다.
	// 상수만 가능하다.
	static_assert(y==20 , "y should be 5(jm)");

	return 0;
}