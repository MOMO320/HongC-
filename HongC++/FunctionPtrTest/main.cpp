#include "main.h"
#include <iostream>
#include "Player.h"

int mainFunctionPtrTest()
{
	Player player;

	int choice;
	std::cout << "�ൿ�� �����ϼ��� (1:�̵�, 2: ����, 3: ���) : ";
	std::cin >> choice;

	// ���õ� �ൿ ����
	player.performAction(choice);

	return 0;
}