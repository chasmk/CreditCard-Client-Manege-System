#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include "person.h"
#include"String.h"
class Manager :public person
{
public:
	Manager();
	Manager(String mid, String n, String i,String p);
	Manager& operator=(Manager& a);
	void display();
	String get_pwd() { return pwd; }
	String get_managerid() { return manager_id; }
	void set_pwd(String a) { pwd = a; };
	void set_managerid(String a) { manager_id = a; }
	void change_pwd();//����Ա�޸�����
	Manager* next;
protected:
	String pwd;//����
	String manager_id;//Ա����
};
#endif
