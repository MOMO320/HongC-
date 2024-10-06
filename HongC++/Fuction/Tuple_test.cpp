#include <iostream>
#include <tuple>
#include <string>

using namespace std;

// tuple �÷��� ����

tuple<int, string> getAgeName()
{
	int age;
	string name;

	cout << "���̸� �Է��ϼ��� : ";
	cin >> age;

	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;

	return make_tuple(age, name);
}

int mainTupleTest()
{
	tuple<int, string> personInfo;
	personInfo = getAgeName();

	cout << "���� : " << std::get<0>(personInfo) << endl;
	cout << "�̸� : " << std::get<1>(personInfo) << endl;

	auto [age, name] = personInfo;

	cout << "����1 : " << age << " / �̸�1 : " << name << endl;

	int age2;
	string name2;
	std::tie(age2, name2) = personInfo;
	cout << "����2 : " << age2 << " / �̸�2 : " << name2 << endl;
	return 0;
}