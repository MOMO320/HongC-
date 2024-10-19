#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

// 이니셜라이져 리스트 initializer list
// 사용자 정의 자료형에서 생성자나 대입연산자를 만들때 
// 편하게 사용 할 수 있는 initializer list를 알아 봅시다.

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

	// initializer_list는 iterator로 인덱스에 접근하기 때문에 for_each문으로 접근한다.
	// 인덱스 (첨자 [])로 접근이 불가 하다.
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
	// 궁금한 내용이 있어 질문 했음 답변 달면 추가로 달아놔야지 
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