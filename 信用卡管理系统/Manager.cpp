#include "Manager.h"
Manager::Manager()
{//����Ĭ��Ϊ���֤����λ
	my_id = "123456";
	my_name = "myname";
	manager_id = "manager";
	pwd = "123456";
	int l = my_id.len();
	for (int i = 0; i < 6; i++)
	{
		pwd[i] = my_id[l - 6 + i];
	}
	next = nullptr;
}
Manager::Manager(String mid, String n, String i,String p) :person(n, i), manager_id(mid)
{
	pwd = p;
	next = nullptr;
}
Manager& Manager::operator=(Manager& a)
{
	my_name = a.get_name();
	my_id = a.get_id();
	manager_id = a.get_managerid();
	pwd = a.get_pwd();
	return *this;
}
void Manager::display()
{

	cout << "Ա���˺ţ�" << manager_id << "\n����Ա����" << get_name() << "\n���֤�ţ�" << get_id() << endl << endl;
}
void Manager::change_pwd()
{
	int flag = 0;
	String old_pwd;
	String new_pwd;
a:
	system("cls");
	cout << "�����룺";
	cin >> old_pwd;
	if (old_pwd.len() == 1 && old_pwd[0] == 0)return;
	if ((old_pwd == pwd) != true)
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
		system("cls");
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