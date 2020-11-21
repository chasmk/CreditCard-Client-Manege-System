#include "Client.h"
#include<iostream>
#include"string.h"
using namespace std;
Client::Client()
{//密码默认为身份证后六位
	my_id = "123456";//身份证号
	my_name = "myname";//姓名
	client_id = "client";//客户账号
	pwd = "123456";
	int l = my_id.len();
	for (int i = 0; i < 6; i++)
	{
		pwd[i] = my_id[l - 6 + i];
	}
	next = nullptr;
}
Client::Client(String cid="client", String n = "myname", String i = "123456",String p="123456") :person(n,i)
{
	client_id = cid;
	int l = my_id.len();
	pwd = p;
	next = nullptr;
}
Client& Client::operator=(Client& a)
{
	set_clientid(a.get_clientid());
	set_id(a.get_id());
	set_name(a.get_name());
	set_pwd(a.get_pwd());
	return *this;
}
void Client::display()
{
	cout << "客户账号：" << client_id << "\n客户名：" << get_name() << "\n身份证号：" << get_id() << endl<<endl;
}
void Client::change_pwd()//修改密码
{
	int flag = 0;
	String old_pwd;
	String new_pwd;
a:
	cout << "旧密码：";
	cin >> old_pwd;
	if ((old_pwd == pwd)!=true)
	{
		cout << "旧密码错误，请重新输入......输入任意数字继续，取消修改请输入0\n";
		cout << "请输入=>";
		cin >> flag;
		if (flag == 0)return;
		goto a;
	}
	else
	{
	b:
		cout << "新密码：";
		cin >> new_pwd;
		int l = new_pwd.len();
		if (l >= 6 && l <= 15)
		{
			pwd = new_pwd;
			cout << "密码修改成功";
		}
		else
		{
			if (new_pwd.len() < 6)
				cout << "密码太短！";
			else cout << "密码过长！";
			cout << "请重新输入......输入任意数字继续，取消修改请输入0\n";
			cout << "请输入=>";
			cin >> flag;
			if (flag == 0)return;
			goto b;
		}
	}
}
void Client::cost_money()//消费
{
	double tmp = 0;
	String Card;
	int size = c.list_size();
	if (size == 0)
	{
		cout << "您的卡包为空，请去办理信用卡" << endl;
		return;
	}
	else
	{
		cout << "请选择要消费的信用卡" << endl;
	}
	Cnode *pp = c.head->next;
	CreditCard* p;
	int i = 1;
	while (pp != nullptr)
	{
		pp->mcard->display();
		i++;
		pp = pp->next;
	}
	int flag = 0;
a:
	cout << "请输入=>";
	cin >> Card;
	p = c.find_Cardid(Card);
	if (p==nullptr)
	{
		cout << "此卡不存在，请重新选择......输入任意数字继续，输入0退出\n";
		cout << "请输入=>";
		cin >> flag;
		if (flag == 0)return;
		goto a;
	}
	else
	{
		double l= p->get_Credit_limit();
		cout << "您的信用额度为：" << l << endl;
		if (l <= 0)
		{
			cout << "信用额度不足，此卡已经被冻结，请尽快充值......输入任意数字返回\n";
			cout << "请输入=>";
			cin >> flag;
			return;
		}
	b:
		cout << "请输入消费金额：";
		double cost = 0;
		cin >> cost;
		if (cost < 0)
		{
			cout << "消费金额不能为负，请重新输入";
			goto b;
		}
		else
		{
			if (l < cost)
			{
				cout << "信用额度不足，请重新输入\n";
				goto b;
			}
			else
			{
				l -= cost;
				p->set_Credit_limit(l);
				double point = p->get_Points();
				point += cost / 10.0;
				p->set_Points(point);
				cout << "本次成功消费：" << cost << "元" << endl;
				cout << "剩余信用额度：" << l << endl;
				cout << "获得信用积分：" << cost / 10.0 << " 当前总信用积分：" << point << endl;
				//更新消费记录
				double* d = p->get_consumption();
				int i = 0;
				for (; i < 10 && d[i] + 1>0.01; i++ );
				if (i == 10) i--;
				for (int j = i; j >= 1; j--) d[j] = d[j - 1];
				d[0] = cost;
			}
		}
		return;
	}

}
void Client::exchange_points()//信用积分兑换
{
	String Card;
	cout << "请选择要兑换的信用卡"<<endl;
	int size = c.list_size();
	if (size == 0)
	{
		cout << "您的卡包为空，请去办理信用卡" << endl;
		return;
	}
	Cnode* pp = c.head->next;
	CreditCard* p;
	int i = 1;
	while (pp != nullptr)
	{
		pp->mcard->display();
		i++;
		pp = pp->next;
	}
	int flag = 0;
a:
	cout << "请输入=>";
	cin >> Card;
	p = c.find_Cardid(Card);
	if (p == nullptr)
	{
		cout << "此卡不存在，请重新选择......输入任意数字继续，输入0退出\n";
		cout << "请输入=>";
		cin >> flag;
		if (flag == 0)return;
		goto a;
	}
	else
	{
		double point = p->get_Points();
		cout << "您当前的信用积分为：" << point << endl;
		cout << "请选择兑换礼品：" << endl;
		cout << "1. 旺旺雪饼 - 2分" << endl;
		cout << "2. 可口可乐 - 5分" << endl;
		cout << "3. 乐事薯片 - 6分" << endl;
		cout << "4. 简易手电筒 - 8分" << endl;
		cout << "5. 睡眠三件套 - 20分" << endl;
		int flag = 0;
	b:
		cout << "请输入=>";
		cin >> flag;
		if (flag < 1 || flag>5)
		{
			cout << "礼品不存在，请重新输入" << endl;
			goto b;
		}
		else
		{
			switch (flag)
			{
			case 1:flag = 2; break;
			case 2:flag = 5; break;
			case 3:flag = 6; break;
			case 4:flag = 8; break;
			case 5:flag = 20; break;
			}
			if (point >= flag)
			{
				point -= flag;
				p->set_Points(point);
				cout << "兑换成功！请凭兑换码：12138 到附近门店兑换礼品，有效期30天......输入任意数字返回" << endl;
				cout << "请输入=>";
				int n = 0; cin >> n;
				return;
			}
			else
			{
				cout << "信用积分不足，请重新选择"<<endl;
					goto b;
			}
		}
	}
}
void Client::new_card(CreditCard *a)//添加信用卡
{
	c.add_Card(a);
	cout << "信用卡开通成功！已加入您的卡包" << endl;
}