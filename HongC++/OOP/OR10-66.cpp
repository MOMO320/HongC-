#include <iostream>
#include <vector>
#include <array>
#include <cstdarg>
#include <cassert>
#include <initializer_list>

using namespace std;
// 컨테이너 클래스(Container Classes)

class IntArray
{
private:
	int m_capacity = 0;
	int m_length = 0;
	int* m_data = nullptr;

public:
	//Constructors
	IntArray(std::initializer_list<int> values)
	{
		std::cout << "IntArray::IntArray " << std::endl;

		assert(values.size() >= 0);

		m_length = values.size();
		m_capacity = m_length * 2;
		m_data = new int[m_capacity];

		int ix = 0;
		for (auto value : values)
		{
			m_data[ix] = value;
			std::cout << m_data[ix] << ", ";
			++ix;
		}
		std::cout << std::endl;
	}

	~IntArray()
	{
		if (m_data != nullptr)
			reset();
	}


	void reset()
	{
		delete[] m_data;
		m_data = nullptr;

		m_length = 0;
		m_capacity = 0;
	}

	void resize(const int& size)
	{
		assert(size >= 0);	// size가 0보다 작거나 같을때 에러 발생

		// 만약 m_data == nullptr 이면 새로 메모리를 잡음
		if (m_data == nullptr)
		{
			m_length = size;
			m_capacity = m_length * 2;
			m_data = new int[m_capacity];
			return;
		}

		// 만약 현재 m_capacity보다 m_length가 크다면 다시 용량 재할당 해준다.
		if (m_length >= m_capacity)
		{
			m_capacity *= 2;
			int* temp = new int[m_capacity];

			for (int i = 0; i < m_length; ++i)
				temp[i] = m_data[i];

			delete[] m_data;

			m_data = temp;
		}

		// 기존 사이즈보다 작은건 상관이 없다 인덱스 접근을 못하게 되니깐
	}

	void insertBefore(const int& value, const int& ix)
	{
		assert(ix > 0);

		++m_length;
		int index = m_length - 1;

		// 사이즈가 용량을 넘으면 다시 할당
		if (m_length >= m_capacity) resize(m_length);

		for (int i = index; i <= index; --i)
		{
			if (ix == i) break;
			int curr = m_data[i];
			int before = m_data[i - 1];
			m_data[i] = m_data[i - 1];
		}

		m_data[ix] = value;
	}

	void push_back(const int& value)
	{
		++m_length;

		if (m_length >= m_capacity) resize(m_length);

		m_data[m_length - 1] = value;
	}

	friend std::ostream& operator<<(std::ostream& out, const IntArray& data)
	{
		for (int i = 0; i < data.m_length; ++i)
		{
			if (i != 0) out << ", ";
			out << data.m_data[i];
		}
		return out;
	}

	void remove(const int& ix)
	{
		assert(ix >= 0);

		int tempIx = m_length;
		--m_length;

		for (int i = ix; i <= m_length; ++i)
		{
			m_data[i] = m_data[i + 1];
		}
	}
};

int main10_6_2()
{
	IntArray my_arr{ 1,2,3,4,5 };
	
	my_arr.push_back(100);
	cout << my_arr << endl;
	my_arr.push_back(200);
	cout << my_arr << endl;
	my_arr.push_back(300);
	cout << my_arr << endl;
	my_arr.push_back(400);
	cout << my_arr << endl;
	my_arr.insertBefore(50, 3);
	cout << my_arr << endl;

	my_arr.push_back(600);
	my_arr.push_back(700);
	my_arr.push_back(800);
	my_arr.push_back(900);
	my_arr.push_back(1000);
	cout << my_arr << endl;

	my_arr.remove(5);
	cout << my_arr << endl;
	return 0;
}

int main10_6()
{
	//IntArray my_arr{ 1,3,5,7,9 };
	//my_arr.insertBefore(10,1);		// 1, 10, 3, 5, 7, 9
	//my_arr.remove(3);					// 1, 10, 3, 7, 9
	//my_arr.push_back(13);				// 1, 10, 3, 7, 9 , 13

	std::vector<int> int_vec;
	std::array<int, 10> int_arr;

	return 0;
}