#include"manager_list.h"
#include"client_list.h"
#include"Card_list.h"
#include"String.h"
#include<fstream>
#include<iostream>
using namespace std;
void welcom();//��ӭ����
void clientlogin();//�û���½����
void oldclientlogin();//���û���½
void newclientsignin();//���û�ע��
void managerlogin();//����Ա��½����
void managers();//����Ա����
void informquery();//��Ϣ��ѯ����
void advancedquery();//�߼���ѯ
void business();//ҵ���ѯ
CreditCard* newcard(Client*,int); //�½���

int flag = 0;
client_list clist;//�ͻ���
manager_list mlist;//����Ա��
Card_list cardlist;//���ÿ���
ifstream inclient("Client.txt", ios::in);
ifstream inmanager("manager.txt", ios::in);
ifstream incard("Card.txt", ios::in);
ofstream outclient("Client.txt", ios::app);//׷����ĩβ
ofstream outmanager("manager.txt", ios::app);
ofstream outcard("Card.txt", ios::app);

int main()
{
	String name, id, cid, pwd,mid;
	String cardid, bank; double  limit=0, point=0; int sum;
	while (inclient >> cid >> name >> id>>pwd)
	{
		Client tmp(cid, name, id,pwd);
		clist.add_tail(tmp);
	}
	while (inmanager >> mid >> name >> id>>pwd)
	{
		Manager tmp(mid, name, id,pwd);
		mlist.add_tail(tmp);
	}
	while (incard >> cardid >> name >> id >> bank >> limit>>point >> sum)
	{
		Client* ctmp = clist.find_myid(id);
		person* per;
		if (ctmp != nullptr)
			per = new person(ctmp->get_name(), ctmp->get_id());
		else
		{
			per = new person("nullname", "nullid");
		}
		CreditCard tmp(per, cardid, bank, limit, point);
		int s = sum;
		if (s != 0)
		{
			int i = 0;
			double* temp = new double[s];
			while (s != 0)
			{
				incard >> temp[i++];
				s--;
			}
			double* temp1 = tmp.get_consumption();
			for (int j = 0; j < i; j++)temp1[j] = temp[j];
		}
		CreditCard* p = cardlist.add_tail(tmp);//ͬʱ���б���Ӵ˿�
		if (ctmp != nullptr)
		{
			ctmp->c.add_Card(p);//���ҵ��ͻ�id ����ͻ���������Ӵ˿�
		}
	}

	inclient.close();
	incard.close();
	inmanager.close();

	//------------������----------------//
a0:
	welcom();
	cout << "������=>";
	cin >> flag;
	system("cls");
	switch (flag)
	{
	case 0:goto a4;
	case 1:goto a1;//�û���½
	case 2:goto a2;//����Ա��½
	case 3:goto a3;//ҵ���ѯ
	default:cout << "���벻��ȷ������������" << endl; goto a0;
	}
//-----------------------------------------------------------------------------------------------//
	//------------�û���½����----------------//
a1:
	clientlogin();
b10:
	cout << "������=>";
	cin >> flag;
	//system("cls");
	switch (flag)
	{
	case 0:system("cls"); goto a0;//�����ϲ�
	case 1:goto b11;//���û���½
	case 2:goto b12;//���û�ע��
	default:cout << "���벻��ȷ������������" << endl; goto b10;
	}
b11:
	oldclientlogin();//���û���½
	goto a1;
b12:
	newclientsignin();//���û�ע��
	goto a1;
//-----------------------------------------------------------------------------------------------//
	//------------����Ա��½����----------------//
a2:
	system("cls");
	managerlogin();
b20:
	cout << "������=>";
	cin >> flag;
	system("cls");
	switch (flag)
	{
	case 0:goto a0;//�����ϲ�
	case 1:goto b21;//����Ա��½
	default:cout << "���벻��ȷ������������" << endl; goto b20;
	}
b21:
	managers();//����Ա��½
	goto a2;
//-----------------------------------------------------------------------------------------------//
	//------------ҵ���ѯ����----------------//
a3:
	system("cls");
	business();
	goto a0;

a4:
	cout << " --------------------------------------" << endl;
	cout << "|           ��лʹ�ã��ټ���           |" << endl;
	cout << " --------------------------------------" << endl;
	outclient.close();
	outcard.close();
	outmanager.close();
	return 0;
}

