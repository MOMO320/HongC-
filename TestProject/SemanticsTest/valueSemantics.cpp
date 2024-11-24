#include <iostream>

class MyClass
{
public:
	int data;

	// ������
	MyClass(int val) : data(val) {}

	// ���� ������
	MyClass(const MyClass& other)
	{
		data = other.data;
		std::cout << "���� ������ ȣ��\n";
	}

	// ���� ���� ������
	MyClass& operator=(const MyClass& other)
	{
		if (this != &other)
		{
			data = other.data;
			std::cout << "���� ���� ������ ȣ��\n";
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