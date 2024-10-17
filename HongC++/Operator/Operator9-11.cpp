#include <iostream>
#include <cassert>
using namespace std;

// ���� ������ �����ε�, ���� ���� vs ���� ���� 
//                     (Deep copy , Shallow copy)

// ������ �������� �ּҸ� ������ ���� ���� ������ �Ѵ�.
//
class MyString
{
public:
	char* m_data = nullptr;
	int m_length = 0;

public:
	MyString(const char* source = "")
	{
		assert(source);

		cout << "constructor" << endl;

		m_length = std::strlen(source) + 1;
		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}

	MyString(const MyString& source)
	{
		cout << "Copy Constructor" << endl;

		this->m_length = source.m_length;

		//delete[] m_data;

		if (source.m_data == nullptr)
		{
			m_data = nullptr; return;
		}

		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source.m_data[i];
	}

	~MyString()
	{
		delete[] m_data;
	}

	MyString& operator = (const MyString source)
	{
		/* shallow copy(�ּ� ����)
		this->m_data = source.m_data;
		this->m_length = source.m_length;*/


		cout << "Assignment operator" << endl;

		if (this == &source)	//prevent self-assignment
			return *this;

		delete[] m_data;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			nullptr;

		return *this;
	}

	const char* getString()
	{
		return m_data;
	}

	int getLength() { return m_length; }
};

void printInt(const int value)
{
	cout << value << endl;
}

int main9_11_1()
{

	MyString hello("gogo");

	cout << (int*)hello.m_data << endl;	// 000001C77A0D3890
	cout << hello.getString() << endl;

	{
		// �ʱ�ȭ �Ҷ� �ν��Ͻ� ��ü�� Rvalue�� ������ ���� �����ڰ� ȣ�� �ǰ�
		MyString copy(hello);	// ������ �ּ� �����ؼ� ������ �־���
		// �Ʒ��� ���� �ϸ� ���� �����ڰ� ȣ�� �ȴ�.
		copy = hello;
		cout << (int*)copy.m_data << endl;	// 000001C77A0D3890 ( �׷��� �ּҰ� ����)
		cout << copy.getString() << endl;	
	}	// ���� �ּҸ� �����ϰ� �ִ� copy�� ��ȣ'}'�� ������ ���� �Ǹ鼭 �����ϰ� �ִ�
		// ���� �Ҵ� �����͵��� ���� �Ǿ���.

	cout << hello.getString() << endl;


	printInt(5);

	return 0;
}

int main9_11_2()
{
	MyString hello("Hello");

	MyString str1 = hello;

	MyString str2;
	str2 = hello;


	return 0;
}