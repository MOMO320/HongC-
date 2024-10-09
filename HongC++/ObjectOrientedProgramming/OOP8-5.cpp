#include "file.h"

// 위임 생성자(Delegating Constuctor)
// : 생성자가 다른 생성자를 가져다 쓰는 것을 위임 생성자라고 한다.

class Student
{
private:
	int		m_id;
	string	m_name;

public:
	// 어떠한 기능을 하는 코드는 한군데만 나와야 한다.
	Student(const string& name_in)
		//: m_id(0), m_name(name_in)
		// : Student(0, name_in) // 위임 생성자
	{
		init(0, name_in);
	}
	// 중복된 초기화 함수는 좋지 않은 코드이다.
	Student(const int& id_in, const string& name_in)
		: m_id(id_in), m_name(name_in)
	{
		init(id_in, name_in);
	}

	// 초기화 코드를 분리하는 방법을 추천 함
	void init(const int& id_in, const string& name_in)
	{
		m_id = id_in;
		m_name = name_in;
	}

	void print()
	{
		cout << m_id << " " << m_name << endl;
	}
};

int main()
{
	Student st1(0, "Jack Jack");
	st1.print();

	Student st2("Dash");
	st2.print();

	return 0;
}