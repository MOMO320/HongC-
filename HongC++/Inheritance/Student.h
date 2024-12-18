#pragma once

#include "Person.h"

class Student : public Person
{
private:
	int m_intel;

public:
	Student(const std::string& name_in = "No Name", const int& intel_in = 0)
		: Person(name_in), m_intel(intel_in)
	{

	}

	void setIntel(const int& intel_in)
	{
		m_intel = intel_in;
	}

	int& getIntel()
	{
		return m_intel;
	}

	void study()
	{
		std::cout << getName() << "studing..." << std::endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Student& student)
	{
		out << "student name : " << student.getName() << "/ intel : " << student.m_intel;
		return out;
	}
};
