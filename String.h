#include <fstream>

#pragma once
class String
{
public:
	String();
	String(const char *str);
	String(const String &other);
	String(String &&other);
	~String();

	String& operator=(const String const &other);
	String operator+(const String const &other);
	bool operator==(const String const &other);
	bool operator!=(const String const &other);
	char& operator[](const int index);
	friend std::ostream& operator<<(std::ostream &os, const String &other);
	friend std::istream& operator>>(std::istream &is, const String &other);

	size_t getLength() const;

private:
	char* str;
	int length;
	
	size_t strlen(const char *str) const;
	void strcpy(const char *from, char *&to);
};

