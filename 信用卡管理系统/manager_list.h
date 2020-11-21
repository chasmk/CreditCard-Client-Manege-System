#pragma once
#include"Manager.h"
typedef Manager dataType;
class manager_list
{
public:
	manager_list();//默认构造函数
	~manager_list();
	int list_size()const;
	void outputfile();//out到文件
	void add_front(Manager value);//添加到首
	void add_tail(Manager value);//添加到尾
	void deletes(Manager value);//删除指定值
	//查找功能
	Manager* find_myname(String value);
	Manager* find_myid(String value);
	Manager* find_managerid(String value);//找到前一个结点
	//排序功能
	Manager* BubbleSort_managerid();
	Manager* BubbleSort_managername();
	Manager* BubbleSort_id();
	//链表操作
	void modify();
	void Delete();
	void Sort();
	void show();
protected:
	Manager* head, * tail;
	int size;
};

