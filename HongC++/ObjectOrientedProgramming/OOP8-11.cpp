#include "file.h"

// ���� ��� �Լ�

/*
	�� ���� ��� �Լ� ���ٽ� ���� �� ��
	- this�� �Ἥ ��� ������ ���� �� �� ����. (this->)
	- static ��� ������ ��� �����ϴ�.
*/

class SomethingST
{
public:
	// inner class
	class _init
	{
	public:
		_init()
		{	
			// ���������� ��� ������ �ʱ�ȭ ���� �� �ִ�.(���/����??)
			// inner class������ static ��� ������ �ʱ�ȭ ���� �� �ִ�.
			s_value = 9876;
		}
	};

private:
	static int s_value;
	int m_value;
	
	static _init s_initializer;

public:
	// static ��� ������ �����ڿ��� �ʱ�ȭ�� �� ���� ����.
	SomethingST() : m_value(123)/*, s_value(1024)*/ {}
	static int getValue()
	{
		// this�� �Ἥ ��� ������ ���� �� �� ����.
		// return this->s_value;
		// return m_value;		// static ������ ��� �����ϴ�.
		return s_value;
	}

	void setValue(int value)
	{
		m_value = value;
	}

	int temp()
	{
		return this->m_value;
	}
};


int main8_11()
{
	// �ν��Ͻ��� �ƴϾ ���� ����
	// private�� ������ ���� �Ұ�
	//cout << SomethingST::s_value << endl;
	cout << SomethingST::getValue() << endl;

	SomethingST s1, s2;
	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl;

	// ��� �Լ� ������ ��� ���
	// ��� �Լ��� ��� �ν��Ͻ��� ������ ����� �ص� �Լ��� �ּҴ�
	// �ᱹ �ϳ��̱� ������ �ν��Ͻ� �Լ��� �ּҸ� �־� �ָ� �ȵ˴ϴ�.
	//int (SomethingST:: * fptr1)() = &s1.temp;	-> �ν��Ͻ��� �Լ� �ּ� ������ ������

	// �׷��� ������ �Ʒ��� ���� Ŭ������ ���� ������ �Լ��� �ּҸ� �ҷ��;� �մϴ�.
	int (SomethingST:: * fptr1)() = &SomethingST::temp;
	
	// ������ ��� �Լ��� ��� �� ������ �ν��Ͻ� ��ü�� ������ 
	// ������ �ν��Ͻ� ��ü�� ���� ���� �̿� �ϵ��� ���ݴϴ�.

	s1.setValue(20);
	s2.setValue(400);

	cout << (s1.*fptr1)() << endl;	// ��� �� 20
	cout << (s2.*fptr1)() << endl;	// ��� �� 400

	// static ��� �Լ��� ��� Ŭ������ �����Ͽ� ���� ���� �ʾƵ� �ȴ�.
	int (* fptr2)() = &SomethingST::getValue;
	// static ��� �Լ��� �ν��Ͻ� ��ü�� �ҷ��� �����ų �ʿ䰡 ����.
	cout << fptr2() << endl;

	return 0;
}

int SomethingST::s_value = 10;
// �Ʒ��� ���� SomethingStŬ���� ���� _init�� �ʱ�ȭ ���ָ� �����ڸ� �ҷ���
// s_value�� ���� �ʱ�ȭ �ȴ�.
SomethingST::_init SomethingST::s_initializer;