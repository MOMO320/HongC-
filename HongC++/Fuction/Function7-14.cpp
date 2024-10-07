#include <iostream>
#include <cassert>	// assert.h
#include <array>

using namespace std;

// �ܾ��ϱ� assert
// assert�� ��Ÿ�ӿ� �˷��ش�.

void printValue(const std::array<int, 5>& my_array, const int& ix)
{
	// �Ʒ��� ���� ���� ��ġ�� �� �� �ִ�.
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

	// static_assert���� ���ϴ� ���� �ȵȴ�.
	// ����� �����ϴ�.
	static_assert(y==20 , "y should be 5(jm)");

	return 0;
}