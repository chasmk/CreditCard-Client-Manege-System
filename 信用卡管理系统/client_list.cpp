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
		cout << "��ѯ��ϣ�һ����" << size << "λ�û�" << endl;
	}
	else
	{
		cout << "��Ǹ����ѯ�޽��" << endl;
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
//���ҹ���
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
dataType* client_list::find_clientid(String value)//�ҵ�ǰһ�����
{
	dataType* p = head;
	while (!(p->next->get_clientid() == value))
	{
		p = p->next;
		if (p->next == nullptr) return nullptr;
	}
	return p;
}
//������
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
		//����©���һ�αȽ�
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
		//����©���һ�αȽ�
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
		{//����i������
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
		//����©���һ�αȽ�
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
	cout << "��ѡ��Ҫ�޸���Ϣ���û�����";
	String a;
	cin >> a;
	Client* c = find_clientid(a);
	if (c == nullptr)
	{
		cout << "�û��ţ�" << a << "�����ڣ�����������......���������������ּ���,����0����" << endl;
		cout << "������=>";
		cin >> flag;
		if (flag == 0) return;
		goto p;
	}
	else
	{
		cout << "���û���ϢΪ��" << endl;
		c->next->display();
		c = c->next;
	pp:
		cout << "��ѡ��Ҫ�޸ĵ���Ϣ,����0����" << endl;
		cout << "1. ����\n2. �û���\n3. ���֤��" << endl;
		cin >> flag;
		switch (flag)
		{
		case 0:return;
		case 1:
		{cout << "�����������֣�"; String a; cin >> a; c->set_name(a); break; }
		case 2:
		{cout << "���������û�����"; String b; cin >> b; c->set_clientid(b); break; }
		case 3:
		{
			sfz:
			cout << "�����������֤�ţ�";
			String e;
			cin >> e;
			if (e.len() != 18)
			{
				cout << "���֤�ų���ӦΪ18λ������������......�����������ּ���������0ȡ��" << endl;
				cout << "������=>";
				cin >> flag;
				if (!flag)return;
				else goto sfz;
			}
			c->set_id(e); break;
		}
		default:cout << "��Ϣ�����ڣ�������ѡ��....."; goto pp;
		}
		cout << "�޸ĺ����ϢΪ��" << endl;
		c->display();
		cout << "�޸ĳɹ���" ;
	}
}
void client_list::deletes(Client value)//ɾ��ָ��ֵ
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
	cout << "��ѡ��Ҫɾ����Ϣ���û�����";
	String a;
	cin >> a;
	Client* c = this->find_clientid(a);
	if (c == nullptr)
	{
		cout << "�û�����" << a << "�����ڣ�����������......����0���أ����������������ּ���" << endl;
		cout << "������=>";
		cin >> flag;
		if (flag == 0) return;
		goto p;
	}
	else
	{
		cout << "���û���ϢΪ��" << endl;
		c = c->next;
		c->display();
		cout << "ȷ��Ҫɾ����[y/n]:";
		char j; cin >> j;
		if (j == 'y' || j == 'Y')
		{
			this->deletes(*c);
			cout << "ɾ���ɹ���" ;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�";
		}
	}
}
void client_list::Sort()
{
pp:
	cout << "��ѡ���������ͣ�" << endl;
	cout << "1. ���û���\n2. ������\n3. �����֤��\n";
	int flag = 0;
	cout << "��ѡ��=>";
	cin >> flag;
	switch (flag)
	{
	case 1:BubbleSort_clientid(); break;
	case 2:BubbleSort_clientname(); break;
	case 3:BubbleSort_id(); break;
	default:cout << "��Ϣ�����ڣ�������ѡ��....."; goto pp;
	}
	cout << "������ɣ�";
}
