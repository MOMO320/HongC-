#pragma once
#include <assert.h>
#include <iostream>

template<typename T, unsigned int T_SIZE>
class MyArray
{
private:
	//T m_length;
	T* m_data;

public:
	MyArray()
	{
		//m_length = 0;
		m_data = nullptr;
		m_data = new T[T_SIZE];
	}
	MyArray(int length)
	{
		m_data = new T[T_SIZE];
		//m_length = length;
	}
	~MyArray()
	{
		reset();
	}

	void reset()
	{
		delete[] m_data;
		m_data = nullptr;
		//m_length = 0;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}

	void print()
	{
		for (int i = 0; i < T_SIZE; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}
};

// 템플릿은 헤더에서 정의해야 한다.
//template<typename T>
//void MyArray<T>::print()
//{
//	for (int i = 0; i < m_length; ++i)
//		std::cout << m_data[i] << " ";
//	std::cout << std::endl;
//}