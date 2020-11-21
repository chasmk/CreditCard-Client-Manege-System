#pragma once
#include"CreditCard.h"

class Cnode {//客户卡包链表的结点
public:
	Cnode* next;
	CreditCard* mcard;//指向卡列表的一张卡的指针
	Cnode(CreditCard* a = nullptr, Cnode* b = nullptr) :mcard(a), next(b){}
};

class C_Card_list
{
public:
	Cnode* head;
	Cnode* tail;
	int size;
	C_Card_list();//默认构造函数
	CreditCard* add_Card(CreditCard* a);//添加一张卡
	CreditCard* find_Cardid(String a);//按卡号寻找
	int list_size();
};
