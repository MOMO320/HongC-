#include "MyArray.h"

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

// explicit instantiation
// print�Լ��� charŸ������ ��ȯ�ҰŴϱ� �����Ͽ��� �˷��ִ� ��
template void MyArray<char>::print();	// �Լ������� ����

// class explicit instantiation
template class MyArray<char>;	// Ŭ�������� ����