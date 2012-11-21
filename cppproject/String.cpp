#include <iostream>

class String
{
	friend bool operator == (const String &s1, const String &s2);
	friend bool operator < (const String &s1, const String &s2);
	friend bool operator > (const String &s1, const String &s2);
	friend String operator + (String &s1, String &s2);

public:
	String();
	String(const char* str);
	~String(void);

	int length();
	bool empty();

	char* get_string(){return string;}
	int get_length(){return str_length;}
	void set_string(char* input, String &s);
private:
	int str_length;
	char *string;
};

String::String()
{
	str_length = 1;
	string = new char[1];
	string[0] = '\0';
}

String::String(const char *str)
{
	str_length = strlen(str)+1;
	string = new char[str_length];
	for(int i = 0; i < str_length; i++){
		string[i] = str[i];
	}
}

int String::length()
{
	return str_length;
}