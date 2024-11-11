#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 예외 처리의 기본(Exception Handling)
/*
	ㅁ 예외처리를 하는 상황
	- 게임 서버 같은 경우
	- 예측할 수 없는 상황이 생길경우
*/

int findFirstChar(const char* string, char ch)
{
	for (std::size_t index = 0; index < strlen(string); ++index)
	{
		if (string[index] == ch)
			return index;
	}

	return -1;	// no match
}

double divide(int x, int y, bool& success)
{
	if (y == 0)
	{
		success = false;
		return 0.0;
	}

	success = true;
	return static_cast<double>(x) / y;
}

int main14_1_1()
{
	bool success;	// flag 변수를 만들어줌
	double result = divide(5, 3, success);

	// bool 변수인 flag 변수를 통해 정상적으로 
	// 코드가 작동했는지 예외처리를 해줍니다.
	if (!success)
		std::cerr << "An error occurred" << std::endl;
	else
		std::cout << "Result is " << result << std::endl;

	
	std::ifstream input_file("temp.txt");
	// pointer가 nullptr인지 확인으로 체크 합니다.
	if (!input_file)	
		std::cerr << "Cannot open file" << std::endl;

	return 0;
}