#include <iostream>

using namespace std;

// 가상 기본 클래스와 다이아몬드 문제

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
	// 가상 상속으로 인해 두 부모에서 할아버지 생성자가 호출되지 않도록 한다.
	// 그렇기 때문에 PowerDevice 생성자를 따로 호출한다.
	// 만약 지정 생성자를 호출 하지 않으면 기본 생성자가 호출된다.
	Copier(int scanner, int printer, int power)
		: Scanner(scanner, power), Printer(printer, power), PoweredDevice(power)
	{

	}
};


int main12_8()
{
	// 생성자가 두번 불러와 진다.
	Copier cop(1, 2, 3);

	// 주소가 틀리다. (바라 보는 객체가 다르다.)
	cout << &cop.Scanner::PoweredDevice::m_i << endl;	//00000018456FF5D8
	cout << &cop.Printer::PoweredDevice::m_i << endl;	//00000018456FF5DC

	return 0;
}