void welcom()
{
	cout << "--------------------------------------" << endl;
	cout << "|        ���ÿ��ͻ�����ϵͳ          |" << endl;
	cout << "|                                    |" << endl;
	cout << "|       �������Ӧ���ַ��ʲ˵�       |" << endl;
	cout << "|       0-�˳�ϵͳ                   |" << endl;
	cout << "|       1-�û�ģ��                   |" << endl;
	cout << "|       2-����Աģ��                 |" << endl;
	cout << "|       3-ҵ���ѯ                   |" << endl;
	cout << "--------------------------------------" << endl;
}
void clientlogin()
{
	cout << "--------------------------------------" << endl;
	cout << "|        ��ӭ�����û���½����        |" << endl;
	cout << "|                                    |" << endl;
	cout << "|       �������Ӧ���ַ��ʹ���       |" << endl;
	cout << "|       0-�����ϲ�                   |" << endl;
	cout << "|       1-���û���½                 |" << endl;
	cout << "|       2-���û�ע��                 |" << endl;
	cout << "--------------------------------------" << endl;

}
void oldclientlogin()//���û���½
{

	int flag = 0;
a:
	cout << "�������û�����";
	String cid;
	cin >> cid;
	Client* p = clist.find_clientid(cid);//find_clientid()�ҵ�ǰһ�����
	if (p == nullptr)
	{
		cout << "�û�����δע��......1 �������룬0�����ϲ�" << endl;
		cout << "������=>";
		cin >> flag;
		if (flag) goto a;
		else
		{
			system("cls");
			return;
		}
	}
	else
	{
		p = p->next;
	ab:
		String pwd;
		cout << "���������룺";
		cin >> pwd;
		cout << "��ȷ������ʾ#" << p->get_pwd() << "#" << endl;
		if (p->get_pwd() == pwd)
		{
			cout << "��½�ɹ���,�����������ּ���...." << endl;
			cout << "������=>";
			cin >> flag;
			system("cls");
			goto b;
		}
		else
		{
			cout << "�������......1 �������룬0�����ϲ�" << endl;
			cout << "������=>";
			cin >> flag;
			if (flag) goto ab;
			else
			{
				system("cls");
				return;
			}
		}
	}
b:
	cout << "--------------------------------------" << endl;
	cout << "|        " << p->get_name() << "!    ��ӭ��           |" << endl;
	cout << "|                                    |" << endl;
	cout << "|       �������Ӧ���ַ��ʹ���       |" << endl;
	cout << "|       0-������һ��                 |" << endl;
	cout << "|       1-�鿴������Ϣ               |" << endl;
	cout << "|       2-�޸�����                   |" << endl;
	cout << "|       3-���ѽ��                   |" << endl;
	cout << "|       4-���û��ֶһ�               |" << endl;
	cout << "|       5-��ͨ���ÿ�                 |" << endl;
	cout << "--------------------------------------" << endl;
b10:
	//Cnode* p1;
	Cnode* node = p->c.head->next;
	cout << "������=>";
	cin >> flag;
	system("cls");
	switch (flag)
	{
	case 0:return;//������һ��
	case 1:goto a1;//�鿴������Ϣ
	case 2:goto a2;//�޸�����
	case 3:goto a3;//���ѽ��
	case 4:goto a4;//���û��ֶһ�
	case 5:goto a5;//��ͨ���ÿ�
	default:cout << "���벻��ȷ������������" << endl; goto b10;
	}
a1:
	p->display();
	if (p->c.list_size() == 0)cout << "���ÿ��б�Ϊ��" << endl;
	else
	{
		while (node != nullptr)
		{
			node->mcard->display();
			node = node->next;
		}
		cout << "����չʾ��ϣ�һ����" << p->c.list_size() << "�ſ�" << endl;
	}
	goto c;
a2:
	p->change_pwd(); clist.outputfile(); goto c;
a3:
	p->cost_money(); cardlist.outputfile(); goto c;
a4:
	p->exchange_points(); cardlist.outputfile(); goto c;
a5:
	{
		CreditCard* tmp = newcard(p, 1);
		p->new_card(tmp);
		goto c;
	}
c:
cout << "�����������ּ���...." << endl;
cout << "������=>";
cin >> flag;
system("cls");
goto b;
}//
void newclientsignin()//���û�ע��
{
	cout << "���������ĸ�����Ϣ" << endl;
	String name;
	String id;
	cout << "������";
	cin >> name;
sfz:
	cout << "���֤�ţ�";
	cin >> id;
	if (id.len() != 18)
	{
		cout << "���֤�ų���ӦΪ18λ������������......�����������ּ���������0ȡ��" << endl;
		cin >> flag;
		if (!flag) return;
		else goto sfz;
	}
	String pwd = id.subString(id, 12, 6);
	int l = clist.list_size();
	l++;//���������û���
	String cid = "000";
	for (int i = 0; i < 3 && l != 0; i++)
	{
		cid[2 - i] = l % 10 + '0';
		l /= 10;
	}
	cout << "cid:" << cid << endl;
	Client ctmp(cid, name, id,pwd);
	Client* tmp = clist.add_tail(ctmp);//��ӵ��ͻ�����
	outclient << ctmp.get_clientid() << " " << ctmp.get_name() << " " << ctmp.get_id() <<" "<<ctmp.get_pwd()<< endl;
	cout << "�����û�����" << ctmp.get_clientid() << endl << "����Ĭ�����룺" << ctmp.get_pwd() << endl;
	cout << "�˺Ŵ����ɹ���......�����������ּ���" << endl;
	cout << "������=>";
	cin >> flag;
	system("cls");
}
void managerlogin()
{
	cout << " --------------------------------------" << endl;
	cout << "|        ��ӭ��������Ա��½����       |" << endl;
	cout << "|                                     |" << endl;
	cout << "|       �������Ӧ���ַ��ʹ���        |" << endl;
	cout << "|       0-������һ��                  |" << endl;
	cout << "|       1-����Ա��½                  |" << endl;
	cout << " --------------------------------------" << endl;
}
void managers()//����Ա����
{
	String mid;
	String pwd;
	int flag = 0;
a:
	system("cls");
	cout << "���������Ա�ţ�";
	cin >> mid;
	Manager* p = mlist.find_managerid(mid);
	if (p == nullptr)
	{
		cout << "����Ա��δע��......1 �������룬0�����ϲ�" << endl;
		cout << "������=>";
		cin >> flag;
		if (flag) goto a; else return;
	}
	else
	{
		p = p->next;
		cout << "���������룺";
		cin >> pwd;
		if (p->get_pwd() == pwd)
		{
			cout << "��½�ɹ���......�����������ּ���" << endl;
			cout << "������=>";
			cin >> flag;
			goto b;
		}
		else
		{
			cout << "��ȷ���룺" << p->get_pwd() << "#" << endl;
			cout << "�������......1 �������룬0�����ϲ�" << endl;
			cout << "������=>";
			cin >> flag;
			if (flag) goto a; else return;
		}
	}
b:
	system("cls");
	cout << " --------------------------------------" << endl;
	cout << "|        " << p->get_name() << "    ��ӭ��!         |" << endl;
	cout << "|                                     |" << endl;
	cout << "|       �������Ӧ���ַ��ʹ���        |" << endl;
	cout << "|       0-������һ��                  |" << endl;
	cout << "|       1-��ʾ������Ϣ                |" << endl;
	cout << "|       2-�޸�����                    |" << endl;
	cout << "|       3-�½��û�                    |" << endl;
	cout << "|       4-�½����ÿ�                  |" << endl;
	cout << "|       5-�޸���Ϣ                    |" << endl;
	cout << "|       6-ɾ����Ϣ                    |" << endl;
	cout << "|       7-����������Ϣ                |" << endl;
	cout << "|       8-��Ϣ�鿴                    |" << endl;
	cout << " --------------------------------------" << endl;
b10:
	cout << "������=>";
	cin >> flag;
	system("cls");
	switch (flag)
	{
	case 0:return;//������һ��
	case 1:goto a1;//�鿴������Ϣ
	case 2:goto a2;//�޸�����
	case 3:goto a3;//�½��û�
	case 4:goto a4;//�½����ÿ�
	case 5:goto a5;//�޸���Ϣ
	case 6:goto a6;//ɾ����Ϣ
	case 7:goto a7;//����������Ϣ
	case 8:goto a8;//��Ϣ�鿴
	default:cout << "���벻��ȷ������������" << endl; goto b10;
	}
a1:
	p->display(); goto c;
a2:
	p->change_pwd(); mlist.outputfile(); goto c;
a3:
	{
		cout << "���������û��ĸ�����Ϣ" << endl;
		String name;
		String id;
		cout << "������";
		cin >> name;
	sfz:
		cout << "\n���֤�ţ�";
		cin >> id;
		if (id.len() != 18)
		{
			cout << "���֤�ų���ӦΪ18λ������������......�����������ּ���������0ȡ��" << endl;
			cout << "������=>";
			cin >> flag;
			if (!flag)goto c;
			else goto sfz;
		}
		String pwd = id.subString(id, 12, 6);
		int l = clist.list_size();
		l++;//���������û���
		String cid = "000";
		for (int i = 0; i < 3 && l != 0; i++)
		{
			cid[2 - i] = l % 10 + '0';
			l /= 10;
		}
		Client ctmp(cid, name, id,pwd);
		clist.add_tail(ctmp);
		outclient << ctmp.get_clientid() << " " << ctmp.get_name() << " " << ctmp.get_id()<<" "<<ctmp.get_pwd()<<endl;
		cout << "���û�: \n"; ctmp.display(); cout << "�����ɹ���" << endl;
		goto c; }
a4:
	{
		newcard(nullptr, 0);
		goto c; }
a5:
	{
		cout << "��ѡ��Ҫ�޸ĵ����ݣ�" << endl;
		cout << "1. �û���Ϣ�޸�\n2. ���ÿ���Ϣ�޸�" << endl;
	mb:
		cout << "������=>";
		cin >> flag;
		switch (flag)
		{
		case 1:clist.modify(); clist.outputfile(); break;
		case 2:cardlist.modify(); cardlist.outputfile(); break;
		default:cout << "��Ų�����,����������"; goto mb;
		}
		goto c; }
a6:
	{
		cout << "��ѡ��Ҫɾ�������ݣ�" << endl;
		cout << "1. �û���Ϣɾ��\n2. ���ÿ���Ϣɾ��" << endl;
	mc:
		cout << "������=>";
		cin >> flag;
		switch (flag)
		{
		case 1:clist.Delete(); clist.outputfile(); break;
		case 2:cardlist.Delete(); cardlist.outputfile(); break;
		default:cout << "��Ų����ڣ�����������"; goto mc;
		}
		goto c;
	}
a7:
	{
		cout << "��ѡ��Ҫ������������ݣ�" << endl;
		cout << "1. �û���Ϣ\n2. ���ÿ���Ϣ\n3. ����Ա��Ϣ" << endl;
	md:
		cout << "������=>";
		cin >> flag;
		switch (flag)
		{
		case 1:clist.Sort(); clist.outputfile(); break;
		case 2:cardlist.Sort(); cardlist.outputfile(); break;
		case 3:mlist.Sort(); mlist.outputfile(); break;
		default:cout << "��Ų����ڣ�����������" << endl; goto md;
		}
		goto c;
	}
a8:
	system("cls");
	informquery();
b30:
	cin >> flag;
	system("cls");
	switch (flag)
	{
	case 0:goto b;//�����ϲ�
	case 1:goto b31;//�û���ѯ
	case 2:goto b32;//����Ա��ѯ
	case 3:goto b33;//���ÿ���ѯ
	case 4:goto b34;//�߼���ѯ
	default:cout << "���벻��ȷ������������" << endl; goto b30;
	}
b31:clist.show(); goto b35;
b32:mlist.show(); goto b35;
b33:cardlist.show(); goto b35;
b34:advancedquery(); goto
a8;
b35:
cout << "......�����������ּ���" << endl;
cout << "������=>";
cin >> flag;
goto a8;
c:
cout << "......�����������ּ���" << endl;
cout << "������=>";
cin >> flag;
goto b;
}
void informquery()//��Ϣ��ѯ����
{
	cout << "--------------------------------------" << endl;
	cout << "|        ��ӭ������Ϣ��ѯ����        |" << endl;
	cout << "|                                    |" << endl;
	cout << "|       �������Ӧ���ַ��ʹ���       |" << endl;
	cout << "|       0-�����ϲ�                   |" << endl;
	cout << "|       1-�û���ѯ                   |" << endl;
	cout << "|       2-����Ա��ѯ                 |" << endl;
	cout << "|       3-���ÿ���ѯ                 |" << endl;
	cout << "|       4-�߼���ѯ                   |" << endl;
	cout << "--------------------------------------" << endl;
}
void advancedquery()//�߼���ѯ
{
a:
	system("cls");
	cout << " --------------------------------------" << endl;
	cout << "|       ��ӭ�����߼���ѯ����          |" << endl;
	cout << "|                                     |" << endl;
	cout << "|       �������Ӧ���ַ��ʹ���        |" << endl;
	cout << "|       0-������һ��                  |" << endl;
	cout << "|       1-�����Ų�ѯ                  |" << endl;
	cout << "|       2-���û�������ѯ              |" << endl;
	cout << "|       3-�����֤����                |" << endl;
	cout << "|       4-���û��ֲ�ѯ                |" << endl;
	cout << " --------------------------------------" << endl;
	String cardid;
	String name;
	double credit;
	String id;
	CreditCard* ctmp1;
	CreditCard* ctmp4;
	Client* tmp3;
	Client* tmp4;
b30:
	cout << "������=>";
	cin >> flag;
	switch (flag)
	{
	case 0:return;//�����ϲ�
	case 1:goto b31;//�����Ų�ѯ
	case 2:goto b32;//���û�������ѯ
	case 3:goto b33;//�����֤�Ų�ѯ
	case 4:goto b34;//�����û��ֲ�ѯ
	default:cout << "���벻��ȷ������������" << endl; goto b30;
	}
b31:
	cout << "���������ѯ����=>";
	cin >> cardid;
	ctmp1 = cardlist.find_cardnum(cardid);
	if (ctmp1 == nullptr)
	{
		cout <<cardid<<" "<< "��ѯ�޽��! " ;
	}
	else
	{
		ctmp1->next->display();
	}
	goto c;
b32:
	cout << "���������ѯ�û�������";
	cin >> name;

	tmp3 = clist.find_myname(name);
	if (tmp3 == nullptr)
	{
		cout <<name<<" "<< "��ѯ�޽��! " << endl;
	}
	else
	{
		Cnode *p=tmp3->c.head->next;
		while (p != nullptr)
		{
			p->mcard->display();
			p = p->next;
		}
	}
	goto c;
b33:
	cout << "���������ѯ���֤�ţ�";
	cin >> id;

	tmp4 = clist.find_myid(id);
	if (tmp4 == nullptr)
	{
		cout << id << " " << "��ѯ�޽��! " << endl;
	}
	else
	{
		Cnode* p = tmp4->c.head->next;
		while (p != nullptr)
		{
			p->mcard->display();
			p = p->next;
		}
	}
	goto c;
b34:
	cout << "���������ѯ���û��֣�";
	cin >> credit;
	ctmp4 = cardlist.find_cardcredit(credit);
	if (ctmp4 == nullptr)
	{
		cout<< credit<<" " << "��ѯ�޽��! " << endl;
	}
	else
	{
		ctmp4->display();
	}
	goto c;

c:
	cout << "�����������ּ���" << endl;
	cout << "������=>"; cin >> flag;
	goto a;
}
void business()
{
a:
	ofstream outfeed("feedback.txt", ios::app);
	String s;
	system("cls");
	cout << "--------------------------------------" << endl;
	cout << "|        ��ӭ����ҵ���ѯ����        |" << endl;
	cout << "|                                    |" << endl;
	cout << "|       �������Ӧ���ַ��ʹ���       |" << endl;
	cout << "|       0-�����ϲ�                   |" << endl;
	cout << "|       1-���в�ѯ                   |" << endl;
	cout << "|       2-���ö�Ȳ�ѯ               |" << endl;
	cout << "|       3-���û����ƶȲ�ѯ           |" << endl;
	cout << "|       4-�������                   |" << endl;
	cout << "--------------------------------------" << endl;
b30:
	cout << "������=>";
	cin >> flag;
	system("cls");
	switch (flag)
	{
	case 0:return;//�����ϲ�
	case 1:goto b31;//���в�ѯ
	case 2:goto b32;//���ö�Ȳ�ѯ
	case 3:goto b33;//���û����ƶȲ�ѯ
	case 4:goto b34;//�������
	default:cout << "���벻��ȷ������������" << endl; goto b30;
	}
b31:
	cout << "----------------------------------------------" << endl;
	cout << "|   ����˾���������н����������������ϵ   |" << endl;
	cout << "|                                            |" << endl;
	cout << "|     Ϊ���ṩ*������*,*��ɿ�*���Ŵ�����    |" << endl;
	cout << "|                                            |" << endl;
	cout << "|           *�й���������*                   |" << endl;
	cout << "|           *�й���������*                   |" << endl;
	cout << "|           *�й�ũҵ����*                   |" << endl;
	cout << "|           *�й���������*                   |" << endl;
	cout << "|           δ�����......                   |" << endl;
	cout << "---------------------------------------------" << endl;
	goto b35;
b32:
	cout << "-----------------------------------------" << endl;
	cout << "|      ����˾�ṩ���¶�ȵ����ô���     |" << endl;
	cout << "|                                       |" << endl;
	cout << "|                                       |" << endl;
	cout << "|             *500��*                   |" << endl;
	cout << "|             *1000��*                  |" << endl;
	cout << "|             *2000��*                  |" << endl;
	cout << "|             *5000��*                  |" << endl;
	cout << "|             *10000��*                 |" << endl;
	cout << "|             δ�����......            |" << endl;
	cout << "-----------------------------------------" << endl;
	goto b35;
b33:
	cout << "--------------------------------------" << endl;
	cout << "|      ����˾�����û����ƶ�����      |" << endl;
	cout << "|                                    |" << endl;
	cout << "|      ÿ100Ԫ�Ĵ��������           |" << endl;
	cout << "|              ||                    |" << endl;
	cout << "|             \\||/                   |" << endl;
	cout << "|              \\/                    |" << endl;
	cout << "|             1����                  |" << endl;
	cout << "--------------------------------------" << endl;
	goto b35;
b34:
	cout << "������������������������#������" << endl;
	cout << "������=>";
	outfeed << endl << ">>>" << endl;
	while (cin >> s)
	{
		if (s.findchar('#'))
		{
			outfeed << s;
			break;
		}
		else outfeed << s;
	}
	cout << "��л����֧��" << endl;
	outfeed.close();
	goto b35;
b35:
	cout << "�����������ּ���" << endl;
	cout << "������=>";
	cin >> flag;
	goto a;
}
CreditCard* newcard(Client* x,int i) //�����ÿ���ͨ x==0����Ա��ͨ x==1�û���ͨ
{
	cout << "��ѡ�����Ŀ�������" << endl;
	cout << "1. �й���������\n2. �й���������\n3. �й�ũҵ����\n4. �й���������" << endl;
cb:
	cin >> flag;
	String bank;
	switch (flag)
	{
	case 1:bank ="�й���������"; break;
	case 2:bank ="�й���������"; break;
	case 3:bank ="�й�ũҵ����"; break;
	case 4:bank = "�й���������"; break;
	default:cout << "���в����ڣ�����������"; goto cb;
	}
	cout << "��ѡ���������ö��" << endl;
	cout << "1. 500\n2. 2000\n3. 5000\n4. 10000" << endl;
	double credit;
db:
	cin >> flag;
	switch (flag)
	{
	case 1:credit = 500; break;
	case 2:credit = 2000; break;
	case 3:credit = 5000; break;
	case 4:credit = 10000; break;
	default:cout << "���ö�Ȳ����ڣ�����������" << endl; goto db;
	}

	int l = cardlist.list_size();
	l++;//�������ɿ���
	String cnum = "000";
	for (int i = 0; i < 3&&l!=0; i++)
	{
		cnum[2-i] = l % 10+'0';
		l /= 10;
	}
	double point = credit / 100;
	cout << "�����������" << endl;
	if (i == 0)//����ǹ���Ա�½���
	{
		cout << "��ѡ��Ҫ�󶨵��û���,�����������ּ���ѡ���ݲ���������0" << endl;
	ccb:
		cout << "������=>";
		cin >> flag;
		Client* ctmp = new Client;
		if (flag)
		{
			clist.show();
			cout << "������Ҫѡ����û���";
			String client; cin >> client;
			Client* tt = clist.find_clientid(client);//�ҵ�ǰһ�����
			if (tt == nullptr)
			{
				cout << "�û��Ų����ڣ�������ѡ��......�����������ּ���������0�˳�" << endl;
				cout << "������=>";
				cin >> flag;
				if (flag) goto ccb; else return cardlist.gettail();
			}
			else
			{
				ctmp = tt->next;
			}
		}
		CreditCard dtmp(ctmp, cnum, bank, credit, point);
		cout << "���ÿ��½����" << endl;
		cardlist.add_tail(dtmp);
		cout << "���ÿ�������" << endl;
		outcard  << dtmp.get_num() << " " << dtmp.get_man()->get_name() << " " << dtmp.get_man()->get_id() << " " << dtmp.get_bank()
			<< " " << dtmp.get_Credit_limit() << " " << dtmp.get_Points();
		double* cost = dtmp.get_consumption();
		int i = 0;
		for (; cost[i] + 1 > 0.01 && i < 10; i++);
		if (i == 0)outcard << " " << 0;
		else {
			cout << " " << i;
			for (int k = 0; k < i; k++)outcard << " " << cost[k];
		}
		outcard << endl;
		dtmp.display();
		return cardlist.gettail();
	}
	else//�û��½���
	{
		CreditCard dtmp(x, cnum, bank, credit, point);
		cout << "���ÿ��½����" << endl;
		cardlist.add_tail(dtmp);
		cout << "���ÿ�������" << endl;
		outcard  << dtmp.get_num() << " " << dtmp.get_man()->get_name() << " " << dtmp.get_man()->get_id() << " " << dtmp.get_bank()
			<< " " << dtmp.get_Credit_limit() << " " << dtmp.get_Points();
		double* cost = dtmp.get_consumption();
		int i = 0;
		for (; cost[i] + 1 > 0.5 && i < 10; i++);
		if (i == 0)outcard << " " << 0;
		else {
			cout << " " << i;
			for (int k = 0; k < i; k++)outcard << " " << cost[k];
		}
		outcard << endl;
		dtmp.display();
		return cardlist.gettail();
	}
}