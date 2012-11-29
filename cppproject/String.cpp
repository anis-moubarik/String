#include <iostream>
#include "String.h"

//Constructor for empty String
String::String()
{
	string = new char[1];
	string[0] = '\0';
	length = 0;
}

String::String(const char * const newString)
{
	length = strlen(newString);
	string = new char[length+1];

	for(unsigned int i = 0; i <= length; i++)
	{
		string[i] = newString[i];
	}
	string[length] = '\0';
}

String::String(const String & str)
{
	length = str.strlength();
	string = new char[length+1];
	for(unsigned int i = 0; i <= length; i++)
	{
		string[i] = str[i];
	}
	string[length] = '\0';
}

String::~String()
{
	delete [] string;
	length = 0;
}

String String::operator+(const String & str)
{
	unsigned int i, j, totalLength;
	totalLength = length + str.strlength();
	char* newString = new char[totalLength];

	for(i = 0; i < length; i++)
	{
		newString[i] = string[i];
	}
	for(j = 0; j < str.strlength(); j++, i++)
	{
		newString[i] = str[j];
	}

	newString[totalLength] = '\0';
	String temp(newString);
	return temp;
}

template<class T> void swap(T& a, T& b)
{
	T copy(a);
	a = b;
	b = copy;
}

void String::swap(String & str)
{
	::swap(string, str.string);
}

String & String::operator=(const String & str)
{
	String temp(str);
	swap(temp);

	return *this;
}

std::ostream & operator <<(std::ostream & output, const String & str)
{
	output << str.string;
	return output;
}

char & String::operator[](unsigned int index)
{
	if(index > length)
		return string[length-1];
	else
		return string[index];
}

//immutable
char String::operator[](unsigned int index) const
{
	if(index > length)
		return string[length-1];
	else
		return string[index];
}