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
		c.print(os) << "�̸�: " << c.name << ", ���� : " << c.level;
		return os;
	}

	virtual ostream& print(ostream& os)
	{
		os << "���� ĳ���� ";
		return os;
	}

};

class Archer : public Character
{
public:
	Archer(string n, int i) : Character(n, i) {}

	ostream& print(ostream& os) override
	{
		os << "���� �ü� ĳ���� ";
		return os;
	}
};

class Healer : public Character
{
public:
	Healer(string n, int i) : Character(n, i) {}

	ostream& print(ostream& os) override
	{
		os << "���� ���� ĳ���� ";
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
