#include "manager_list.h"
#include<fstream>
int Strcmp3(const char* s1, const char* s2)
{
	for (int i = 0; s1[i] && s2[i]; ++i) {
		if (s1[i] < s2[i])
			return -1;
		else if (s1[i] > s2[i])
			return 1;
	}
	return 0;
}
manager_list::manager_list()
{
	head = tail = new Manager("mid","name","id","pwd");
	size = 0;
}
manager_list::~manager_list()
{
	Manager* p = head;
	while (head)
	{
		head = head->next;
		delete p;
		p = head;
	}
}

int manager_list::list_size()const
{
	return size;
}
void manager_list::outputfile()
{
	ofstream outfile("manager.txt", ios::out);
	Manager* p = head->next;
	while (p != nullptr)
	{
		outfile  << p->get_managerid() << " " << p->get_name() << " " << p->get_id() << " " << p->get_pwd() << endl;
		p = p->next;
	}
}
void manager_list::show()
{
	Manager* p = head->next;
	if (p != nullptr)
	{
		while (p)
		{
			p->display();
			p = p->next;
		}
		cout << "查询完毕！一共有" << size << "个管理员" << endl;
	}
	else
	{
		cout << "抱歉，查询无结果" << endl;
	}
}
void manager_list::add_front(Manager value)
{
	Manager* p = head->next;
	head->next = new Manager(value);
	head->next->next = p;
	size++;
	if (size == 1) tail = head->next;
}
void manager_list::add_tail(Manager value)
{
	tail->next = new Manager(value);
	tail = tail->next;
	tail->next = nullptr;
	size++;
}
//查找功能
Manager* manager_list::find_myname(String value)
{
	Manager* p = head->next;
	while (p && !(p->get_name() == value))p = p->next;
	return p;
}
Manager* manager_list::find_myid(String value)
{
	Manager* p = head->next;
	while (p && !(p->get_id() == value))p = p->next;
	return p;
}
Manager* manager_list::find_managerid(String value)//找到前一个结点
{
	Manager* p = head;
	while (!(p->next->get_managerid() == value))
	{
		p = p->next;
		if (p->next == nullptr) return nullptr;
	}
	return p;
}
//排序功能
Manager* manager_list::BubbleSort_managerid()
{
	Manager* pre = head->next;
	Manager* p = nullptr;
	if (pre != nullptr)
	{
		if (pre->next)p = pre->next;
		else
			return head;
	}
	else
	{
		return head;
	}
	Manager* tail = this->tail;
	while (!(head->next == tail))
	{
		while (!(p == tail))
		{
			if (Strcmp3(pre->get_managerid(), p->get_managerid()) > 0)
			{
				Manager tmp;
				tmp = *pre;
				*pre = *p;
				*p = tmp;
			}
			pre = p;
			p = p->next;
		}
		//补上漏最后一次比较
		if (Strcmp3(pre->get_managerid(), p->get_managerid()) > 0)
		{
			Manager tmp;
			tmp = *pre;
			*pre = *p;
			*p = tmp;
		}
		tail = pre;
		pre = head->next;
		p = pre->next;
	}
	return head;
}
Manager* manager_list::BubbleSort_managername()
{
	Manager* pre = head->next;
	Manager* p = nullptr;
	if (pre != nullptr)
	{
		if (pre->next)p = pre->next;
		else
			return head;
	}
	else
	{
		return head;
	}
	Manager* tail = this->tail;
	while (!(head == tail))
	{
		while (!(p == tail))
		{
			if (Strcmp3(pre->get_name(), p->get_name()) > 0)
			{
				Manager tmp;
				tmp = *pre;
				*pre = *p;
				*p = tmp;
			}
			pre = p;
			p = p->next;
		}
		//补上漏最后一次比较
		if (Strcmp3(pre->get_name(), p->get_name()) > 0)
		{
			Manager tmp;
			tmp = *pre;
			*pre = *p;
			*p = tmp;
		}
		tail = pre;
		pre = head->next;
		p = pre->next;
	}
	return head;
}
Manager* manager_list::BubbleSort_id()
{
	Manager* pre = head->next;
	Manager* p = nullptr;
	if (pre != nullptr)
	{
		if (pre->next)p = pre->next;
		else
			return head;
	}
	else
	{
		return head;
	}
	Manager* tail = this->tail;
	while (!(head == tail))
	{
		while (!(p == tail))
		{
			if (Strcmp3(pre->get_id(), p->get_id()) > 0)
			{
				Manager tmp;
				tmp = *pre;
				*pre = *p;
				*p = tmp;
			}
			pre = p;
			p = p->next;
		}
		//补上漏最后一次比较
		if (Strcmp3(pre->get_id(), p->get_id()) > 0)
		{
			Manager tmp;
			tmp = *pre;
			*pre = *p;
			*p = tmp;
		}
		tail = pre;
		pre = head->next;
		p = pre->next;
	}
	return head;
}
void manager_list::modify()
{
	int flag = 0;
p:
	cout << "请选择要修改信息的管理员号：";
	String a;
	cin >> a;
	Manager* c = this->find_managerid(a);
	if (c == nullptr)
	{
		cout << "管理员号：" << a << "不存在，请重新输入......输入0返回，输入其它任意数字继续" << endl;
		cin >> flag;
		if (flag == 0) return;
		goto p;
	}
	else
	{
		cout << "此管理员信息为：" << endl;
		c->display();
	pp:
		cout << "请选择要修改的信息,输入0返回" << endl;
		cout << "1. 姓名\n2. 用户名\n3. 身份证号" << endl;
		cin >> flag;
		switch (flag)
		{
		case 0:return;
		case 1:
		{cout << "请输入新名字："; String a; cin >> a; c->set_name(a); break; }
		case 2:
		{cout << "请输入新用户名："; String b; cin >> b; c->set_managerid(b); break; }
		case 3:
		{cout << "请输入新身份证号："; String e; cin >> e; c->set_id(e); break; }
		default:cout << "信息不存在，请重新输入....."; goto pp;
		}
		cout << "修改成功！输入任意数字继续" << endl;
		cin >> flag;
	}
}
void manager_list::deletes(Manager value)//删除指定值
{
	Manager* p = find_managerid(value.get_managerid());
	if (p != nullptr)
	{
		Manager* tmp = p->next;
		if (tmp != nullptr)
		{
			p = tmp->next;
			delete tmp;
			size--;
		}
		else
		{
			p->next = nullptr;
		}
	}
}
void manager_list::Delete()
{
	int flag = 0;
p:
	cout << "请选择要删除信息的管理员号：";
	String a;
	cin >> a;
	Manager* c = this->find_managerid(a);
	if (c == nullptr)
	{
		cout << "管理员号：" << a << "不存在，请重新输入......输入0返回，输入其它任意数字继续" << endl;
		cout << "请输入=>";
		cin >> flag;
		if (flag == 0) return;
		goto p;
	}
	else
	{
		cout << "此管理员信息为：" << endl;
		c->display();
		cout << "确定要删除吗？[y/n]:";
		char j; cin >> j;
		if (j == 'y' || j == 'Y')
		{
			deletes(*c);
			cout << "删除成功！";
		}
		else
		{
			cout << "删除失败！";
		}
	}
}
void manager_list::Sort()
{
pp:
	cout << "请选择排序类型：" << endl;
	cout << "1. 按管理员号\n2. 按姓名\n3. 按身份证号\n";
	int flag = 0;
	cout << "请选择=>";
	cin >> flag;
	switch (flag)
	{
	case 1:BubbleSort_managerid(); break;
	case 2:BubbleSort_managername(); break;
	case 3:BubbleSort_id(); break;
	default:cout << "信息不存在，请重新输入....."; goto pp;
	}
	cout << "排序完成！";
}