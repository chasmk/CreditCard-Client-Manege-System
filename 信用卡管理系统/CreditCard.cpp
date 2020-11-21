#include "CreditCard.h"
#include<iostream>
using namespace std;
CreditCard::CreditCard()
{
	next = nullptr;
	Card_num = "null_Card_num";
	man = new person("nullname","nullid");
	Card_bank = "null_Card_bank";
	Card_Credit_limit = 0;
	for(int i=0;i<10;i++)Card_consumption[i] = -1;
	Card_Points = 0;
}
CreditCard::CreditCard(person* p=new person("nullname", "nullid"),String a= "null_Card_num", String c= "null_Card_bank", double d=0,  double f=0) :man(p),Card_num(a),Card_bank(c), Card_Credit_limit(d),  Card_Points(f)
{

	for (int i = 0; i < 10; i++) Card_consumption[i] = -1;
	next = nullptr;
}
CreditCard::CreditCard( CreditCard& a)
{
	man = new person;
	set_bank(a.get_bank());
	set_Credit_limit(a.get_Credit_limit());
	set_id(a.man->get_id());
	set_name(a.man->get_name());
	set_consumption(a.get_consumption());
	set_num(a.get_num());
	set_Points(a.get_Points());
}
CreditCard& CreditCard::operator=(CreditCard& a)
{
	set_bank(a.get_bank());
	set_Credit_limit(a.get_Credit_limit());
	set_id(a.man->get_id());
	set_name(a.man->get_name());
	set_consumption(a.get_consumption());
	set_num(a.get_num());
	set_Points(a.get_Points());
	return *this;
}
void CreditCard::display()
{
	cout << "1.���ţ�" << get_num() << endl;
	cout << "2.������" << man->get_name() << endl;
	cout << "3.���֤�ţ�" << man->get_id() << endl;
	cout << "4.�������У�" << get_bank() << endl;
	cout << "5.���ö�ȣ�" << get_Credit_limit() << endl;
	cout << "6.���ѽ��(��ʮ��)��" ;
	double *a=get_consumption();
	if (a[0] + 1 < 1e-2)cout << "�������Ѽ�¼��";
	for (int i = 0; i < 10 && a[i] != -1; i++)cout << a[i] << ",";
	cout << endl;
	cout << "7.���û��֣�" << get_Points() << endl;
	cout << endl;
}
