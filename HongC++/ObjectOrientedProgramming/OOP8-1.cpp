#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ��ü���� ���α׷��ְ� Ŭ����
// Object-Oriented-Programming class

/*
	Object (���������� ���� �ִ� ��ü�� Object��� �Ѵ�.)
	Friend : name, address, age, height, weight, ...
			 print()
*/

/*
	�� struct�� class�� ������(���Ŀ� �� ������)

	- struct���� ���� �����ڰ� ����


*/

// �ܼ��� ����� �Ҷ��� class ��� struct�� ����ϴ°� ����.(������ ������)
struct Friend
{	
	// ��� ����
	string	name;
	string	address;
	int		age;
	double	height;
	double  weight;

	// ��� �Լ� (���� ����� ������ ���������� ������ ���� �� �� �ִ�.
	void print()
	{
		cout << name << " " << address << " " << age << " " << height << " "
			<< weight << endl;
	}
};


// �����Ϳ� ����� ������ ���°��� Ŭ������ ����.
// - class�� ��ü��� ������ ���α׷��� ���ν� �������� ������ �� ���̴�.
class Friend_C
{
public:	// access sprcifier(public, private, proteced)
	// ��� ����
	string	m_name;
	string	m_address;
	int		m_age;
	double	m_height;
	double  m_weight;

	// ��� �Լ� (���� ����� ������ ���������� ������ ���� �� �� �ִ�.
	void print()
	{
		cout << m_name << " " << m_address << " " << m_age << " " << m_height << " "
			<< m_weight << endl;
	}
};


// Friend : name , address, age, height, weight

void print(const string& name, const string& address, 
	const int& age, const double& height, const double& weight)
{
	cout << name << " " << address << " " << age <<
		" " << height << " " << weight << endl;
}

void print(const Friend &fr)
{
	cout << fr.name << " " << fr.address << " " << fr.age << " " << fr.height << " "
		<< fr.weight << endl;
}

int main8_1()
{
	string	name;
	string	address;
	int		age;
	double	height;
	double  weight;

	//print(name, address, age, height, weight);

	vector<string>	name_vec;
	vector<string>	addr_vec;
	vector<int>		age_vec;
	vector<double>  height_vec;
	vector<double>	weight_vec;

	//print(name_vec[0], addr_vec[0], age_vec[0], height_vec[0], weight_vec[0]);

	// struct ---------------------------------------------------------

	Friend jj;	// instanciation, instance
	//cout << &jj << endl;
	jj.name		= "Jack Jack";
	jj.age		= 2;
	jj.address	= "Uptown";
	jj.height	= 100;
	jj.weight	= 50;

	Friend ss{ "sam","Uptown",2,30,10 };	// ������ ���缭 ���� �־�� �Ѵ�.

	print(jj.name, jj.address, jj.age, jj.height, jj.weight);

	// struct Friend �Ű������� �޴� print �Լ�
	print(jj);

	ss.print();

	vector<Friend_C> my_friends;
	my_friends.resize(2);

	for (auto& element : my_friends)
		element.print();

	return 0;
}