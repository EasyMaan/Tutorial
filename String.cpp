#include "String.h"

String::String()
{
	str = nullptr;
	length = 0;
}

String::String(char *str)
{
	length = strlen(str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
}

String::String(const String &other)
{
	length = strlen(other.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';
}

String::String(String &&other)
{
	this->length = other.length;
	this->str = other.str;
	other.str = nullptr;
}

String& String::operator = (const String &other)
{
	if (this->str != nullptr)
	{
		delete[] str;
	}
	length = strlen(other.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';
	return *this;
}

String String::operator + (const String &other)
{
	String newStr;
	newStr.length = strlen(this->str) + strlen(other.str);
	newStr.str = new char[strlen(this->str) + strlen(other.str) + 1];
	int i = 0;
	for (; i < strlen(this->str); i++)
	{
		newStr.str[i] = this->str[i];
	}
	for (int j = 0; j < strlen(other.str); j++, i++)
	{
		newStr.str[i] = other.str[j];
	}
	newStr.str[strlen(this->str) + strlen(other.str)] = '\0';
	return newStr;
}

bool String::operator == (const String &other)
{
	if (this->length != other.length)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
	}
	return true;
}

bool String::operator != (const String &other)
{
	return !(this->operator==(other));
}

char& String::operator[](int index)
{
	return this->str[index];
}
	
int String::Length()
{
	return length;
}

String::~String()
{
	delete[] this->str;
}
