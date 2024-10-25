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

	// 부모 클래스는 자식 클래스에 있는걸 가져다 쓸 수 없지만
	// 자식은 가능하다.
	//person.study();	// error
	//person.teach();	// error

	return 0;
}