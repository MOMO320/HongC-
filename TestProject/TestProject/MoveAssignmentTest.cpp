#include <iostream>
#include <vector>

class HeavyObject
{
	std::vector<int> data;	// ū ������ ���

public:
	// �⺻ ������
	HeavyObject(size_t size) : data(size, 0)
	{
		std::cout << "Default Constructor\n";
	}

	// ���� ������
	HeavyObject(const HeavyObject& other) : data(other.data)
	{
		std::cout << "Copy Constructor\n";
	}

	// �̵� ������
	HeavyObject(HeavyObject&& other) noexcept : data(std::move(other.data))
	{
		std::cout << "Move Constructor\n";
	}

	// ���� ���� ������
	HeavyObject& operator=(const HeavyObject& other)
	{
		if (this != &other)
		{
			data = other.data;	// ����
			std::cout << "Copy Assignment Operator\n";
		}

		return *this;
	}

	// ���� ���� ������
	HeavyObject& operator=(HeavyObject&& other)
	{
		if (this != &other)
		{
			data = std::move(other.data);	//�̵�
			std::cout << "Move Assignment Operator\n";
		}

		return *this;
	}

	// ������ ũ�� ���
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
	obj2 = obj1;	// ���� ���� ������ ȣ��

	std::cout << "Move assignment : ";
	obj2 = std::move(obj1);		//�̵� ���� ������ ȣ��

	std::cout << "Final states : " << std::endl;
	obj1.printSize();
	obj2.printSize();

	return 0;
}