#include <iostream>
#include <string>

using namespace std;

class Character
{
private:
	string name;
	int level;

public:
	Character(string n, int i) : name(n), level(i) {}

	friend ostream& operator<<(ostream& os, Character& c)
	{
		c.print(os) << "이름: " << c.name << ", 레벨 : " << c.level;
		return os;
	}

	virtual ostream& print(ostream& os)
	{
		os << "나의 캐릭터 ";
		return os;
	}

};

class Archer : public Character
{
public:
	Archer(string n, int i) : Character(n, i) {}

	ostream& print(ostream& os) override
	{
		os << "나의 궁수 캐릭터 ";
		return os;
	}
};

class Healer : public Character
{
public:
	Healer(string n, int i) : Character(n, i) {}

	ostream& print(ostream& os) override
	{
		os << "나의 힐러 캐릭터 ";
		return os;
	}
};

int mainVfTest()
{
	Archer* archer = new Archer("Heal", 10);
	Character* charcter = archer;

	cout << *charcter << endl;
	
	charcter = new Healer("momo", 32);
	
	cout << *charcter << endl;

	return 0;
}
