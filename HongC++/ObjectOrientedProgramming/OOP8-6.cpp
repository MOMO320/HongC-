#include "file.h"

// 소멸자 destructor
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
	
	// 소멸자는 instance가 메모리에서 해제될 때 내부에서 자동으로 호출됩니다.
	// 하지만 동적할당으로 만들어진 경우에는 영역을 벗어나도 자동으로 메모리가 해제되지
	// 않기 대문에 delete로 메모리를 해제할 때에만 소멸자가 호출 됩니다.
	// 소멸자를 프로그래머가 직접 호출하는 것은 대부분의 경우 권장 하지 않습니다.
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
		// memory leak 발생(메모리 할당 하고 해제 하지 않음 발생)
		IntArray my_int_arr(10000);

	}

	return 0;
}