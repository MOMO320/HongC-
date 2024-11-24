#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

//  ����(lambda) �Լ���  std::function
// ���ٴ� �͸� �Լ��� ����ϴ�.(function pointer�� ���)

using namespace std;

void goodbye(const string& s)
{
	cout << "Goodbye" << s << endl;
}

class Object
{
public:
	void hello(const string& str)
	{
		cout << "hello" << str << endl;
	}
};

int main()
{

	auto func = [](const int& i)-> void {cout << "Hello, Wolrd" << endl; };

	func(123);	// function pointer ó�� ��� �ȴ�.

	[](const int& i)-> void {cout << "Hello, World" << i << endl; }(1234);


	{
		string name = "Jack Jack";
		[&]() { cout << name << endl; }(); // �Լ��� �Ű� ������ ���� �������� �������� ���([&])
	}

	vector<int> v;

	v.push_back(1);
	v.push_back(2);

	auto func2 = [](int val)  {cout << val << endl; };
	//for_each(v.begin(), v.end(), func2);

	for_each(v.begin(), v.end(), [](int& val) { val = val * 2; });
	for_each(v.begin(), v.end(), [&](int val) { cout << val<< " "; });

	cout << []() -> int {return 1; } () << endl;

	std::function<void(int)> func3 = func2;
	func3(123);

	//place holder , bind
	std::function<void(void)>func4 = std::bind(func3, 456);
	func4();

	{
		Object instance;
		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

		f(string("World")); // f("World");  <- ����

		auto f2 = std::bind(&goodbye, std::placeholders::_1);
		f2(string("World"));

	}





	return 0;
}