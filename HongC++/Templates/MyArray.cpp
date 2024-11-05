#include "MyArray.h"

//template<typename T, unsigned int T_SIZE>
//void MyArray<T , T_SIZE>::print()
//{
//	for (int i = 0; i < T_SIZE; ++i)
//		std::cout << m_data[i] << " ";
//	std::cout << std::endl;
//}

// explicit instiation의 경우 사이즈를 넣는 상수값을 정하기 어려워서 header에 정의하는게
// 좋다.

// explicit instantiation
// print함수를 char타입으로 변환할거니깐 컴파일에게 알려주는 것
// void MyArray<char, >::print();	// 함수에만도 가능

// class explicit instantiation
//template class MyArray<char>;	// 클래스에도 가능