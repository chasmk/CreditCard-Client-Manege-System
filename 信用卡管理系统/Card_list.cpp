#include "Card_list.h"
#include<fstream>
int Strcmp1(const char* s1, const char* s2)
{
	for (int i = 0; s1[i] && s2[i]; ++i) {
		if (s1[i] < s2[i])
			return -1;
		else if (s1[i] > s2[i])
			return 1;
	}
	return 0;
}
Card_list::Card_list()
{
	head = tail =new CreditCard;
	size = 0;
}
Card_list::~Card_list()
{
	CreditCard* p = head;
	while (head)
	{
		head = head->next;
		delete p;
		p = head;
	}
}
void Card_list::show()
{
	CreditCard* p = head->next;
	if (p != nullptr)
	{
		while (p != nullptr)
		{
			p->display();
			p = p->next;
		}
		cout << "查询完毕！一共有" << size << "张信用卡" << endl;
	}
	else
	{
		cout << "抱歉，查询无结果" << endl;
	}
}
int Card_list::list_size()const
{
	return size;
}
void Card_list::outputfile()
{
	ofstream outcard("Card.txt", ios::out);
	CreditCard* p = head->next;
	while (p != nullptr)
	{
		outcard << p->get_num() << " " << p->get_man()->get_name() << " " << p->get_man()->get_id() << " " << p->get_bank()
			<< " " << p->get_Credit_limit() << " " << p->get_Points();
		double* cost = p->get_consumption();
		int i = 0;
		for (; cost[i] + 1 > 0.01 && i < 10; i++);
		if (i == 0)outcard << " " << 0;
		else {
			outcard << " " << i;
			for (int k = 0; k < i; k++)outcard << " " << cost[k];
		}
		outcard << endl;
		p = p->next;
	}
}
CreditCard* Card_list::add_tail(CreditCard value)
{
	tail->next = new CreditCard(value);
	tail = tail->next;
	tail->next = nullptr;
	size++;
	return tail;
}
CreditCard* Card_list::find_cardnum(String value)
{//找到目标结点的前一个结点
	CreditCard* p= head;
	while (!(p->next->get_num() == value))
	{
		p = p->next;
		if (p->next == nullptr) return nullptr;
	}
	return p;
}
CreditCard* Card_list::find_cardname(String value)
{
	CreditCard* p = head->next;
	while (p && !(p->get_man()->get_name() == value))p = p->next;
	return p;
}
CreditCard* Card_list::find_cardidnum(String value)
{
	CreditCard* p = head->next;
	while (p && !(p->get_man()->get_id() == value))p = p->next;
	return p;
}
CreditCard* Card_list::find_cardcredit(double value)
{
	CreditCard* p = head->next;
	while (p && !(p->get_Credit_limit() == value))p = p->next;
	return p;
}
CreditCard* Card_list::BubbleSort_cardnum()
{
	CreditCard* pre = head->next;
	CreditCard* p = nullptr;
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
	CreditCard* tail = this->tail;
	while (!(head->next ==tail))
	{
		while (!(p == tail))
		{
			if (Strcmp1(pre->get_num(), p->get_num()) > 0)
			{
				CreditCard tmp;
				tmp = *pre;
				*pre = *p;
				*p = tmp;
			}
			pre = p;
			p = p->next;
		}
		//补上漏最后一次比较
		if (Strcmp1(pre->get_num(), p->get_num()) > 0)
		{
			CreditCard tmp;
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
CreditCard* Card_list::BubbleSort_cardlimit()
{
	CreditCard* pre = head->next;
	CreditCard* p = nullptr;
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
	CreditCard* tail = this->tail;
	while (!(head->next == tail))
	{
		while (!(p == tail))
		{
			if (pre->get_Credit_limit() > p->get_Credit_limit())
			{
				CreditCard tmp;
				tmp = *pre;
				*pre = *p;
				*p = tmp;
			}
			pre = p;
			p = p->next;
		}
		//补上漏最后一次比较
		if (pre->get_Credit_limit() > p->get_Credit_limit())
		{
			CreditCard tmp;
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
CreditCard* Card_list::BubbleSort_cardpoint()
{
	CreditCard* pre = head->next;
	CreditCard* p = nullptr;
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
	CreditCard* tail = this->tail;
	while (!(head->next == tail))
	{
		while (!(p == tail))
		{
			if (pre->get_Points() > p->get_Points())
			{
				CreditCard tmp;
				tmp = *pre;
				*pre = *p;
				*p = tmp;
			}
			pre = p;
			p = p->next;
		}
		//补上漏最后一次比较
		if (pre->get_Points() > p->get_Points())
		{
			CreditCard tmp;
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
void Card_list::modify()
{
	int flag = 0;
	p:
	cout << "请选择要修改信息的卡号：";
	String a;
	cin >> a;
	CreditCard *c=find_cardnum(a);//找到目标结点的前一个
	if (c == nullptr)
	{
		cout << "卡号：" << a << "不存在，请重新输入......输入0返回，输入其它任意数字继续" << endl;
		cout << "请输入=>";
		cin >> flag;
		if (flag == 0) return;
		goto p;
	}
	else
	{
	pp:
		cout << "此卡信息为：" << endl;
		c->next->display();
		c = c->next;
		cout << "请选择要修改的信息,输入0返回" << endl;
		cout << "请输入=>";
		cin >> flag;
		switch (flag)
		{
		case 0:return;
		case 1:
		{cout << "请输入新卡号："; String a; cin >> a; c->set_num(a); break; }
		case 2:
		{cout << "请输入新名字："; String b; cin >> b; c->set_name(b); break;}
		case 3:
		{cout << "请输入新身份证号："; String e; cin >> e; c->set_id(e); break; }
		case 4:
		{cout << "请输入新开户银行："; String d; cin >> d; c->set_bank(d); break; }
		case 5:
			cout << "请输入新信用额度："; double f; cin >> f; c->set_Credit_limit(f); break;
		case 7:
			cout << "请输入新信用积分："; double g; cin >> g; c->set_Points(g); break;
		default:cout << "信息不存在，请重新输入....."; goto pp;
		}
		cout << "修改成功！" << endl;
	}
}
void Card_list::deletes(CreditCard value)//删除指定值
{
	CreditCard *p = this->find_cardnum(value.get_num());
	if (p != nullptr)
	{
		CreditCard* tmp = p->next;
		if (tmp != nullptr)
		{
			p->next = tmp->next;
			delete tmp;
			size--;
		}
		else
		{
			p->next = nullptr;
		}
	}
}
void Card_list::Delete()
{
	int flag = 0;
p:
	cout << "请输入要删除信息的卡号：";
	String a;
	cin >> a;
	CreditCard* c = this->find_cardnum(a);
	if (c == nullptr)
	{
		cout << "卡号：" << a << "不存在，请重新输入......输入0返回，输入其它任意数字继续" << endl;
		cout << "请输入=>";
		cin >> flag;
		if (flag == 0) return;
		goto p;
	}
	else
	{
		String b;
		cout << "此卡信息为：" << endl;
		c = c->next;
		c->display();
		cout << "确定要删除吗？[y/n]:";
		char j; cin >> j;
		if (j == 'y' || j == 'Y')
		{
			this->deletes(*c);
			cout << "删除成功！";
		}
		else
		{
			cout << "删除失败！";
		}
	}
}
void Card_list::Sort()
{
	pp:
	cout << "请选择排序类型：";
	cout << "1. 按卡号\n2. 按信用额度\n3. 按信用积分\n";
	cout << "请选择=>";
	int flag=0;
	cin >> flag;
	switch (flag)
	{
	case 1:BubbleSort_cardnum(); break;
	case 2:BubbleSort_cardlimit(); break;
	case 3:BubbleSort_cardpoint(); break;
	default:cout << "信息不存在，请重新选择....."; goto pp;
	}
	cout << "排序完成！";
}


