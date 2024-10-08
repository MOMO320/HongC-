#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 객체지향 프로그래밍과 클래스
// Object-Oriented-Programming class

/*
	Object (개념적으로 묶여 있는 객체를 Object라고 한다.)
	Friend : name, address, age, height, weight, ...
			 print()
*/

/*
	ㅁ struct와 class의 차이점(추후에 더 설명함)

	- struct에는 접근 지정자가 없음


*/

// 단순한 기능을 할때는 class 대신 struct을 사용하는게 좋다.(데이터 묶을때)
struct Friend
{	
	// 멤버 변수
	string	name;
	string	address;
	int		age;
	double	height;
	double  weight;

	// 멤버 함수 (같은 멤버기 때문에 직접적으로 변수에 접근 할 수 있다.
	void print()
	{
		cout << name << " " << address << " " << age << " " << height << " "
			<< weight << endl;
	}
};


// 데이터와 기능을 묶을때 쓰는것은 클래스가 좋다.
// - class란 객체라는 개념을 프로그래밍 언어로써 문법으로 구현을 한 것이다.
class Friend_C
{
public:	// access sprcifier(public, private, proteced)
	// 멤버 변수
	string	m_name;
	string	m_address;
	int		m_age;
	double	m_height;
	double  m_weight;

	// 멤버 함수 (같은 멤버기 때문에 직접적으로 변수에 접근 할 수 있다.
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

	Friend ss{ "sam","Uptown",2,30,10 };	// 순서에 맞춰서 값을 넣어야 한다.

	print(jj.name, jj.address, jj.age, jj.height, jj.weight);

	// struct Friend 매개변수로 받는 print 함수
	print(jj);

	ss.print();

	vector<Friend_C> my_friends;
	my_friends.resize(2);

	for (auto& element : my_friends)
		element.print();

	return 0;
}