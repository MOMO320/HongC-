#include "MyArray.h"

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

// explicit instantiation
// print함수를 char타입으로 변환할거니깐 컴파일에게 알려주는 것
template void MyArray<char>::print();	// 함수에만도 가능

// class explicit instantiation
template class MyArray<char>;	// 클래스에도 가능