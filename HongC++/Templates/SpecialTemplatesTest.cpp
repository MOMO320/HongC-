#include <iostream>
#include <string>

// �⺻ ���ø� ����
template<typename T>
class Printer
{
public:
	void print(const T& value)
	{
		std::cout << "�Ϲ� Ÿ�� : " << value << std::endl;
	}
};

// int Ÿ�Կ� ���� ���� Ư��ȭ
template<>
class Printer<int>
{
public:
	void print(const int& value)
	{
		std::cout << "���� Ÿ�� : " << value << "(int Ư��ȭ)" << std::endl;
	}
};

//char* Ÿ�Կ� ���� ���� Ư��ȭ
template<>
class Printer<char*>
{
public:
	void print(const char* value)
	{
		std::cout << "���ڿ� ������ Ÿ�� : " << value << "(char* Ư��ȭ)" << std::endl;
	}
};

// ������ Ÿ�Կ� ���� �κ� Ư��ȭ
template<typename T>
class Printer<T*>
{
public:
	void print(T* const& value)
	{
		std::cout << "������ Ÿ�� : " << *value << "(������ Ư��ȭ)" << std::endl;
	}
};

int main()
{

	Printer<int> intPrinter;
	intPrinter.print(32);

	Printer<std::string> stringPrinter;		// �Ϲ� Ÿ������ ����
	stringPrinter.print("Hello, Templates!");

	char str[] = "Hello, Specialization!";
	Printer<char*> charPointerPrinter;
	charPointerPrinter.print(str);

	int x = 100;
	Printer<int*> intPointerPrinter;
	intPointerPrinter.print(&x);

	return 0;
}
