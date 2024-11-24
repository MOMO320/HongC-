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
		std::cout << "Destructor called, size: " << size << std::endl;
		delete[] data;
		size = 0;
	}

	// ���� ������
	MyClass(const MyClass& other) : size(other.size)
	{
		data = new int[size];
		std::copy(other.data, other.data + size, data);
		std::cout << "Copy Constructor called, size : " << size << std::endl;
	}

	// �̵� ������
	MyClass(MyClass&& other) noexcept(false) : data(nullptr), size(0)
	{
		// ���ܸ� ���� �� �ִ� �̵� ������
		if (other.size > 1000)
		{
			throw std::runtime_error("Cannot move large object");
		}

		data = other.data;
		size = other.size;

		other.data = nullptr;
		other.size = 0;

		std::cout << "Move Constructor called, size : " << size << std::endl;
	}

	// ���� �Ҵ� ������
	MyClass& operator=(const MyClass& other)
	{
		if (this != &other)
		{
			delete[] this->data;

			size = other.size;
			data = new int[size];
			std::copy(other.data, other.data + size, data);
			std::cout << "Copy Assignment Operator called, size : " << size << std::endl;
		}
		return *this;
	}

	// �̵� �Ҵ� ������
	MyClass& operator=(MyClass&& other) noexcept(false)
	{
		if (this != &other)
		{
			// ���� �ڿ� ����
			delete[] data;

			// ���ܸ� ���� �� �ִ� �̵� �Ҵ� ������
			if (other.size > 1000)
				throw std::runtime_error("Cannot move large object");

			data = other.data;
			size = other.size;

			other.data = nullptr;
			other.size = 0;

			std::cout << "Move Assignment Operator called, size : " << size << std::endl;
		}

		return *this;
	}

	// ������ ��� �Լ�
	void print() const {
		for (size_t i = 0; i < size; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	try
	{
		std::vector<MyClass> vec;
		vec.reserve(3);

		vec.emplace_back(10);
		vec.emplace_back(20000);
		vec.emplace_back(5);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caugth : " << e.what() << std::endl;
	}

	return 0;
}