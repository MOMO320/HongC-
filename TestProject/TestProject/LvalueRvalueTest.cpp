//#include <iostream>
//#include <string>
//#include <utility>	// std::move
//
//class MyClass
//{
//private:
//	std::string data;
//
//public:
//	MyClass(const std::string& str) : data(str) 
//	{
//		std::cout << "Default constructor called!\n";
//	}
//	MyClass(std::string&& str) : data(std::move(str))
//	{
//		std::cout << "Move constructor called!\n";
//	}
//};
//
//int mainLvalueRvalue()
//{
//	std::string temp = "Hello";
//
//	MyClass myClass1(temp);
//	MyClass myClass2(std::move(temp));
//
//	if (temp.empty())
//	{
//		std::cout << "temp's empty." << std::endl;
//	}
//	else
//		std::cout << temp << std::endl;
//
//	return 0;
//}
