#include <memory>
#include <iostream>
#include <string>

class Person
{
public:
    std::string name;

public:
    Person(std::string _name) : name(_name)
    {
        std::cout << "Person <constructor> name : " << name << std::endl;
    }
    ~Person()
    {
        std::cout << "Person <Destructor> name : " << name << std::endl;
    }

    void print()
    {
        std::cout << name << std::endl;
    }
};

int main1() {
    //std::shared_ptr<int> p1 = std::make_shared<int>(10); // 정수 10을 가리키는 shared_ptr 생성
    //std::cout << "p1 count: " << p1.use_count() << std::endl; // 참조 카운트: 1

    //{
    //    std::shared_ptr<int> p2 = p1; // p2도 같은 객체를 공유
    //    std::cout << "p1 count after p2: " << p1.use_count() << std::endl; // 참조 카운트: 2
    //
    //
    //    std::shared_ptr<int> p3 = p1;
    //    std::cout << "p3 count after : " << p1.use_count() << std::endl;

    //} // p2가 스코프를 벗어나면서 참조 카운트 감소

    //std::cout << "p1 count after p2 is out of scope: " << p1.use_count() << std::endl; // 참조 카운트: 1

    //p1.reset();

    
    std::shared_ptr<Person> p1 = std::make_shared<Person>("Momo");
  
    {
        std::shared_ptr<Person> p2 = p1;
        std::cout << p2.use_count() << std::endl;
        p2->print();
    }

    p1.reset();
    std::cout << p1.use_count() << std::endl;

    return 0;
}
