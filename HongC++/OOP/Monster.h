#pragma once
#include <string>
#include "Position2D.h"

using namespace std;

class Monster
{
private:
	string m_name;	// string = char * data, unsinged length;
	Position2D m_location; // 재활용 가능

public:
	Monster(string name, const Position2D& pos2d)
		: m_name(name), m_location(pos2d)
	{

	}

	void moveTo(const Position2D& pos2d_target)
	{
		m_location.set(pos2d_target);
	}

	friend ostream& operator << (ostream& out,const Monster& monster)
	{
		cout << monster.m_name<< " " << monster.m_location;
		return out;
	}
};

