#pragma once
#ifndef PERSON_H
#define PERSON_H
#include"String.h"
class person
{
public:
	person();
	person(String, String);
	person(person&);
	String get_name() { return my_name; }
	String get_id() { return my_id; }
	void set_name(String a) { my_name = a; }
	void set_id(String b) { my_id = b; }
//protected:
    String my_name;
	String my_id;
};

#endif