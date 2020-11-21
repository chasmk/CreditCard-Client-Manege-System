#pragma once
#include"CreditCard.h"
class Card_list
{
public:
	Card_list();//默认构造函数
	~Card_list();
	int list_size()const;
	void outputfile();//out到文件
	CreditCard* gethead() { return head; }
	CreditCard* gettail() { return tail; }
	CreditCard* add_tail(CreditCard value);//添加到尾
	void deletes(CreditCard value);//删除指定值
	//查找功能
	CreditCard* find_cardnum(String value);//找到目标结点的前一个结点
	CreditCard* find_cardname(String value);
	CreditCard* find_cardidnum(String value);
	CreditCard* find_cardcredit(double value);
	//排序功能
	CreditCard* BubbleSort_cardnum();
	CreditCard* BubbleSort_cardlimit();
	CreditCard* BubbleSort_cardpoint();
	//链表操作
	void modify();
	void Delete();
	void Sort();
	void show();
protected:
	CreditCard* head, * tail;
	int size;
};
