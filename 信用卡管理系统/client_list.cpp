#include "client_list.h"
#include<fstream>
typedef Client dataType;
int Strcmp2(const char* s1, const char* s2)
{
	for (int i = 0; s1[i] && s2[i]; ++i) {
		if (s1[i] < s2[i])
			return -1;
		else if (s1[i] > s2[i])
			return 1;
	}
	return 0;
}
client_list::client_list()
{
	head = tail = new dataType("cid","name","id","pwd");
	size = 0;
}
client_list::~client_list()
{
	Client* p = head;
	while (head)
	{
		head = head->next;
		delete p;
		p = head;
	}
}
void client_list::outputfile()
{
	ofstream outfile("Client.txt",ios::out);
	Client* p = head->next;
	while (p != nullptr)
	{
		outfile << p->get_clientid() << " " << p->get_name() << " " << p->get_id()<<" "<<p->get_pwd() << endl;
		p = p->next;
	}
}
void client_list::show()
{
	Client* p = head->next;
	if (p != nullptr)
	{
		while (p)
		{
			p->display();
			p = p->next;
		}
		cout << "查询完毕！一共有" << size << "位用户" << endl;
	}
	else
	{
		cout << "抱歉，查询无结果" << endl;
	}
}
Client* client_list::add_tail(Client value)
{
	tail->next = new Client(value);
	tail = tail->next;
	tail->next = nullptr;
	size++;
	return tail;
}
//查找功能
dataType* client_list::find_myname(String value)
{
	dataType* p = head->next;
	while (p && !(p->get_name() == value))p = p->next;
	return p;
}
dataType* client_list::find_myid(String value)
{
	dataType* p = head->next;
	while (p && !(p->get_id() == value)) { p = p->next;  }
	return p;
}
dataType* client_list::find_clientid(String value)//找到前一个结点
{
	dataType* p = head;
	while (!(p->next->get_clientid() == value))
	{
		p = p->next;
		if (p->next == nullptr) return nullptr;
	}
	return p;
}
//排序功能
Client* client_list::BubbleSort_clientid()
{
	Client* pre = head->next;
	Client* p = nullptr;
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
	Client* tail = this->tail;
	while (!(head->next == tail))
	{
		while (!(p == tail))
		{
			if (Strcmp2(pre->get_clientid(), p->get_clientid()) > 0)
			{
				Client tmp;
				tmp = *pre;
				*pre = *p;
				*p = tmp;
			}
			pre = p;
			p = p->next;
		}
		//补上漏最后一次比较
		if (Strcmp2(pre->get_clientid(), p->get_clientid()) > 0)
		{
			Client tmp;
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
Client* client_list::BubbleSort_clientname()
{
	Client* pre = head->next;
	Client* p = nullptr;
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
	Client* tail = this->tail;
	while (!(head->next== tail))
	{
		while (!(p == tail))
		{
			if (Strcmp2(pre->get_name(), p->get_name()) > 0)
			{
				Client tmp;
				tmp = *pre;
				*pre = *p;
				*p = tmp;
			}
			pre = p;
			p = p->next;
		}
		//补上漏最后一次比较
		if (Strcmp2(pre->get_name(), p->get_name()) > 0)
		{
			Client tmp;
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
Client* client_list::BubbleSort_id()
{
	Client* pre = head->next;
	Client* p = nullptr;
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
	Client* tail = this->tail;
	while (!(head->next == tail))
	{
		while (!(p == tail))
		{//遍历i后所有
			if (Strcmp2(pre->get_id(), p->get_id()) > 0)
			{
				Client tmp;
				tmp = *pre;
				*pre = *p;
				*p = tmp;
			}
			pre = p;
			p = p->next;
		}
		//补上漏最后一次比较
		if (Strcmp2(pre->get_id(), p->get_id()) > 0)
		{
			Client tmp;
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
void client_list::modify()
{
	int flag = 0;
p:
	cout << "请选择要修改信息的用户名：";
	String a;
	cin >> a;
	Client* c = find_clientid(a);
	if (c == nullptr)
	{
		cout << "用户号：" << a << "不存在，请重新输入......输入其它任意数字继续,输入0返回" << endl;
		cout << "请输入=>";
		cin >> flag;
		if (flag == 0) return;
		goto p;
	}
	else
	{
		cout << "此用户信息为：" << endl;
		c->next->display();
		c = c->next;
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
		{cout << "请输入新用户名："; String b; cin >> b; c->set_clientid(b); break; }
		case 3:
		{
			sfz:
			cout << "请输入新身份证号：";
			String e;
			cin >> e;
			if (e.len() != 18)
			{
				cout << "身份证号长度应为18位，请重新输入......输入任意数字继续，输入0取消" << endl;
				cout << "请输入=>";
				cin >> flag;
				if (!flag)return;
				else goto sfz;
			}
			c->set_id(e); break;
		}
		default:cout << "信息不存在，请重新选择....."; goto pp;
		}
		cout << "修改后的信息为：" << endl;
		c->display();
		cout << "修改成功！" ;
	}
}
void client_list::deletes(Client value)//删除指定值
{
	Client* p = this->find_clientid(value.get_clientid());
	if (p != nullptr)
	{
		Client* tmp = p->next;
		if (tmp != nullptr)
		{
			p ->next= tmp->next;
			delete tmp;
			size--;
		}
		else
		{
			p->next = nullptr;
		}
	}
}
void client_list::Delete()
{
	int flag = 0;
p:
	cout << "请选择要删除信息的用户名：";
	String a;
	cin >> a;
	Client* c = this->find_clientid(a);
	if (c == nullptr)
	{
		cout << "用户名：" << a << "不存在，请重新输入......输入0返回，输入其它任意数字继续" << endl;
		cout << "请输入=>";
		cin >> flag;
		if (flag == 0) return;
		goto p;
	}
	else
	{
		cout << "此用户信息为：" << endl;
		c = c->next;
		c->display();
		cout << "确定要删除吗？[y/n]:";
		char j; cin >> j;
		if (j == 'y' || j == 'Y')
		{
			this->deletes(*c);
			cout << "删除成功！" ;
		}
		else
		{
			cout << "删除失败！";
		}
	}
}
void client_list::Sort()
{
pp:
	cout << "请选择排序类型：" << endl;
	cout << "1. 按用户名\n2. 按姓名\n3. 按身份证号\n";
	int flag = 0;
	cout << "请选择=>";
	cin >> flag;
	switch (flag)
	{
	case 1:BubbleSort_clientid(); break;
	case 2:BubbleSort_clientname(); break;
	case 3:BubbleSort_id(); break;
	default:cout << "信息不存在，请重新选择....."; goto pp;
	}
	cout << "排序完成！";
}
