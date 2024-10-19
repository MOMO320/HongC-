#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

// �̴ϼȶ����� ����Ʈ initializer list
// ����� ���� �ڷ������� �����ڳ� ���Կ����ڸ� ���鶧 
// ���ϰ� ��� �� �� �ִ� initializer list�� �˾� ���ô�.

class IntArray
{
private:
	unsigned m_length = 0;
	int* m_data = nullptr;

public:
	IntArray(unsigned length) : m_length(length)
	{
		cout << "Basic Constructor" << endl;
		m_data = new int[length];
	}

	// initializer_list�� iterator�� �ε����� �����ϱ� ������ for_each������ �����Ѵ�.
	// �ε��� (÷�� [])�� ������ �Ұ� �ϴ�.
	IntArray(const std::initializer_list<int>& list) : IntArray(list.size())
	{
		cout << "Initialzer_list Constructor" << endl;

		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	~IntArray()
	{
		cout << "DesConstructor" << endl;

		cout << *this << endl;
		delete this->m_data;
	}

	// TODO : overload operator = 
	// �ñ��� ������ �־� ���� ���� �亯 �޸� �߰��� �޾Ƴ����� 
	IntArray& operator = (const IntArray& intArray)
	{
		cout << "operator = " << endl;
		
		if (this == &intArray)
			return *this;

		delete[] this->m_data;

		if (intArray.m_data == nullptr) m_data = nullptr;

		this->m_length = intArray.m_length;
		this->m_data = new int[m_length];

		for (int i = 0; i < intArray.m_length; ++i)
		{
			this->m_data[i] = intArray.m_data[i];
		}

		return *this;
	}

	friend std::ostream& operator << (std::ostream& out, IntArray& intArray)
	{
		for (int i = 0; i < intArray.m_length; ++i)
		{
			cout << intArray.m_data[i] << " ";
		}
		cout << endl;

		return out;
	}

	void getAdress()
	{
		cout << this->m_data << endl;
	}
};

int main9_12()
{
	//int my_arr1[5] = { 1,2,3,4,5 };
	//int* my_arr2 = new int[5] {1, 2, 3, 4, 5};

	//auto il = { 10, 20,30 };

	//IntArray int_array2{ 10,20,30,50,100 };

	//int_array2.getAdress();

	//IntArray int_array(int_array2);

	//int_array.getAdress();

	//cout << int_array2 << endl;

	IntArray array1{ 3,44,5 };
	IntArray array2{ 10,20,30,40 };

	IntArray array4(4);
	array4 = array1;

	return 0;
}