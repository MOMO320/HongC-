#include <iostream>
#include <vector>

using namespace std;

// 요청서 클래스
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

// 요청들을 저장 및 실행 할 클래스
class MoveTask
{
private:
	vector<Command*> commands;

public:
	void operator()()
	{
		cout << "해당 좌표로 플레이어 이동" << endl;
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

	// 1) 요청
	Command cmd1(1000, 5, 5);
	Command cmd2(2000, 40, 10);
	Command cmd3(3000, 20, -5);

	// 2)저장
	task.AddRequest(&cmd1);
	task.AddRequest(&cmd2);
	task.AddRequest(&cmd3);

	// 3).실행
	// 여유가 생기면 요청들을 처리한다.	
	task();

	// 위와 같이 단계를 분리해 줄 수 있다.

	return 0;
}