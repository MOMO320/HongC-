#pragma once
#include <iostream>
#include <string>

class Teacher
{
private:
	std::string m_name;
	//TODO : more memebers like home address, salary, age, evaluation, etc.

public:
	Teacher(const std::string& _name = "No name") :m_name(_name)
	{

	}

	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	std::string getName()
	{
		return m_name;
	}

	friend std::ostream& operator << (std::ostream& out, const Teacher& teacher)
	{
		std::cout << teacher.m_name;
		return out;
	}
};