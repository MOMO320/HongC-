#include <iostream>
#include <fstream>	// ���� �����

using namespace std;

// ����� ������ �����ε� �ϱ�
// ����� �������� ���� ���� ���� ��°� �ܼ� ��� �Ѵ� �� �� �ִ�.


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

	// !! �߿�
	// ��� �Լ��� ������ �����ε��� �� �� ���� ����
	// ù ��° �Ķ���Ͱ� PointŬ������ �ƴ϶� �ƿ�ǲ ��Ʈ���̶� �ȵȴ�.
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

	// �� ����Ʈ �ڵ带 �Ʒ��� ���� ����� ������ �����ε��� ����
	// ���ϰ� �� �� �ִ�.
	cout << p1 << " " << p2 << endl;


	return 0;
}

int main9_2_2()
{
	ofstream of("out.txt");

	// ���� ��� �ϴ� ���
	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);
	of << p1 << " " << p2 << endl;

	of.close();

	// ���� �Է� �޴� ���
	Point p3, p4;

	cin >> p3 >> p4;
	cout << p3 << " " << p4;
	
	return 0;
}

// ���� �б� operator ������ �����ε����� �غ���
int main9_2_3()
{
	// ���� �б� �غ�
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