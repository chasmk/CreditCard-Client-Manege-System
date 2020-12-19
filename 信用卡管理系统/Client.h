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
	void change_pwd();//修改密码
	void cost_money(); // 消费金额
	void exchange_points();//信用积分兑换
	void new_card(CreditCard* );//新建信用卡
	C_Card_list c;//客户卡包(只保存信用卡的指针)
protected:
	String pwd;//密码
	String client_id;//客户账号
};
#endif

