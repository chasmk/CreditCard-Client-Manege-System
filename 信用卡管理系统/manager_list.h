#pragma once
#include"Manager.h"
typedef Manager dataType;
class manager_list
{
public:
	manager_list();//Ĭ�Ϲ��캯��
	~manager_list();
	int list_size()const;
	void outputfile();//out���ļ�
	void add_front(Manager value);//��ӵ���
	void add_tail(Manager value);//��ӵ�β
	void deletes(Manager value);//ɾ��ָ��ֵ
	//���ҹ���
	Manager* find_myname(String value);
	Manager* find_myid(String value);
	Manager* find_managerid(String value);//�ҵ�ǰһ�����
	//������
	Manager* BubbleSort_managerid();
	Manager* BubbleSort_managername();
	Manager* BubbleSort_id();
	//�������
	void modify();
	void Delete();
	void Sort();
	void show();
protected:
	Manager* head, * tail;
	int size;
};

