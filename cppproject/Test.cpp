#include <iostream>
#include <vector>
#include "StringException.h"
#include "String.h"
#include <ctime>

template <class T>
bool assertEquals(T result, T exp)
{
	if(result == exp)
		return true;
	else
		throw StringException("assertEqualStrings exception!\n");
}

bool assertEqualStrings(String result, String expected)
{
	if(result.strlength() != expected.strlength())
		throw StringException("assertEqualStrings exception!\n");
	for(unsigned int i = 0; i < result.strlength(); i++)
	{
		if(result[i] != expected[i])
			throw StringException("assertEqualStrings exception!\n");
	}
	 return true;
}

void testConstructors()
{
	clock_t t1, t2;
	t1 = clock();
	std::cout<<"Starting constructor test.\n";
	String s = String("test1");
	String x;
	String y = String(s);
	assertEqualStrings(s, y);
	t2 = clock();
	std::cout<<"Constructor Test over. Took "<< (((float)t2-(float)t1))/CLOCKS_PER_SEC << " seconds\n";
}

void testOverloads()
{
	clock_t t1, t2;
	t1 = clock();
	std::cout<<"Starting overload test.\n";
	String s = String("test1");
	String x = String("test2");
	String y = String("test1test2");
	s = s+x;
	assertEqualStrings(s, y);
	assertEquals(s[0], y[0]);
	std::cout << "Testing stream " << s+y << "\n";
	t2 = clock();
	std::cout << "Overload test over. Took " << (((float)t2-(float)t1))/CLOCKS_PER_SEC<< " seconds\n";
}

void testIterators()
{
	clock_t t1, t2;
	t1 = clock();
	std::cout<<"Starting Iterator test.\n";
	String s = String("test1");
	int i = 0;
	for(String::iterator<char> it = s.begin(); it != s.end(); ++it){
		assertEquals(*it, s[i]);
		i++;
	}
	t2 = clock();
	std::cout << "Iterator test over. Took " << (((float)t2-(float)t1))/CLOCKS_PER_SEC<< " seconds\n";
}


int main()
{
	std::vector<StringException> exceptions = std::vector<StringException>();

	try{
		testConstructors();
		testOverloads();
		testIterators();
	}
	catch(StringException& e)
	{
		exceptions.push_back(e);
	}

	for(unsigned int i = 0; i < exceptions.size(); i++)
	{
		std::cout << exceptions[i].what() << std::endl;
		std::cout << "Testing failed.\n";
	}
	
	return 0;
}

