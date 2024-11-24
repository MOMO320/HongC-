#include <iostream>
#include <tuple>

// �Լ����� ���� ���� ���ϰ� ��ȯ�ϱ�
// 1. tuple : �������� �����͸� ��� ��ȯ�ϴ� �ڷ���

using namespace std;

auto my_func()
{
	//return tuple<int, int>(123, 556);
	//return std::make_tuple<int, int, int>(123, 456, 789); // c++ 17������ ��ȯ ���
	return tuple(123, 567, 9293,111);
}

int main()
{
	auto result = my_func();
	cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result) << endl;

	//�������� ������ �����ϰ� ���� ��ȯ �޾� �ݴϴ�.(C++ 17�̻�)
	auto [a, b, c, d] = my_func();

	cout << a << " " << b << " " << c << " " << d << " ";

	return 0;
}