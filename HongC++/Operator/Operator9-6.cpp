#include <iostream>
#include <cassert>
using namespace std;

// [] subscript operator
// ÷�� ������ �����ε� �ϱ�

class IntList
{
private:
	int m_list[10] = { 1,2,3,4,5,6,7,8,9,10 };
public:
	void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	int* getList()
	{
		return m_list;	// array ��ü�� ������
	}
	
	// ������ return ���ִ� ������ Lvalue ���� �ϰ�,
	//  �� ������ �� �� �ְ� �ϱ� ����
	int& operator[] (const int value)	// ���� ������ �ڵ�
	{
		// assert�� �̿��ؼ� ������ ��Ƴ�
		// ���� ����ϴ� ÷�� �����ڿ� if���� �ִ°��� ȿ�������� ���ϴϱ�
		// assert�� �ɾ� �����ս��� ���̰� ������� �� ����
		assert(value >= 0);
		assert(value < 10);

		return this->m_list[value];
	}

	// const operator
	const int& operator [] (const int index) const
	{
		assert(value >= 0);
		assert(value < 10);

		return this->m_list[index];
	}
};

int main9_6_1()
{
	IntList my_list;
	my_list.setItem(3, 1);

	cout << my_list.getItem(3) << endl;
	my_list.getList()[3] = 10;
	cout << my_list.getList()[3] << endl;

	cout << my_list[3] << endl;

	const IntList const_list;
	//const_list[1] = 10;	// const�̱� ������ ���� �߻�
	cout << const_list[1] << endl; // �д°� ���� ��
	return 0;
}


int main()
{
	IntList* list = new IntList;

	(*list)[3] = 10;	// ok
	//list[3] = 10;		// �ǵ��� �ٸ���.(error!)

	return 0;
}