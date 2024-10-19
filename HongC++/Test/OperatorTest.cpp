#include <iostream>
#include <vector>

using namespace std;

// ��û�� Ŭ����
class Command
{
private:
	int _playerId;
	int _posX;
	int _posY;

public:
	Command(int playerId, int posX, int posY): _playerId(playerId), _posX(posX), _posY(posY)
	{

	}

	void Printer()
	{
		cout << "ID : " << _playerId << ", x : " << _posX << " , y : " << _posY << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Command& command)
	{
		cout << "ID : " << command._playerId << ", x : " << command._posX << " , y : " << command._posY << endl;
		return out;
	}
};

// ��û���� ���� �� ���� �� Ŭ����
class MoveTask
{
private:
	vector<Command*> commands;

public:
	void operator()()
	{
		cout << "�ش� ��ǥ�� �÷��̾� �̵�" << endl;
		for (auto& cmd : commands)
			cout << *cmd << endl;
	}

	void AddRequest(Command* cmd)
	{
		commands.push_back(cmd);
	}
};


int mainOperatorTest()
{
	MoveTask task;

	// 1) ��û
	Command cmd1(1000, 5, 5);
	Command cmd2(2000, 40, 10);
	Command cmd3(3000, 20, -5);

	// 2)����
	task.AddRequest(&cmd1);
	task.AddRequest(&cmd2);
	task.AddRequest(&cmd3);

	// 3).����
	// ������ ����� ��û���� ó���Ѵ�.	
	task();

	// ���� ���� �ܰ踦 �и��� �� �� �ִ�.

	return 0;
}