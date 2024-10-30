#include <iostream>
#include <string>

using namespace std;

// 인터페이스 클래스
// 외부에서 클래스를 사용할때 이러이러한 기능이 있을것이다.
// 하고 예측을 할 수 있는 중계기를 할 수 있다.
class IErrorLog
{
public:
	// pure virtual function
	virtual bool reportError(const char* errorMessage) = 0;
	virtual ~IErrorLog() { }
};

class FileErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << errorMessage << endl;
		cout << "Writing error to a file" << endl;
		return true;
	}

};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << errorMessage << endl;
		cout << "Printing error to a console" << endl;
		return true;
	}
};

void doSomething(IErrorLog& log)
{
	log.reportError("Runtime error!!");
}

int main12_7_interface()
{
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);
	doSomething(console_log);

	return 0;
}