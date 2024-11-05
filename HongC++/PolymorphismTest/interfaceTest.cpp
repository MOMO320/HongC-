#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Weapon
{
public:
	virtual void attack() = 0;			// 공격 기능
	virtual void reload() = 0;			// 재장전 기능
	virtual int getRange() const = 0;	// 무기 사거리 반환
	virtual string getName() const = 0;	// 무기 이름 반환
};

class Sword : public Weapon
{
public:
	void attack() override
	{
		cout << "Sword attack : Slash with sword!" << endl;
	}

	void reload() override
	{
		cout << "Sword does not need reloading." << endl;
	}

	int getRange() const override
	{
		return 1;
	}
	
	string getName() const override
	{
		return "Sword";
	}
};

class Bow : public Weapon
{
public :
	void attack() override
	{
		cout << "Bow attack : Shoot an arrow!" << endl;
	}

	void reload() override
	{
		cout << "Bow reload : Grab another arrow." << endl;
	}

	int getRange() const override
	{
		return 10;
	}

	string getName() const override
	{
		return "Bow";
	}
};

class Gun : public Weapon
{
public:
	void attack() override
	{
		cout << "Gun attack : Fire a bullet!" << endl;
	}

	void reload() override
	{
		cout << "Gun reload: Insert a new magazine." << endl;
	}

	int getRange() const override
	{
		return 20;
	}
	string getName() const override
	{
		return "Gun";
	}
};

void playerAttack(Weapon* weapon)
{
	cout << "Using " << weapon->getName() << ":" << endl;
	weapon->attack();
	weapon->reload();
	cout << "Range : " << weapon->getRange() << endl;
}

int maininterfaceTest()
{
	Sword sword;
	Bow bow;
	Gun gun;

	playerAttack(&sword);
	playerAttack(&bow);
	playerAttack(&gun);

	// 무기 컬렉션으로 관리하기
	vector<Weapon*> inventory;
	inventory.push_back(&sword);
	inventory.push_back(&bow);
	inventory.push_back(&gun);

	for (Weapon* weapon : inventory)
	{
		playerAttack(weapon);
	}

	for (Weapon* weapon : inventory)
		delete weapon;

	return 0;
}