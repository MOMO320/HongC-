#include "MyArray.h"

//template<typename T, unsigned int T_SIZE>
//void MyArray<T , T_SIZE>::print()
//{
//	for (int i = 0; i < T_SIZE; ++i)
//		std::cout << m_data[i] << " ";
//	std::cout << std::endl;
//}

// explicit instiation�� ��� ����� �ִ� ������� ���ϱ� ������� header�� �����ϴ°�
// ����.

// explicit instantiation
// print�Լ��� charŸ������ ��ȯ�ҰŴϱ� �����Ͽ��� �˷��ִ� ��
// void MyArray<char, >::print();	// �Լ������� ����

// class explicit instantiation
//template class MyArray<char>;	// Ŭ�������� ����