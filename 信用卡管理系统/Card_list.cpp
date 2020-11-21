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
		cout << "��ѯ��ϣ�һ����" << size << "�����ÿ�" << endl;
	}
	else
	{
		cout << "��Ǹ����ѯ�޽��" << endl;
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
{//�ҵ�Ŀ�����ǰһ�����
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
		//����©���һ�αȽ�
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
		//����©���һ�αȽ�
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
		//����©���һ�αȽ�
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
	cout << "��ѡ��Ҫ�޸���Ϣ�Ŀ��ţ�";
	String a;
	cin >> a;
	CreditCard *c=find_cardnum(a);//�ҵ�Ŀ�����ǰһ��
	if (c == nullptr)
	{
		cout << "���ţ�" << a << "�����ڣ�����������......����0���أ����������������ּ���" << endl;
		cout << "������=>";
		cin >> flag;
		if (flag == 0) return;
		goto p;
	}
	else
	{
	pp:
		cout << "�˿���ϢΪ��" << endl;
		c->next->display();
		c = c->next;
		cout << "��ѡ��Ҫ�޸ĵ���Ϣ,����0����" << endl;
		cout << "������=>";
		cin >> flag;
		switch (flag)
		{
		case 0:return;
		case 1:
		{cout << "�������¿��ţ�"; String a; cin >> a; c->set_num(a); break; }
		case 2:
		{cout << "�����������֣�"; String b; cin >> b; c->set_name(b); break;}
		case 3:
		{cout << "�����������֤�ţ�"; String e; cin >> e; c->set_id(e); break; }
		case 4:
		{cout << "�������¿������У�"; String d; cin >> d; c->set_bank(d); break; }
		case 5:
			cout << "�����������ö�ȣ�"; double f; cin >> f; c->set_Credit_limit(f); break;
		case 7:
			cout << "�����������û��֣�"; double g; cin >> g; c->set_Points(g); break;
		default:cout << "��Ϣ�����ڣ�����������....."; goto pp;
		}
		cout << "�޸ĳɹ���" << endl;
	}
}
void Card_list::deletes(CreditCard value)//ɾ��ָ��ֵ
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
	cout << "������Ҫɾ����Ϣ�Ŀ��ţ�";
	String a;
	cin >> a;
	CreditCard* c = this->find_cardnum(a);
	if (c == nullptr)
	{
		cout << "���ţ�" << a << "�����ڣ�����������......����0���أ����������������ּ���" << endl;
		cout << "������=>";
		cin >> flag;
		if (flag == 0) return;
		goto p;
	}
	else
	{
		String b;
		cout << "�˿���ϢΪ��" << endl;
		c = c->next;
		c->display();
		cout << "ȷ��Ҫɾ����[y/n]:";
		char j; cin >> j;
		if (j == 'y' || j == 'Y')
		{
			this->deletes(*c);
			cout << "ɾ���ɹ���";
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�";
		}
	}
}
void Card_list::Sort()
{
	pp:
	cout << "��ѡ���������ͣ�";
	cout << "1. ������\n2. �����ö��\n3. �����û���\n";
	cout << "��ѡ��=>";
	int flag=0;
	cin >> flag;
	switch (flag)
	{
	case 1:BubbleSort_cardnum(); break;
	case 2:BubbleSort_cardlimit(); break;
	case 3:BubbleSort_cardpoint(); break;
	default:cout << "��Ϣ�����ڣ�������ѡ��....."; goto pp;
	}
	cout << "������ɣ�";
}


