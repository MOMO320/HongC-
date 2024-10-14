#include "file.h"

// Static ���� ��� ����

/*
	�� static ���� ��� ���� ��� ���
	- static ��� ������ initialize�� �� �� ����.
	- static const�� ���� �����ϴ�.
	- cpp���Ͽ��� ���� �ؾ� �Ѵ�.
	- static ��� ������ ��� ������ ���̱� ������ �ٸ� �ν��Ͻ��� ����ٰ� �ص�
	  �ϳ��� ������ �����Ͽ� �ּ� ���� ����.
	
	�� static ���� ����� ����ϴ� ���
	- ��� ���� �ϴ� ���
	- �̱���(������ ����)
*/

class Something10
{
public:
	// static ��� ������ initialize�� �� �� ����.
	static int s_value;
	// static const�� ��� Ŭ���� ������ �ٷ� init�� �Ѵ�.
	static const int sc_value = 1;	
	static constexpr int se_value = 1;	// ������ Ÿ�ӿ� ���� �־�� �մϴ�.
};

int generateID()
{
	static int s_id = 0;
	return ++s_id;
}

// static ����� ��� define in cpp(header�� �θ� ������ ������ �߻�)
// header�� ���� �� ��� �ߺ� ���� ���� �߻�
int Something10::s_value = 1;	

int main8_10()
{
	cout << generateID() << endl;
	cout << generateID() << endl;
	cout << generateID() << endl;

	// instance�� ��� ��� static ��� ������ ������ �����ϴ�.
	cout << &Something10::s_value << " " << Something10::s_value << endl;
	
	Something10 st1;
	Something10 st2;

	//st1.m_value = 2;

	Something10::s_value = 1024;

	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;


	return 0;
}