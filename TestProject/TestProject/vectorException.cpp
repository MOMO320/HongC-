#include <iostream>
#include <vector>
#include <stdexcept> //예외를 던지기 위한 헤더

class MyClass
{
private:
	int* data;
	size_t size;

public:
	// 생성자
	MyClass(size_t s) : size(s)
	{
		if (s > 1000)
		{
			// 임의로 큰 값에 대해 예외를 던지도록 함
			throw std::runtime_error("Size too large");
		}
		data = new int[size];
		for (size_t i = 0; i < size; ++i)
		{
			data[i] = i;
		}
		std::cout << "Constructor called, size : " << size << std::endl;
	}

	// 소멸자
	~MyClass()
	{
		delete[] data;
		std::cout << "Destructor called, size: " << size << std::endl;
	}

	// 복사 생성자
	MyClass(const MyClass& other) : size(other.size)
	{

	}
};