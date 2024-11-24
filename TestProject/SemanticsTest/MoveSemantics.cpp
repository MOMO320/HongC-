#include <iostream>
#include <vector>
#include <string>

class MyClass
{
public:
	int* data;

	// 생성자
	MyClass(int val) : data(new int(val))
	{
		std::cout << "생성자 호출\n";
	}

	// 소멸자
	~MyClass()
	{
		delete data;
		std::cout << "소멸자 호출\n";
	}

	// 복사 생성자
	MyClass(const MyClass& other) : data(new int(*other.data))
	{
		std::cout << "복사 생성자 호출 \n";
	}

	// 이동 대입 연산자
	MyClass& operator=(MyClass&& other) noexcept
	{
		if (this != &other)
		{
			delete data;			// 기존 자원 해제
			data = other.data;      // 자원 이동
			other.data = nullptr;
			std::cout << "이동 대입 연산자 호출\n";
		}

		return *this;
	}
};

int main()
{
	MyClass obj1(10);				// 생성자 호출
	MyClass obj2 = std::move(obj1);	// 이동 생성자 호출
	MyClass obj3(20);				// 생성자 호출
	obj3 = std::move(obj2);			// 이동 대입 연산자 호출

	return 0;
}
