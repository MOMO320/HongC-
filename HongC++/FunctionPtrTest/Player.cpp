#include "Player.h"

void Player::move()
{
	std::cout << "�÷��̾ �̵� �մϴ�." << std::endl;
}

void Player::attack()
{
	std::cout << "�÷��̾ ���� �մϴ�." << std::endl;
}

void Player::defend()
{
	std::cout << "�÷��̾ ��� �մϴ�." << std::endl;
}

// �ൿ ����
void Player::performAction(int action)
{
	void (Player::*actions[3])() = { &Player::move , &Player::attack, &Player::defend };

	if (action >= 1 && action <= 3) {
		// ���õ� �ൿ ����
		(this->*actions[action - 1])();
	}
	else
	{
		std::cout << "�߸��� ���� �Դϴ�." << std::endl;
	}
}
