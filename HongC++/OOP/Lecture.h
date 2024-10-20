#pragma once
#include <vector>
#include "Student.h"
#include "Teacher.h"

class Lecture
{
private:
	std::string m_name;

	//Teacher teacher;
	//std::vector<Student> students;

	Teacher *teacher;
	std::vector<Student*> students;
public:
	Lecture(const std::string& name_in)
		:m_name(name_in)
	{

	}
	~Lecture()
	{
		//do Not delete teacher
		//delete teacher;
	}

	void assignTeacher(Teacher* const teacher_input)
	{
		teacher = teacher_input;
	}

	void registerStudent(Student* const student_input)
	{
		// &student_input != &students[0] 
		students.push_back(student_input);
	}

	void study()
	{
		std::cout << m_name << "study " << std::endl;

		// auto�� ����Ҷ� '&'������ ���� �ʰ� value�� �޾ƿ���
		// ���� ������Ʈ ���� �ʴ´�.
		// (�ֳĸ� �ӽ� ��ü�� ������ �� ���簡 �Ͼ�� ������)
		//for (auto& element : students)	// Note : 'auto element' doesn't work
		//	element.setIntel(element.getIntel() + 1);

		// �����Ҵ��� �����͸� ������ auto ������ ���� �ʾƵ� ���� ����ȴ�.
		for (auto& element : students)	// Note : 'auto element' work
			element->setIntel(element->getIntel() + 1);
	
	}

	friend std::ostream& operator << (std::ostream& out, const Lecture& lecture)
	{
		out << "Lecture name : " << lecture.m_name << std::endl;

		out << *lecture.teacher << std::endl;
		
		//for (auto& element : lecture.students)
		//	out << element << std::endl;

		for (auto& element : lecture.students)
			out << (*element) << std::endl;

		return out;
	}
};

