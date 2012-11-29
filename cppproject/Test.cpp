#include <iostream>
#include "String.h"

void testConstructors()
{
	std::cout<<"Starting Constructor test\n";
	String first("asd");
	std::cout << first << "\n";
	

}

int main()
{
	testConstructors();
	return 0;
}