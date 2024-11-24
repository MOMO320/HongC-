#include <iostream>
#include <vector>
#include <string>

class MyClass
{
public:
	int* data;

	// ������
	MyClass(int val) : data(new int(val))
	{
		std::cout << "������ ȣ��\n";
	}

	// �Ҹ���
	~MyClass()
	{
		delete data;
		std::cout << "�Ҹ��� ȣ��\n";
	}

	// ���� ������
	MyClass(const MyClass& other) : data(new int(*other.data))
	{
		std::cout << "���� ������ ȣ�� \n";
	}

	// �̵� ���� ������
	MyClass& operator=(MyClass&& other) noexcept
	{
		if (this != &other)
		{
			delete data;			// ���� �ڿ� ����
			data = other.data;      // �ڿ� �̵�
			other.data = nullptr;
			std::cout << "�̵� ���� ������ ȣ��\n";
		}

		return *this;
	}
};

int main()
{
	MyClass obj1(10);				// ������ ȣ��
	MyClass obj2 = std::move(obj1);	// �̵� ������ ȣ��
	MyClass obj3(20);				// ������ ȣ��
	obj3 = std::move(obj2);			// �̵� ���� ������ ȣ��

	return 0;
}
