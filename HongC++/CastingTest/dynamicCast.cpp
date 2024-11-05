#include <iostream>
#include <typeinfo>

using namespace std;

class Character
{
public :
	virtual void display() { cout << "ĳ�����Դϴ�."; }
	virtual ~Character() = default;
};

class Warrior : public Character
{
public:
	void display() override { cout << "���� �Դϴ�." << endl;; }
	void attack() { cout << "������ ����!" << endl;; }
};

class Mage : public Character
{
public:
	void display() override { cout << "������ �Դϴ�." << endl; }
	void castSpell() { cout << "�������� �ֹ�!" << endl; }
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
		cout << "�� ��ȯ ���� : ���簡 �ƴ�" << endl;
	}

	Mage* mage = dynamic_cast<Mage*>(character);
	if (mage)
	{
		mage->castSpell();
	}
	else
	{
		cout << "����ȯ ���� : �����簡 �ƴ�" << endl;
	}

	delete character;
	return 0;
}