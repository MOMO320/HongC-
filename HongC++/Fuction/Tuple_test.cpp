#include <iostream>
#include <tuple>
#include <string>

using namespace std;

// tuple 컬렉션 연습

tuple<int, string> getAgeName()
{
	int age;
	string name;

	cout << "나이를 입력하세요 : ";
	cin >> age;

	cout << "이름을 입력하세요 : ";
	cin >> name;

	return make_tuple(age, name);
}

int mainTupleTest()
{
	tuple<int, string> personInfo;
	personInfo = getAgeName();

	cout << "나이 : " << std::get<0>(personInfo) << endl;
	cout << "이름 : " << std::get<1>(personInfo) << endl;

	auto [age, name] = personInfo;

	cout << "나이1 : " << age << " / 이름1 : " << name << endl;

	int age2;
	string name2;
	std::tie(age2, name2) = personInfo;
	cout << "나이2 : " << age2 << " / 이름2 : " << name2 << endl;
	return 0;
}