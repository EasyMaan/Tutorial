#include "stdafx.h"

using namespace std;

class String
{
public:
	String();

	String(char *str);

    	String(const String &other);

	String(String &&other);

	String& operator = (const String &other);

	String operator + (const String &other);

	bool operator == (const String &other);

	bool operator != (const String &other);

	char& operator[](int index);
	
	int getLength();

	~String();
private:
	char *str;
	int length;
	friend ostream& operator << (ostream &os, String &other);
	friend istream& operator >> (istream &is, String &other);
};
