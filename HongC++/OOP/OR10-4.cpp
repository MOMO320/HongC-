#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 제휴 관계
// Associaiton
// 제휴 관계인 서로가 내부에 멤버 변수로 가지고 있다.
// 제휴 관계인 경우에는 전방선언이 필요할 수 있다.

// 서로 알아야 할 경우 전방선언을 통해 알게해 준다.
// 서로의 헤더를 include 할 경우 에러가 발생 합니다.(link error)
class Doctor;	/// 전방 선언(forward declaration)
class Patient
{
private:
	string m_name;
	vector<Doctor*> m_doctors;
public:
	Patient(string name_in)
		:m_name(name_in)
	{

	}

	void addDoctor(Doctor* new_doctor)
	{
		m_doctors.push_back(new_doctor);
	}

	void meetDoctors();

	friend class Doctor;
};

class Doctor
{
private:
	string m_name;
	vector<Patient*> m_patients;
public:
	Doctor(string name_in)
		:m_name(name_in)
	{

	}

	void addPatient(Patient* new_patient)
	{
		m_patients.push_back(new_patient);
	}

	void meetPatient()
	{
		for (auto& ele : m_patients)
			cout << "Meet doctor : " << ele->m_name << endl;
	}

	friend class Patient;

};

void Patient::meetDoctors()
{
	for (auto& ele : m_doctors)
		cout << "Meet doctor : " << ele->m_name << endl;
}

int main10_4()
{
	Patient* p1 = new Patient("Jack Jack");
	Patient* p2 = new Patient("Dash");
	Patient* p3 = new Patient("Violet");

	Doctor* d1 = new Doctor("Doctor K");
	Doctor* d2 = new Doctor("Doctor L");

	p1->addDoctor(d1);
	d1->addPatient(p1);

	p2->addDoctor(d2);
	d2->addPatient(p2);

	p2->addDoctor(d1);
	d1->addPatient(p2);

	//patients meet doctors
	p1->meetDoctors();

	// doctors meet patients
	d1->meetPatient();

	//deletes
	delete p1;
	delete p2;
	delete p3;
	delete d1;
	delete d2;
	return 0;
}