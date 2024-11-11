#include <iostream>
#include <string>

// 기본 템플릿 정의
template<typename T>
class Printer
{
public:
	void print(const T& value)
	{
		std::cout << "일반 타입 : " << value << std::endl;
	}
};

// int 타입에 대한 완전 특수화
template<>
class Printer<int>
{
public:
	void print(const int& value)
	{
		std::cout << "정수 타입 : " << value << "(int 특수화)" << std::endl;
	}
};

//char* 타입에 대한 완전 특수화
template<>
class Printer<char*>
{
public:
	void print(const char* value)
	{
		std::cout << "문자열 포인터 타입 : " << value << "(char* 특수화)" << std::endl;
	}
};

// 포인터 타입에 대한 부분 특수화
template<typename T>
class Printer<T*>
{
public:
	void print(T* const& value)
	{
		std::cout << "포인터 타입 : " << *value << "(포인터 특수화)" << std::endl;
	}
};

int main()
{

	Printer<int> intPrinter;
	intPrinter.print(32);

	Printer<std::string> stringPrinter;		// 일반 타입으로 나옴
	stringPrinter.print("Hello, Templates!");

	char str[] = "Hello, Specialization!";
	Printer<char*> charPointerPrinter;
	charPointerPrinter.print(str);

	int x = 100;
	Printer<int*> intPointerPrinter;
	intPointerPrinter.print(&x);

	return 0;
}
