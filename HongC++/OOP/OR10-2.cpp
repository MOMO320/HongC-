#include "Monster.h"
#include "Position2D.h"

// 10.2 객체들의 구성 관계


int main10_2()
{
	Monster mon1("Sanson", Position2D(0,0));

	cout << mon1 << endl;
	Monster mon2("Parsival", Position2D(0,0));
	//mon2.
	//while (1)	// game loop;
	{
		//event
		mon1.moveTo(Position2D(1,1));
		cout << mon1 << endl;
	}

	return 0;
}