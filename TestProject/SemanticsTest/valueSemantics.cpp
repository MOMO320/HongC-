#include <iostream>

class MyClass
{
public:
	int data;

	// 생성자
	MyClass(int val) : data(val) {}

	// 복사 생성자
	MyClass(const MyClass& other)
	{
		data = other.data;
		std::cout << "복사 생성자 호출\n";
	}

	// 복사 대입 연산자
	MyClass& operator=(const MyClass& other)
	{
		if (this != &other)
		{
			data = other.data;
			std::cout << "복사 대입 연산자 호출\n";
		}

		return *this;
	}
};

int mainValueSemantics()
{
	MyClass obj1(10);
	MyClass obj2 = obj1;
	obj2.data = 20;

	std::cout << "obj1.data : " << obj1.data << std::endl;
	std::cout << "obj2.data : " << obj2.data << std::endl;

	MyClass obj3(30);
	obj3 = obj1;
	std::cout << "obj3.data : " << obj3.data << std::endl;

	return 0;
}