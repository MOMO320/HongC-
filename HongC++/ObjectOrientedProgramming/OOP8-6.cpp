#include "file.h"

// �Ҹ��� destructor
class Simple
{
private:
	int m_id;

public:
	Simple(const int& id_in) : m_id(id_in)
	{
		cout << "Constructor : " << m_id << endl;
	}
	~Simple()
	{
		cout << "Destructor :" << m_id << endl;
	}
};

int main8_6_1()
{
	//Simple s1(0);
	Simple* s1 = new Simple(0);
	Simple s2(1);
	
	// �Ҹ��ڴ� instance�� �޸𸮿��� ������ �� ���ο��� �ڵ����� ȣ��˴ϴ�.
	// ������ �����Ҵ����� ������� ��쿡�� ������ ����� �ڵ����� �޸𸮰� ��������
	// �ʱ� �빮�� delete�� �޸𸮸� ������ ������ �Ҹ��ڰ� ȣ�� �˴ϴ�.
	// �Ҹ��ڸ� ���α׷��Ӱ� ���� ȣ���ϴ� ���� ��κ��� ��� ���� ���� �ʽ��ϴ�.
	delete s1;

	return 0;
}

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];

		cout << "Constructor " << endl;
	}
	~IntArray()
	{
		if(m_arr != nullptr) delete[] m_arr;
	}
	int size() { return m_length; }
};


int main8_6_2()
{
	while (true)
	{
		// memory leak �߻�(�޸� �Ҵ� �ϰ� ���� ���� ���� �߻�)
		IntArray my_int_arr(10000);

	}

	return 0;
}