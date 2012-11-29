#ifndef STRING_H
#define STRING_H
class String{
public:
	String();
	String(const char * const);
	String(String const&);
	~String();

	String operator +(const String &);
	String & operator = (const String &);
	friend std::ostream& operator << (std::ostream& output, const String &);
	char & operator[] (unsigned int index);
	char operator[] (unsigned int index) const;

	unsigned int strlength() const {return length;}; 
	void push_back(char c);
	char pop_back();
	void insert(char c);
	void erase(int i);
	void swap(String &);
private:
	char * string;
	unsigned int length;
};

#endif // !STRING_H
