#include <iostream>
#include <utility>

class MyClass
{
private:
	int* data;
	size_t size;

public:
	// 생성자
	MyClass(size_t s) : size(s)
	{
		data = new int[size];
		for (size_t i = 0; i < size; ++i)
		{
			data[i] = i;
		}

		std::cout << "Constructor called, size: " << size << std::endl;
	} 
	
	// 소멸자
	~MyClass()
	{
		std::cout << "Destructor called, size : " << size << std::endl;
		
		if (data == nullptr) return;
		
		delete[] data;
	}

	// 복사 생성자
	MyClass(const MyClass& other) : size(other.size)
	{
		data = new int[size];
		std::copy(other.data, other.data + size, data);
		std::cout << "Copy Constructor  called, size: " << size << std::endl;
	}

	// 이동 생성자
	MyClass(MyClass&& other) noexcept : data(nullptr), size(0)
	{
		// 자원 이동
		data = other.data;
		size = other.size;

		// other 객체를 초기 상태로
		other.data = nullptr;
		other.size = 0;

		std::cout << "Move Constructor called, size: " << size << std::endl;
	}

	// 복사 할당 연산자
	MyClass& operator=(const MyClass& other)
	{
		if (this != &other)
		{
			delete[] data;

			size = other.size;
			data = new int[size];
			std::copy(other.data, other.data + size, data);
			std::cout << "Copy Assignment Operator called, size: " << size << std::endl;
		}

		return *this;
	}
	
	MyClass& operator=(MyClass&& other)
	{
		if (this != &other)
		{
			delete[] data;

			// 소유권 이전
			size = other.size;
			data = other.data;

			// 소유권 박탈
			other.data = nullptr;
			other.size = 0;	

			std::cout << "Move Assignment Operator called, size : " << size << std::endl;
		}

		return *this;
	}

	// 데이터 출력 함수
	void print()
	{
		std::cout << "print () : ";

		for (int i = 0; i < size; ++i)
			std::cout << data[i] << " ";
		std::cout << std::endl;
	}
};

int mainRvalueTest2()
{
	MyClass myClass1(10);
	MyClass myClass2(5);
	std::cout << &myClass1 << std::endl;
	std::cout << &myClass2 << std::endl;

	std::cout << "복사" << std::endl;
	myClass1.print();
	myClass2.print();

	std::cout << "이동" << std::endl;
	myClass2 = std::move(myClass1);

	std::cout << &myClass1 << std::endl;
	myClass1.print();
	std::cout << &myClass2 << std::endl;
	myClass2.print();
	std::cout << "이동" << std::endl;
	return 0;
}