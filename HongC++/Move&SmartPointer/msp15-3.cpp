#include <iostream>
#include "AutoPtr.h"
#include "Resource.h"
using namespace std;

// Move constructors	: �̵� �����ڿ� 
// Move assignment		: �̵� ����

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