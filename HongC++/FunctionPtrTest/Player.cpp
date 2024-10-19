#include "Player.h"

void Player::move()
{
	std::cout << "플레이어가 이동 합니다." << std::endl;
}

void Player::attack()
{
	std::cout << "플레이어가 공격 합니다." << std::endl;
}

void Player::defend()
{
	std::cout << "플레이어가 방어 합니다." << std::endl;
}

// 행동 수행
void Player::performAction(int action)
{
	void (Player::*actions[3])() = { &Player::move , &Player::attack, &Player::defend };

	if (action >= 1 && action <= 3) {
		// 선택된 행동 수행
		(this->*actions[action - 1])();
	}
	else
	{
		std::cout << "잘못된 선택 입니다." << std::endl;
	}
}
