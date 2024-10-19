#pragma once
#include <iostream>

class Player
{
public:
	void move();
	void attack();
	void defend();
	void performAction(int action);
};