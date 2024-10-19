#include "main.h"
#include <iostream>
#include "Player.h"

int mainFunctionPtrTest()
{
	Player player;

	int choice;
	std::cout << "행동을 선택하세요 (1:이동, 2: 공격, 3: 방어) : ";
	std::cin >> choice;

	// 선택된 행동 수행
	player.performAction(choice);

	return 0;
}