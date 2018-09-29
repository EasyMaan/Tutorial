#include "String.h"

//Constructors
String::String()
{
	str = nullptr;
	length = 0;
}

String::String(const char *str)
{
	strcpy(str, this->str);
}

String::String(const String const &other)
{
	if (str != nullptr)
		delete[] str;

	strcpy(other.str, this->str);
}

String::String(String &&other)
{
	length = other.length;
	str = other.str;
	other.str = nullptr;
}

String::~String()
{
	delete[] str;
}

//Operators
String& String::operator=(const String const &other)
{
	if (str != nullptr)
		delete[] str;

	strcpy(other.str, this->str);

	return *this;
}

String String::operator+(const String &other)
{
	String newStr;
	newStr.length = this->length + other.length;
	newStr.str = new char[newStr.length + 1];

	int i = 0;
	for (; i < this->length; i++)
	{
		newStr.str[i] = this->str[i];
	}

	for (int j = 0; j < other.length; j++, i++)
	{
		newStr.str[i] = other.str[j];
	}

	newStr.str[newStr.length] = '\0';

	return newStr;
}

bool String::operator==(const String const &other)
{
	if (length != other.length)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			if (str[i] != other.str[i])
				return false;
		}
	}
	return true;
}

bool String::operator!=(const String const &other)
{
	return !(this->operator==(other));
}

char& String::operator[](const int index)
{
	return str[index];
}

std::ostream& operator<<(std::ostream &os, const String &other)
{
	os << other.str;
	return os;
}

std::istream& operator>>(std::istream &is, const String &other)
{
	is >> other.str;
	return is;
}

//Public methods
size_t String::getLength() const
{
	return length;
}

//Private methods
size_t String::strlen(const char *str) const
{
	size_t count = 0;

	while (str[count])
		count++;

	return count;
}

void String::strcpy(const char *from, char *&to)
{
	length = strlen(from);
	to = new char[length + 1];

	for (int i = 0; i < length; i++)
		to[i] = from[i];

	to[length] = '\0';
}
