#include "Client.h"
#include<iostream>
#include"string.h"
using namespace std;
Client::Client()
{//����Ĭ��Ϊ���֤����λ
	my_id = "123456";//���֤��
	my_name = "myname";//����
	client_id = "client";//�ͻ��˺�
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
	cout << "�ͻ��˺ţ�" << client_id << "\n�ͻ�����" << get_name() << "\n���֤�ţ�" << get_id() << endl<<endl;
}
void Client::change_pwd()//�޸�����
{
	int flag = 0;
	String old_pwd;
	String new_pwd;
a:
	cout << "�����룺";
	cin >> old_pwd;
	if ((old_pwd == pwd)!=true)
	{
		cout << "�������������������......�����������ּ�����ȡ���޸�������0\n";
		cout << "������=>";
		cin >> flag;
		if (flag == 0)return;
		goto a;
	}
	else
	{
	b:
		cout << "�����룺";
		cin >> new_pwd;
		int l = new_pwd.len();
		if (l >= 6 && l <= 15)
		{
			pwd = new_pwd;
			cout << "�����޸ĳɹ�";
		}
		else
		{
			if (new_pwd.len() < 6)
				cout << "����̫�̣�";
			else cout << "���������";
			cout << "����������......�����������ּ�����ȡ���޸�������0\n";
			cout << "������=>";
			cin >> flag;
			if (flag == 0)return;
			goto b;
		}
	}
}
void Client::cost_money()//����
{
	double tmp = 0;
	String Card;
	int size = c.list_size();
	if (size == 0)
	{
		cout << "���Ŀ���Ϊ�գ���ȥ�������ÿ�" << endl;
		return;
	}
	else
	{
		cout << "��ѡ��Ҫ���ѵ����ÿ�" << endl;
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
	cout << "������=>";
	cin >> Card;
	p = c.find_Cardid(Card);
	if (p==nullptr)
	{
		cout << "�˿������ڣ�������ѡ��......�����������ּ���������0�˳�\n";
		cout << "������=>";
		cin >> flag;
		if (flag == 0)return;
		goto a;
	}
	else
	{
		double l= p->get_Credit_limit();
		cout << "�������ö��Ϊ��" << l << endl;
		if (l <= 0)
		{
			cout << "���ö�Ȳ��㣬�˿��Ѿ������ᣬ�뾡���ֵ......�����������ַ���\n";
			cout << "������=>";
			cin >> flag;
			return;
		}
	b:
		cout << "���������ѽ�";
		double cost = 0;
		cin >> cost;
		if (cost < 0)
		{
			cout << "���ѽ���Ϊ��������������";
			goto b;
		}
		else
		{
			if (l < cost)
			{
				cout << "���ö�Ȳ��㣬����������\n";
				goto b;
			}
			else
			{
				l -= cost;
				p->set_Credit_limit(l);
				double point = p->get_Points();
				point += cost / 10.0;
				p->set_Points(point);
				cout << "���γɹ����ѣ�" << cost << "Ԫ" << endl;
				cout << "ʣ�����ö�ȣ�" << l << endl;
				cout << "������û��֣�" << cost / 10.0 << " ��ǰ�����û��֣�" << point << endl;
				//�������Ѽ�¼
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
void Client::exchange_points()//���û��ֶһ�
{
	String Card;
	cout << "��ѡ��Ҫ�һ������ÿ�"<<endl;
	int size = c.list_size();
	if (size == 0)
	{
		cout << "���Ŀ���Ϊ�գ���ȥ�������ÿ�" << endl;
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
	cout << "������=>";
	cin >> Card;
	p = c.find_Cardid(Card);
	if (p == nullptr)
	{
		cout << "�˿������ڣ�������ѡ��......�����������ּ���������0�˳�\n";
		cout << "������=>";
		cin >> flag;
		if (flag == 0)return;
		goto a;
	}
	else
	{
		double point = p->get_Points();
		cout << "����ǰ�����û���Ϊ��" << point << endl;
		cout << "��ѡ��һ���Ʒ��" << endl;
		cout << "1. ����ѩ�� - 2��" << endl;
		cout << "2. �ɿڿ��� - 5��" << endl;
		cout << "3. ������Ƭ - 6��" << endl;
		cout << "4. �����ֵ�Ͳ - 8��" << endl;
		cout << "5. ˯�������� - 20��" << endl;
		int flag = 0;
	b:
		cout << "������=>";
		cin >> flag;
		if (flag < 1 || flag>5)
		{
			cout << "��Ʒ�����ڣ�����������" << endl;
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
				cout << "�һ��ɹ�����ƾ�һ��룺12138 �������ŵ�һ���Ʒ����Ч��30��......�����������ַ���" << endl;
				cout << "������=>";
				int n = 0; cin >> n;
				return;
			}
			else
			{
				cout << "���û��ֲ��㣬������ѡ��"<<endl;
					goto b;
			}
		}
	}
}
void Client::new_card(CreditCard *a)//������ÿ�
{
	c.add_Card(a);
	cout << "���ÿ���ͨ�ɹ����Ѽ������Ŀ���" << endl;
}