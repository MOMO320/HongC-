#include <iostream>
#include <exception>
#include <string>

using namespace std;

// std::exception (���̺귯���� �ִ� exception Ŭ����)


class CustomException : public std::exception
{
public:	// nodexcept : �� �Լ� �ȿ����� exception�� ������ �ʰڴٴ� Ű����
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

		//exception�� ���� �Ǿ� �ִ� ���� exception Ŭ����, �Լ��� ����� �� �ִ�.
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
		// ���� Ÿ�� Ȯ��typeid(exception).name()
		std::cout << typeid(exception).name() << std::endl; // length_errorŬ���� ����
		std::cerr << exception.what() << std::endl;
	}


	return 0;
}