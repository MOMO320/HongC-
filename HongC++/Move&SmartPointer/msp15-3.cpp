#include <iostream>
#include "AutoPtr.h"
#include "Resource.h"
using namespace std;

// Move constructors	: 이동 생성자와 
// Move assignment		: 이동 대입

AutoPtr<Resource> generateResource()
{
	AutoPtr<Resource> res(new Resource(10000000));

	return res;
}

int main15_3()
{
	AutoPtr<Resource> main_res;
	main_res = generateResource();

	return 0;
}