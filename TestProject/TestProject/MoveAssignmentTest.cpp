#include <iostream>
#include <vector>

class HeavyObject
{
	std::vector<int> data;	// 큰 데이터 멤버

public:
	// 기본 생성자
	HeavyObject(size_t size) : data(size, 0)
	{
		std::cout << "Default Constructor\n";
	}

	// 복사 생성자
	HeavyObject(const HeavyObject& other) : data(other.data)
	{
		std::cout << "Copy Constructor\n";
	}

	// 이동 생성자
	HeavyObject(HeavyObject&& other) noexcept : data(std::move(other.data))
	{
		std::cout << "Move Constructor\n";
	}

	// 복사 대입 연산자
	HeavyObject& operator=(const HeavyObject& other)
	{
		if (this != &other)
		{
			data = other.data;	// 복사
			std::cout << "Copy Assignment Operator\n";
		}

		return *this;
	}

	// 복사 대입 연산자
	HeavyObject& operator=(HeavyObject&& other)
	{
		if (this != &other)
		{
			data = std::move(other.data);	//이동
			std::cout << "Move Assignment Operator\n";
		}

		return *this;
	}

	// 데이터 크기 출력
	void printSize() const
	{
		std::cout << "Data size: " << data.size() << std::endl;
	}
};

int mainMoveTest1()
{
	HeavyObject obj1(100000);
	HeavyObject obj2(5000);

	std::cout << "Copy assignment : ";
	obj2 = obj1;	// 복사 대입 연산자 호출

	std::cout << "Move assignment : ";
	obj2 = std::move(obj1);		//이동 대입 연산자 호출

	std::cout << "Final states : " << std::endl;
	obj1.printSize();
	obj2.printSize();

	return 0;
}