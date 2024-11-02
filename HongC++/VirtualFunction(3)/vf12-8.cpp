#include <iostream>

using namespace std;

// ���� �⺻ Ŭ������ ���̾Ƹ�� ����

class PoweredDevice
{
public:
	int m_i = 0;

	PoweredDevice(int power =0)
	{
		cout << "PoweredDevice : " << power << "\n";
	}
};

class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		:PoweredDevice(power)
	{
		cout << "Scanner : " << scanner << '\n';
	}
};

class Printer : virtual public PoweredDevice
{
public : 
	Printer(int printer, int power)
		: PoweredDevice(power)
	{
		cout << "Printer: " << printer << '\n';
	}
		
};

class Copier : public Scanner, public Printer
{
public:
	// ���� ������� ���� �� �θ𿡼� �Ҿƹ��� �����ڰ� ȣ����� �ʵ��� �Ѵ�.
	// �׷��� ������ PowerDevice �����ڸ� ���� ȣ���Ѵ�.
	// ���� ���� �����ڸ� ȣ�� ���� ������ �⺻ �����ڰ� ȣ��ȴ�.
	Copier(int scanner, int printer, int power)
		: Scanner(scanner, power), Printer(printer, power), PoweredDevice(power)
	{

	}
};


int main12_8()
{
	// �����ڰ� �ι� �ҷ��� ����.
	Copier cop(1, 2, 3);

	// �ּҰ� Ʋ����. (�ٶ� ���� ��ü�� �ٸ���.)
	cout << &cop.Scanner::PoweredDevice::m_i << endl;	//00000018456FF5D8
	cout << &cop.Printer::PoweredDevice::m_i << endl;	//00000018456FF5DC

	return 0;
}