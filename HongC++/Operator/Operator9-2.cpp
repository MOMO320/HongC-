#include <iostream>
#include <fstream>	// 파일 입출력

using namespace std;

// 입출력 연산자 오버로딩 하기
// 입출력 연산자의 좋은 점이 파일 출력과 콘솔 출력 둘다 할 수 있다.


class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{}

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }

	void print()
	{
		cout << m_x << " " << m_y << " " << m_z << endl;
	}

	// !! 중요
	// 멤버 함수로 연산자 오버로딩을 할 수 없는 이유
	// 첫 번째 파라미터가 Point클래스가 아니라 아웃풋 스트림이라서 안된다.
	friend std::ostream& operator << (std::ostream& out, const Point& point)
	{
		out << "( " << point.m_x << " " << point.m_y << " " << point.m_z << " )";

		return out;
	}

	friend std::istream& operator >> (std::istream& in, Point& point)
	{
		in >> point.m_x >> point.m_y >> point.m_z;

		return in;
	}

	friend std::ifstream& operator >> (std::ifstream& input, Point& point)
	{
		input >> point.m_x >> point.m_y >> point.m_z;

		return input;
	}

};

int main9_2_1()
{

	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);

	//p1.print();
	//cout << " ";
	//p2.print();
	//cout << endl;

	// 위 프린트 코드를 아래와 같이 입출력 연산자 오버로딩을 통해
	// 편하게 할 수 있다.
	cout << p1 << " " << p2 << endl;


	return 0;
}

int main9_2_2()
{
	ofstream of("out.txt");

	// 파일 출력 하는 방법
	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);
	of << p1 << " " << p2 << endl;

	of.close();

	// 파일 입력 받는 방법
	Point p3, p4;

	cin >> p3 >> p4;
	cout << p3 << " " << p4;
	
	return 0;
}

// 파일 읽기 operator 연산자 오버로딩으로 해보기
int main9_2_3()
{
	// 파일 읽기 준비
	ifstream in("out.txt");
	string s;

	Point pInput1, pInput2;

	if (in.is_open())
	{
		in >> pInput1;
		in >> pInput2;
	}
	cout << pInput1 << " " << pInput2 << endl;

	return 0;
}