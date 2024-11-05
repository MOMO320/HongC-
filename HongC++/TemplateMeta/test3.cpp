#include <iostream>
#include <type_traits>

// ���ø� ��Ÿ ���α׷��� ���� �ڵ�
// ���ø� ��Ÿ ���α׷����� ���� ������ Ÿ�ӿ� Ÿ���� �����ϴ� ����

using namespace std;

// ������ Ÿ�� ���丮 �Լ�
template <typename T>
struct TypeTraits;

// Ÿ�Կ� ���� Ưȭ
template<>
struct TypeTraits<int>
{
	static void info()
	{
		cout << "Integer type \n";
	}
};

template<>
struct TypeTraits<double>
{
	static void info()
	{
		cout << "Double type\n";
	}
};


// �Ϲ� �Լ�
template <typename T>
void printType()
{
	TypeTraits<T>::info();	// T�� Ÿ�Կ� ���� ������ info() ȣ��
}

int maintTemplateMetaTest3()
{
	printType<double>();
	printType<int>();

	return 0;
}