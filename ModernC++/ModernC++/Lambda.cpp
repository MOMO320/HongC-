#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

//  람다(lambda) 함수와  std::function
// 람다는 익명 함수와 비슷하다.(function pointer도 비슷)

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

	func(123);	// function pointer 처럼 사용 된다.

	[](const int& i)-> void {cout << "Hello, World" << i << endl; }(1234);


	{
		string name = "Jack Jack";
		[&]() { cout << name << endl; }(); // 함수의 매개 변수를 참조 형식으로 가져오는 방식([&])
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

		f(string("World")); // f("World");  <- 가능

		auto f2 = std::bind(&goodbye, std::placeholders::_1);
		f2(string("World"));

	}





	return 0;
}