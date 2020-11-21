#pragma once
#ifndef _CLIENT_LIST_H_
#define _CLIENT_LIST_H_
#include"Client.h"
class client_list
{
public:
	client_list();//默认构造函数
	~client_list();
	int list_size()const { return size; }
	Client* add_tail(Client value);//添加到尾
	void deletes(Client value);//删除指定值
	Client* gethead() { return head; }
	void outputfile();//out到文件
	//查找功能
	Client* find_myname(String value);
	Client* find_myid(String value);
	Client* find_clientid(String value);//找到前一个结点
	//排序功能
	Client* BubbleSort_clientid();
	Client* BubbleSort_clientname();
	Client* BubbleSort_id();
	//链表操作
	void modify();
	void Delete();
	void Sort();
	void show();
protected:
	Client* head, * tail;
	int size;
};
#endif
