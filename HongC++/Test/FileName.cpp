#include <iostream>
#include <string>

using namespace std;

class MyClass
{
public:
	string myString = "s";
	int myInt = 0;

public:
	void print() {
		cout << myString << endl;
		cout << myInt << endl;
	}
};

int main()
{
	MyClass myClass;

	myClass.print();

	return 0;
}