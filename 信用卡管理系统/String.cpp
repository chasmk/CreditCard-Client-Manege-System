#include "String.h"
int Strlen(const char* s)
{
	int i = 0;
	for (; s[i]; ++i);
	return i;
}
void Strcpy(char* d, const char* s)
{
	int i = 0;
	for (i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = '\0';

}
int Strcmp(const char* s1, const char* s2)
{
	for (int i = 0; s1[i] && s2[i]; ++i) {
		if (s1[i] < s2[i])
			return -1;
		else if (s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void Strcat(char* d, const char* s)
{
	int len = strlen(d);
	strcpy(d + len, s);
}
String::String()
{
	str = new char[5];
	str[0] = 'a';
}
String::String(const char* a)
{
	str = new char[Strlen(a) + 1];
	Strcpy(str, a);
}
String::String(String& a)
{
	str = new char[Strlen(a.str) + 1];
	Strcpy(str, a.str);
}
int String::len()
{
	return Strlen(str);
}
char& String::operator[](int i)
{
	return str[i];
}
bool String::findchar(char c)
{
	int l = len();
	for (int i = 0; i < l; i++)
	{
		if (str[i] == c)return true;
	}
	return false;
}
String String::subString(String a, int i, int l)
{
	String tmp;
	delete[]tmp;
	tmp.str = new char[l+1];
	for (int j = 0; j < l;j++)
	{
		tmp[j] = a[i+j];
	}
	tmp[l] = '\0';
	return tmp;
}
String& String::operator=(const char* s)
{
	delete[]str;
	str = new char[Strlen(s) + 1];
	Strcpy(str, s);
	str[Strlen(s)] = '\0';
	return *this;
}
void String::operator=( String& a)
{
	if (this == &a)
		return;
	str = new char[a.len() + 1];
	Strcpy(str, a.str);
}
String operator+(const String& a, const  String& b)
{
	String tmp;
	tmp.str = new char[Strlen(a.str) + Strlen(b.str) + 1];
	Strcpy(tmp.str, a.str);
	Strcat(tmp.str, b.str);
	return tmp;
}
String& operator+(const String& a, const char* b)
{

	static String tmp;
	tmp.str = new char[Strlen(a.str) + Strlen(b) + 1];
	Strcpy(tmp.str, a.str);
	Strcat(tmp.str, b);
	return tmp;
}
ostream& operator<<(ostream& o, const String& a)
{
	o << a.str;
	return o;
}
istream& operator>>(istream& i, String& s)
{
	s.str = new char[256];
	i >> s.str;
	return i;
}
bool operator==(String& a, String& b)
{
	if (Strcmp(a.str, b.str) == 0&&a.len()==b.len())return true;
	else return false;
}
bool operator!=(String& a, String& b)
{
	if (Strcmp(a.str, b.str) == 0&& a.len() == b.len())return false;
	else return true;
}
bool operator==(const char* c, String& b)
{
	if (strlen(c) != b.len())return false;
	if (Strcmp(c, b.str) == 0)return true;
	else return false;
}
bool operator>(const char* c, String& b)
{
	if (Strcmp(c, b.str) > 0)return true;
	else return false;
}