#include <iostream>
#include <cassert>
using namespace std;

// 대입 연산자 오버로딩, 깊은 복사 vs 얕은 복사 
//                     (Deep copy , Shallow copy)

// 동적한 데이터의 주소를 복사한 것을 얕을 복사라고 한다.
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
		/* shallow copy(주소 공유)
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
		// 초기화 할때 인스턴스 객체를 Rvalue로 넣으면 복사 생성자가 호출 되고
		MyString copy(hello);	// 포인터 주소 복사해서 가지고 있었음
		// 아래와 같이 하면 대입 연산자가 호출 된다.
		copy = hello;
		cout << (int*)copy.m_data << endl;	// 000001C77A0D3890 ( 그래서 주소가 같음)
		cout << copy.getString() << endl;	
	}	// 같은 주소를 공유하고 있는 copy가 괄호'}'가 끝나고 삭제 되면서 공유하고 있던
		// 동적 할당 데이터들이 삭제 되었다.

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