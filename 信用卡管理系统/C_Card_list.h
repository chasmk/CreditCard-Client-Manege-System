#pragma once
#include"CreditCard.h"

class Cnode {//�ͻ���������Ľ��
public:
	Cnode* next;
	CreditCard* mcard;//ָ���б��һ�ſ���ָ��
	Cnode(CreditCard* a = nullptr, Cnode* b = nullptr) :mcard(a), next(b){}
};

class C_Card_list
{
public:
	Cnode* head;
	Cnode* tail;
	int size;
	C_Card_list();//Ĭ�Ϲ��캯��
	CreditCard* add_Card(CreditCard* a);//���һ�ſ�
	CreditCard* find_Cardid(String a);//������Ѱ��
	int list_size();
};
