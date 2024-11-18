#include <iostream>
#include <vector>
#include <stdexcept> //���ܸ� ������ ���� ���

class MyClass
{
private:
	int* data;
	size_t size;

public:
	// ������
	MyClass(size_t s) : size(s)
	{
		if (s > 1000)
		{
			// ���Ƿ� ū ���� ���� ���ܸ� �������� ��
			throw std::runtime_error("Size too large");
		}
		data = new int[size];
		for (size_t i = 0; i < size; ++i)
		{
			data[i] = i;
		}
		std::cout << "Constructor called, size : " << size << std::endl;
	}

	// �Ҹ���
	~MyClass()
	{
		delete[] data;
		std::cout << "Destructor called, size: " << size << std::endl;
	}

	// ���� ������
	MyClass(const MyClass& other) : size(other.size)
	{

	}
};