#include "Student.h"
#include "Teacher.h"

int main11_2()
{
	Student std1("Jack Jack", 2);
	std1.setName("Jack Jack 2");
	Teacher teacher1("Dr.H");
	teacher1.setName("Dr.K");

	//std::cout << std1.getName() << std::endl;
	//std::cout << teacher1.getName() << std::endl;

	std::cout << std1 << std::endl;
	std::cout << teacher1 << std::endl;

	std1.doNothing();
	teacher1.doNothing();

	std1.study();
	teacher1.teach();

	Person person;
	person.setName("Mr. Incredible");
	person.getName();

	// �θ� Ŭ������ �ڽ� Ŭ������ �ִ°� ������ �� �� ������
	// �ڽ��� �����ϴ�.
	//person.study();	// error
	//person.teach();	// error

	return 0;
}