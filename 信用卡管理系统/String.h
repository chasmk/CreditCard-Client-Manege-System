#pragma once
#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;

class String
{
public:
	String();
	String(const char*);
	String(String& a);
	operator const char* () { return str; }
	int len();
	char& operator[](int i);
	String& operator=(const char* s);
	bool findchar(char c);
	String subString(String, int i, int l);
	friend String operator+(const String& a, const  String& b);
	friend String& operator+(const String& a, const char* b);
	friend ostream& operator<<(ostream& o, const String& a);
	friend istream& operator>>(istream& i, String& a);
	void operator=(String& a); //String&
	friend bool operator==(String& a, String& b);
	friend bool operator!=(String& a, String& b);
	friend bool operator==(const char* c, String& b);

	char* str;
};

#endif

