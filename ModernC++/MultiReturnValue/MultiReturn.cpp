#include <iostream>
#include <tuple>

// 함수에서 여러 개의 리턴값 반환하기
// 1. tuple : 여러개의 데이터를 묶어서 반환하는 자료형

using namespace std;

auto my_func()
{
	//return tuple<int, int>(123, 556);
	//return std::make_tuple<int, int, int>(123, 456, 789); // c++ 17이전에 반환 방법
	return tuple(123, 567, 9293,111);
}

int main()
{
	auto result = my_func();
	cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result) << endl;

	//여러개의 변수를 선언하고 값을 반환 받아 줍니다.(C++ 17이상)
	auto [a, b, c, d] = my_func();

	cout << a << " " << b << " " << c << " " << d << " ";

	return 0;
}