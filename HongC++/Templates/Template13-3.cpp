// �ڷ����� �ƴ� ���ø� �Ű�����
#include "MyArray.h"

int main13_3()

	// std::vector<double> my_array; my_array.resize(100);
	// MyArray<double> my_array(100);
{
	// ���ø��� ������ Ÿ�ӿ� ���� �˷���� �Ѵ�.
	// non-type parameter �ڷ����� �ƴ� Ÿ��-> ���ͷ�(���)
	// ������ �ȵ� ex) int i = 10; MyArray<double, i> my_array; -> error!!!
	MyArray<char, 10> my_array;

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print();

	return 0;
}