#pragma once
#include"CreditCard.h"
class Card_list
{
public:
	Card_list();//Ĭ�Ϲ��캯��
	~Card_list();
	int list_size()const;
	void outputfile();//out���ļ�
	CreditCard* gethead() { return head; }
	CreditCard* gettail() { return tail; }
	CreditCard* add_tail(CreditCard value);//��ӵ�β
	void deletes(CreditCard value);//ɾ��ָ��ֵ
	//���ҹ���
	CreditCard* find_cardnum(String value);//�ҵ�Ŀ�����ǰһ�����
	CreditCard* find_cardname(String value);
	CreditCard* find_cardidnum(String value);
	CreditCard* find_cardcredit(double value);
	//������
	CreditCard* BubbleSort_cardnum();
	CreditCard* BubbleSort_cardlimit();
	CreditCard* BubbleSort_cardpoint();
	//�������
	void modify();
	void Delete();
	void Sort();
	void show();
protected:
	CreditCard* head, * tail;
	int size;
};
