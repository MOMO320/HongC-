#include <iostream>
#include <exception>
#include <string>

using namespace std;

// std::exception (라이브러리에 있는 exception 클래스)


class CustomException : public std::exception
{
public:	// nodexcept : 이 함수 안에서는 exception을 던지지 않겠다는 키워드
	const char* what() const noexcept override
	{
		return "Custom exception";
	}
};
int main14_4()
{
	try
	{
		std::string s;
	//	s.resize(-1);

		//exception에 정의 되어 있는 많은 exception 클래스, 함수를 사용할 수 있다.
		//throw std::runtime_error("Bad thing happend");
		throw CustomException();
	}
	catch (std::length_error& exception)
	{
		std::cerr << "Length_Error" << endl;
		std::cerr << exception.what() << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cerr << "exception " << endl;
		// 예외 타입 확인typeid(exception).name()
		std::cout << typeid(exception).name() << std::endl; // length_error클래스 나옴
		std::cerr << exception.what() << std::endl;
	}


	return 0;
}