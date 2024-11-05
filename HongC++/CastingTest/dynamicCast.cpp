#include <iostream>
#include <typeinfo>

using namespace std;

class Character
{
public :
	virtual void display() { cout << "캐릭터입니다."; }
	virtual ~Character() = default;
};

class Warrior : public Character
{
public:
	void display() override { cout << "전사 입니다." << endl;; }
	void attack() { cout << "전사의 공격!" << endl;; }
};

class Mage : public Character
{
public:
	void display() override { cout << "마법사 입니다." << endl; }
	void castSpell() { cout << "마법사의 주문!" << endl; }
};

int mainDynamicCastTest()
{
	Character* character = new Warrior();
	Warrior* warrior = dynamic_cast<Warrior*>(character);

	if (warrior)
	{
		warrior->attack();
	}
	else
	{
		cout << "형 변환 실패 : 전사가 아님" << endl;
	}

	Mage* mage = dynamic_cast<Mage*>(character);
	if (mage)
	{
		mage->castSpell();
	}
	else
	{
		cout << "형변환 실패 : 마법사가 아님" << endl;
	}

	delete character;
	return 0;
}