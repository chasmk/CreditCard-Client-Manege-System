#pragma once
#ifndef _CLIENT_LIST_H_
#define _CLIENT_LIST_H_
#include"Client.h"
class client_list
{
public:
	client_list();//Ĭ�Ϲ��캯��
	~client_list();
	int list_size()const { return size; }
	Client* add_tail(Client value);//��ӵ�β
	void deletes(Client value);//ɾ��ָ��ֵ
	Client* gethead() { return head; }
	void outputfile();//out���ļ�
	//���ҹ���
	Client* find_myname(String value);
	Client* find_myid(String value);
	Client* find_clientid(String value);//�ҵ�ǰһ�����
	//������
	Client* BubbleSort_clientid();
	Client* BubbleSort_clientname();
	Client* BubbleSort_id();
	//�������
	void modify();
	void Delete();
	void Sort();
	void show();
protected:
	Client* head, * tail;
	int size;
};
#endif
