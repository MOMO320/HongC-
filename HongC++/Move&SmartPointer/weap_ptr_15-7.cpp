#include <iostream>
#include <memory>
#include <string>
using namespace std;

// 순환 의존성 문제(Circular dependency issueds)와 std::weak_ptr

class Person
{
	std::string m_name;
	//std::shared_ptr<Person> m_partner;
	std::weak_ptr<Person> m_partner;

public:
	Person(const std::string& name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (!p1 || !p2)
			return false;

		// p1과 p2가 서로 참조 되어 있어 지워지지 않는 상황이 발생한다.
		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << "is partnered with " << p2->m_name << "\n";
		
		return true;
	}

	// weak_ptr 사용하려 할때 lock을 해줘야 한다.
	// lock : weak_ptr을 shared_ptr로 변경해주는 함수 이다.
	const std::shared_ptr<Person> getPartner() const
	{
		return m_partner.lock();
	}


	const std::string& getName() const
	{
		return m_name;
	}
};

int main()
{
	auto lucy = std::make_shared<Person>("Lucy");
	auto ricky = std::make_shared<Person>("Ricky");

	partnerUp(lucy, ricky);

	std::cout << lucy->getPartner()->getName() << std::endl;

	return 0;
}