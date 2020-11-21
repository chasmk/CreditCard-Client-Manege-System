#pragma once
#ifndef _CREDITCARD_H_
#define _CREDITCARD_H_
#include"person.h"
class CreditCard
{
public:
	CreditCard* next;
	CreditCard();
	CreditCard(person*,String, String,double,double);
	CreditCard(CreditCard&);
	CreditCard& operator =(CreditCard&);
	person* get_man() { return man; }
	String get_num(){ return Card_num; }
	String get_bank() { return Card_bank; }
	double get_Credit_limit(){ return Card_Credit_limit; }
	double* get_consumption() { return Card_consumption; }
	double get_Points() { return Card_Points; }
	void set_num(String a) { Card_num=a; }
	void set_name(String a) {  man->set_name(a); }
	void set_id(String a) { /*man = new person;*/ man->set_id(a); }
	void set_bank(String a) {  Card_bank = a; }
	void set_Credit_limit(double a) {  Card_Credit_limit = a; }
	void set_consumption(double *a) { for (int i = 0; i < 10; i++)Card_consumption[i] = a[i];}
	void set_Points(double a) {  Card_Points = a; }
	void display();
protected:
	person* man;//本卡持有者
	String Card_num;//卡号
	String Card_bank;//开户银行
	double Card_Credit_limit;//信用额度
	double Card_consumption[10];//消费金额
	double Card_Points;//信用积分
};
#endif
