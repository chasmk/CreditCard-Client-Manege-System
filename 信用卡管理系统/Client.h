#pragma once
#ifndef _CLIENT_H_
#define _CLIENT_H_
#include<iostream>
#include"String.h"
#include"person.h"
#include"C_Card_list.h"
using namespace std;
class Client : public person
{
public:
	Client* next;
	Client();
	Client(String, String, String,String);
	Client& operator=(Client& a);
	void display();
	String get_pwd() { return pwd; }
	String get_clientid() { return client_id; }
	void set_clientid(String a) { client_id = a; }
	void set_pwd(String a) { pwd = a; }
	void change_pwd();//�޸�����
	void cost_money(); // ���ѽ��
	void exchange_points();//���û��ֶһ�
	void new_card(CreditCard* );//�½����ÿ�
	C_Card_list c;//�ͻ�����(ֻ�������ÿ���ָ��)
protected:
	String pwd;//����
	String client_id;//�ͻ��˺�
};
#endif

