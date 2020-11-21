#include"manager_list.h"
#include"client_list.h"
#include"Card_list.h"
#include"String.h"
#include<fstream>
#include<iostream>
using namespace std;
void welcom();//欢迎界面
void clientlogin();//用户登陆界面
void oldclientlogin();//老用户登陆
void newclientsignin();//新用户注册
void managerlogin();//管理员登陆界面
void managers();//管理员功能
void informquery();//信息查询界面
void advancedquery();//高级查询
void business();//业务查询
CreditCard* newcard(Client*,int); //新建卡

int flag = 0;
client_list clist;//客户表
manager_list mlist;//管理员表
Card_list cardlist;//信用卡表
ifstream inclient("Client.txt", ios::in);
ifstream inmanager("manager.txt", ios::in);
ifstream incard("Card.txt", ios::in);
ofstream outclient("Client.txt", ios::app);//追加在末尾
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
		CreditCard* p = cardlist.add_tail(tmp);//同时向卡列表添加此卡
		if (ctmp != nullptr)
		{
			ctmp->c.add_Card(p);//若找到客户id 则向客户卡包中添加此卡
		}
	}

	inclient.close();
	incard.close();
	inmanager.close();

	//------------主界面----------------//
a0:
	welcom();
	cout << "请输入=>";
	cin >> flag;
	system("cls");
	switch (flag)
	{
	case 0:goto a4;
	case 1:goto a1;//用户登陆
	case 2:goto a2;//管理员登陆
	case 3:goto a3;//业务查询
	default:cout << "输入不正确，请重新输入" << endl; goto a0;
	}
//-----------------------------------------------------------------------------------------------//
	//------------用户登陆界面----------------//
a1:
	clientlogin();
b10:
	cout << "请输入=>";
	cin >> flag;
	//system("cls");
	switch (flag)
	{
	case 0:system("cls"); goto a0;//返回上层
	case 1:goto b11;//老用户登陆
	case 2:goto b12;//新用户注册
	default:cout << "输入不正确，请重新输入" << endl; goto b10;
	}
b11:
	oldclientlogin();//老用户登陆
	goto a1;
b12:
	newclientsignin();//新用户注册
	goto a1;
//-----------------------------------------------------------------------------------------------//
	//------------管理员登陆界面----------------//
a2:
	system("cls");
	managerlogin();
b20:
	cout << "请输入=>";
	cin >> flag;
	system("cls");
	switch (flag)
	{
	case 0:goto a0;//返回上层
	case 1:goto b21;//管理员登陆
	default:cout << "输入不正确，请重新输入" << endl; goto b20;
	}
b21:
	managers();//管理员登陆
	goto a2;
//-----------------------------------------------------------------------------------------------//
	//------------业务查询界面----------------//
a3:
	system("cls");
	business();
	goto a0;

a4:
	cout << " --------------------------------------" << endl;
	cout << "|           感谢使用，再见！           |" << endl;
	cout << " --------------------------------------" << endl;
	outclient.close();
	outcard.close();
	outmanager.close();
	return 0;
}

void welcom()
{
	cout << "--------------------------------------" << endl;
	cout << "|        信用卡客户管理系统          |" << endl;
	cout << "|                                    |" << endl;
	cout << "|       请输入对应数字访问菜单       |" << endl;
	cout << "|       0-退出系统                   |" << endl;
	cout << "|       1-用户模块                   |" << endl;
	cout << "|       2-管理员模块                 |" << endl;
	cout << "|       3-业务查询                   |" << endl;
	cout << "--------------------------------------" << endl;
}
void clientlogin()
{
	cout << "--------------------------------------" << endl;
	cout << "|        欢迎来到用户登陆界面        |" << endl;
	cout << "|                                    |" << endl;
	cout << "|       请输入对应数字访问功能       |" << endl;
	cout << "|       0-返回上层                   |" << endl;
	cout << "|       1-老用户登陆                 |" << endl;
	cout << "|       2-新用户注册                 |" << endl;
	cout << "--------------------------------------" << endl;

}
void oldclientlogin()//老用户登陆
{

	int flag = 0;
a:
	cout << "请输入用户名：";
	String cid;
	cin >> cid;
	Client* p = clist.find_clientid(cid);//find_clientid()找到前一个结点
	if (p == nullptr)
	{
		cout << "用户名还未注册......1 重新输入，0返回上层" << endl;
		cout << "请输入=>";
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
		cout << "请输入密码：";
		cin >> pwd;
		cout << "正确密码提示#" << p->get_pwd() << "#" << endl;
		if (p->get_pwd() == pwd)
		{
			cout << "登陆成功！,输入任意数字继续...." << endl;
			cout << "请输入=>";
			cin >> flag;
			system("cls");
			goto b;
		}
		else
		{
			cout << "密码错误！......1 重新输入，0返回上层" << endl;
			cout << "请输入=>";
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
	cout << "|        " << p->get_name() << "!    欢迎你           |" << endl;
	cout << "|                                    |" << endl;
	cout << "|       请输入对应数字访问功能       |" << endl;
	cout << "|       0-返回上一级                 |" << endl;
	cout << "|       1-查看个人信息               |" << endl;
	cout << "|       2-修改密码                   |" << endl;
	cout << "|       3-消费金额                   |" << endl;
	cout << "|       4-信用积分兑换               |" << endl;
	cout << "|       5-开通信用卡                 |" << endl;
	cout << "--------------------------------------" << endl;
b10:
	//Cnode* p1;
	Cnode* node = p->c.head->next;
	cout << "请输入=>";
	cin >> flag;
	system("cls");
	switch (flag)
	{
	case 0:return;//返回上一级
	case 1:goto a1;//查看个人信息
	case 2:goto a2;//修改密码
	case 3:goto a3;//消费金额
	case 4:goto a4;//信用积分兑换
	case 5:goto a5;//开通信用卡
	default:cout << "输入不正确，请重新输入" << endl; goto b10;
	}
a1:
	p->display();
	if (p->c.list_size() == 0)cout << "信用卡列表为空" << endl;
	else
	{
		while (node != nullptr)
		{
			node->mcard->display();
			node = node->next;
		}
		cout << "卡包展示完毕，一共有" << p->c.list_size() << "张卡" << endl;
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
cout << "输入任意数字继续...." << endl;
cout << "请输入=>";
cin >> flag;
system("cls");
goto b;
}//
void newclientsignin()//新用户注册
{
	cout << "请输入您的个人信息" << endl;
	String name;
	String id;
	cout << "姓名：";
	cin >> name;
sfz:
	cout << "身份证号：";
	cin >> id;
	if (id.len() != 18)
	{
		cout << "身份证号长度应为18位，请重新输入......输入任意数字继续，输入0取消" << endl;
		cin >> flag;
		if (!flag) return;
		else goto sfz;
	}
	String pwd = id.subString(id, 12, 6);
	int l = clist.list_size();
	l++;//用于生成用户号
	String cid = "000";
	for (int i = 0; i < 3 && l != 0; i++)
	{
		cid[2 - i] = l % 10 + '0';
		l /= 10;
	}
	cout << "cid:" << cid << endl;
	Client ctmp(cid, name, id,pwd);
	Client* tmp = clist.add_tail(ctmp);//添加到客户链表
	outclient << ctmp.get_clientid() << " " << ctmp.get_name() << " " << ctmp.get_id() <<" "<<ctmp.get_pwd()<< endl;
	cout << "您的用户名：" << ctmp.get_clientid() << endl << "您的默认密码：" << ctmp.get_pwd() << endl;
	cout << "账号创建成功！......输入任意数字继续" << endl;
	cout << "请输入=>";
	cin >> flag;
	system("cls");
}
void managerlogin()
{
	cout << " --------------------------------------" << endl;
	cout << "|        欢迎来到管理员登陆界面       |" << endl;
	cout << "|                                     |" << endl;
	cout << "|       请输入对应数字访问功能        |" << endl;
	cout << "|       0-返回上一级                  |" << endl;
	cout << "|       1-管理员登陆                  |" << endl;
	cout << " --------------------------------------" << endl;
}
void managers()//管理员功能
{
	String mid;
	String pwd;
	int flag = 0;
a:
	system("cls");
	cout << "请输入管理员号：";
	cin >> mid;
	Manager* p = mlist.find_managerid(mid);
	if (p == nullptr)
	{
		cout << "管理员还未注册......1 重新输入，0返回上层" << endl;
		cout << "请输入=>";
		cin >> flag;
		if (flag) goto a; else return;
	}
	else
	{
		p = p->next;
		cout << "请输入密码：";
		cin >> pwd;
		if (p->get_pwd() == pwd)
		{
			cout << "登陆成功！......输入任意数字继续" << endl;
			cout << "请输入=>";
			cin >> flag;
			goto b;
		}
		else
		{
			cout << "正确密码：" << p->get_pwd() << "#" << endl;
			cout << "密码错误！......1 重新输入，0返回上层" << endl;
			cout << "请输入=>";
			cin >> flag;
			if (flag) goto a; else return;
		}
	}
b:
	system("cls");
	cout << " --------------------------------------" << endl;
	cout << "|        " << p->get_name() << "    欢迎你!         |" << endl;
	cout << "|                                     |" << endl;
	cout << "|       请输入对应数字访问功能        |" << endl;
	cout << "|       0-返回上一级                  |" << endl;
	cout << "|       1-显示个人信息                |" << endl;
	cout << "|       2-修改密码                    |" << endl;
	cout << "|       3-新建用户                    |" << endl;
	cout << "|       4-新建信用卡                  |" << endl;
	cout << "|       5-修改信息                    |" << endl;
	cout << "|       6-删除信息                    |" << endl;
	cout << "|       7-排序整理信息                |" << endl;
	cout << "|       8-信息查看                    |" << endl;
	cout << " --------------------------------------" << endl;
b10:
	cout << "请输入=>";
	cin >> flag;
	system("cls");
	switch (flag)
	{
	case 0:return;//返回上一级
	case 1:goto a1;//查看个人信息
	case 2:goto a2;//修改密码
	case 3:goto a3;//新建用户
	case 4:goto a4;//新建信用卡
	case 5:goto a5;//修改信息
	case 6:goto a6;//删除信息
	case 7:goto a7;//排序整理信息
	case 8:goto a8;//信息查看
	default:cout << "输入不正确，请重新输入" << endl; goto b10;
	}
a1:
	p->display(); goto c;
a2:
	p->change_pwd(); mlist.outputfile(); goto c;
a3:
	{
		cout << "请输入新用户的个人信息" << endl;
		String name;
		String id;
		cout << "姓名：";
		cin >> name;
	sfz:
		cout << "\n身份证号：";
		cin >> id;
		if (id.len() != 18)
		{
			cout << "身份证号长度应为18位，请重新输入......输入任意数字继续，输入0取消" << endl;
			cout << "请输入=>";
			cin >> flag;
			if (!flag)goto c;
			else goto sfz;
		}
		String pwd = id.subString(id, 12, 6);
		int l = clist.list_size();
		l++;//用于生成用户号
		String cid = "000";
		for (int i = 0; i < 3 && l != 0; i++)
		{
			cid[2 - i] = l % 10 + '0';
			l /= 10;
		}
		Client ctmp(cid, name, id,pwd);
		clist.add_tail(ctmp);
		outclient << ctmp.get_clientid() << " " << ctmp.get_name() << " " << ctmp.get_id()<<" "<<ctmp.get_pwd()<<endl;
		cout << "新用户: \n"; ctmp.display(); cout << "创建成功！" << endl;
		goto c; }
a4:
	{
		newcard(nullptr, 0);
		goto c; }
a5:
	{
		cout << "请选择要修改的内容：" << endl;
		cout << "1. 用户信息修改\n2. 信用卡信息修改" << endl;
	mb:
		cout << "请输入=>";
		cin >> flag;
		switch (flag)
		{
		case 1:clist.modify(); clist.outputfile(); break;
		case 2:cardlist.modify(); cardlist.outputfile(); break;
		default:cout << "序号不存在,请重新输入"; goto mb;
		}
		goto c; }
a6:
	{
		cout << "请选择要删除的内容：" << endl;
		cout << "1. 用户信息删除\n2. 信用卡信息删除" << endl;
	mc:
		cout << "请输入=>";
		cin >> flag;
		switch (flag)
		{
		case 1:clist.Delete(); clist.outputfile(); break;
		case 2:cardlist.Delete(); cardlist.outputfile(); break;
		default:cout << "序号不存在，请重新输入"; goto mc;
		}
		goto c;
	}
a7:
	{
		cout << "请选择要排序整理的内容：" << endl;
		cout << "1. 用户信息\n2. 信用卡信息\n3. 管理员信息" << endl;
	md:
		cout << "请输入=>";
		cin >> flag;
		switch (flag)
		{
		case 1:clist.Sort(); clist.outputfile(); break;
		case 2:cardlist.Sort(); cardlist.outputfile(); break;
		case 3:mlist.Sort(); mlist.outputfile(); break;
		default:cout << "序号不存在，请重新输入" << endl; goto md;
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
	case 0:goto b;//返回上层
	case 1:goto b31;//用户查询
	case 2:goto b32;//管理员查询
	case 3:goto b33;//信用卡查询
	case 4:goto b34;//高级查询
	default:cout << "输入不正确，请重新输入" << endl; goto b30;
	}
b31:clist.show(); goto b35;
b32:mlist.show(); goto b35;
b33:cardlist.show(); goto b35;
b34:advancedquery(); goto
a8;
b35:
cout << "......输入任意数字继续" << endl;
cout << "请输入=>";
cin >> flag;
goto a8;
c:
cout << "......输入任意数字继续" << endl;
cout << "请输入=>";
cin >> flag;
goto b;
}
void informquery()//信息查询界面
{
	cout << "--------------------------------------" << endl;
	cout << "|        欢迎来到信息查询界面        |" << endl;
	cout << "|                                    |" << endl;
	cout << "|       请输入对应数字访问功能       |" << endl;
	cout << "|       0-返回上层                   |" << endl;
	cout << "|       1-用户查询                   |" << endl;
	cout << "|       2-管理员查询                 |" << endl;
	cout << "|       3-信用卡查询                 |" << endl;
	cout << "|       4-高级查询                   |" << endl;
	cout << "--------------------------------------" << endl;
}
void advancedquery()//高级查询
{
a:
	system("cls");
	cout << " --------------------------------------" << endl;
	cout << "|       欢迎来到高级查询界面          |" << endl;
	cout << "|                                     |" << endl;
	cout << "|       请输入对应数字访问功能        |" << endl;
	cout << "|       0-返回上一级                  |" << endl;
	cout << "|       1-按卡号查询                  |" << endl;
	cout << "|       2-按用户姓名查询              |" << endl;
	cout << "|       3-按身份证号码                |" << endl;
	cout << "|       4-信用积分查询                |" << endl;
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
	cout << "请输入=>";
	cin >> flag;
	switch (flag)
	{
	case 0:return;//返回上层
	case 1:goto b31;//按卡号查询
	case 2:goto b32;//按用户姓名查询
	case 3:goto b33;//按身份证号查询
	case 4:goto b34;//按信用积分查询
	default:cout << "输入不正确，请重新输入" << endl; goto b30;
	}
b31:
	cout << "请输入待查询卡号=>";
	cin >> cardid;
	ctmp1 = cardlist.find_cardnum(cardid);
	if (ctmp1 == nullptr)
	{
		cout <<cardid<<" "<< "查询无结果! " ;
	}
	else
	{
		ctmp1->next->display();
	}
	goto c;
b32:
	cout << "请输入待查询用户姓名：";
	cin >> name;

	tmp3 = clist.find_myname(name);
	if (tmp3 == nullptr)
	{
		cout <<name<<" "<< "查询无结果! " << endl;
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
	cout << "请输入待查询身份证号：";
	cin >> id;

	tmp4 = clist.find_myid(id);
	if (tmp4 == nullptr)
	{
		cout << id << " " << "查询无结果! " << endl;
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
	cout << "请输入待查询信用积分：";
	cin >> credit;
	ctmp4 = cardlist.find_cardcredit(credit);
	if (ctmp4 == nullptr)
	{
		cout<< credit<<" " << "查询无结果! " << endl;
	}
	else
	{
		ctmp4->display();
	}
	goto c;

c:
	cout << "输入任意数字继续" << endl;
	cout << "请输入=>"; cin >> flag;
	goto a;
}
void business()
{
a:
	ofstream outfeed("feedback.txt", ios::app);
	String s;
	system("cls");
	cout << "--------------------------------------" << endl;
	cout << "|        欢迎来到业务查询界面        |" << endl;
	cout << "|                                    |" << endl;
	cout << "|       请输入对应数字访问功能       |" << endl;
	cout << "|       0-返回上层                   |" << endl;
	cout << "|       1-银行查询                   |" << endl;
	cout << "|       2-信用额度查询               |" << endl;
	cout << "|       3-信用积分制度查询           |" << endl;
	cout << "|       4-意见反馈                   |" << endl;
	cout << "--------------------------------------" << endl;
b30:
	cout << "请输入=>";
	cin >> flag;
	system("cls");
	switch (flag)
	{
	case 0:return;//返回上层
	case 1:goto b31;//银行查询
	case 2:goto b32;//信用额度查询
	case 3:goto b33;//信用积分制度查询
	case 4:goto b34;//意见反馈
	default:cout << "输入不正确，请重新输入" << endl; goto b30;
	}
b31:
	cout << "----------------------------------------------" << endl;
	cout << "|   本公司与以下银行建立了深入合作伙伴关系   |" << endl;
	cout << "|                                            |" << endl;
	cout << "|     为您提供*最优质*,*最可靠*的信贷服务    |" << endl;
	cout << "|                                            |" << endl;
	cout << "|           *中国工商银行*                   |" << endl;
	cout << "|           *中国人民银行*                   |" << endl;
	cout << "|           *中国农业银行*                   |" << endl;
	cout << "|           *中国建设银行*                   |" << endl;
	cout << "|           未完待续......                   |" << endl;
	cout << "---------------------------------------------" << endl;
	goto b35;
b32:
	cout << "-----------------------------------------" << endl;
	cout << "|      本公司提供以下额度的信用贷款     |" << endl;
	cout << "|                                       |" << endl;
	cout << "|                                       |" << endl;
	cout << "|             *500￥*                   |" << endl;
	cout << "|             *1000￥*                  |" << endl;
	cout << "|             *2000￥*                  |" << endl;
	cout << "|             *5000￥*                  |" << endl;
	cout << "|             *10000￥*                 |" << endl;
	cout << "|             未完待续......            |" << endl;
	cout << "-----------------------------------------" << endl;
	goto b35;
b33:
	cout << "--------------------------------------" << endl;
	cout << "|      本公司的信用积分制度如下      |" << endl;
	cout << "|                                    |" << endl;
	cout << "|      每100元的贷款或消费           |" << endl;
	cout << "|              ||                    |" << endl;
	cout << "|             \\||/                   |" << endl;
	cout << "|              \\/                    |" << endl;
	cout << "|             1积分                  |" << endl;
	cout << "--------------------------------------" << endl;
	goto b35;
b34:
	cout << "请留下您宝贵的意见，（输入#结束）" << endl;
	cout << "请输入=>";
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
	cout << "感谢您的支持" << endl;
	outfeed.close();
	goto b35;
b35:
	cout << "输入任意数字继续" << endl;
	cout << "请输入=>";
	cin >> flag;
	goto a;
}
CreditCard* newcard(Client* x,int i) //新信用卡开通 x==0管理员开通 x==1用户开通
{
	cout << "请选择您的开户银行" << endl;
	cout << "1. 中国工商银行\n2. 中国人民银行\n3. 中国农业银行\n4. 中国建设银行" << endl;
cb:
	cin >> flag;
	String bank;
	switch (flag)
	{
	case 1:bank ="中国工商银行"; break;
	case 2:bank ="中国人民银行"; break;
	case 3:bank ="中国农业银行"; break;
	case 4:bank = "中国建设银行"; break;
	default:cout << "银行不存在，请重新输入"; goto cb;
	}
	cout << "请选择您的信用额度" << endl;
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
	default:cout << "信用额度不存在，请重新输入" << endl; goto db;
	}

	int l = cardlist.list_size();
	l++;//用于生成卡号
	String cnum = "000";
	for (int i = 0; i < 3&&l!=0; i++)
	{
		cnum[2-i] = l % 10+'0';
		l /= 10;
	}
	double point = credit / 100;
	cout << "卡号生成完毕" << endl;
	if (i == 0)//如果是管理员新建卡
	{
		cout << "请选择要绑定的用户号,输入任意数字继续选择，暂不绑定请输入0" << endl;
	ccb:
		cout << "请输入=>";
		cin >> flag;
		Client* ctmp = new Client;
		if (flag)
		{
			clist.show();
			cout << "请输入要选择的用户：";
			String client; cin >> client;
			Client* tt = clist.find_clientid(client);//找到前一个结点
			if (tt == nullptr)
			{
				cout << "用户号不存在，请重新选择......输入任意数字继续，输入0退出" << endl;
				cout << "请输入=>";
				cin >> flag;
				if (flag) goto ccb; else return cardlist.gettail();
			}
			else
			{
				ctmp = tt->next;
			}
		}
		CreditCard dtmp(ctmp, cnum, bank, credit, point);
		cout << "信用卡新建完毕" << endl;
		cardlist.add_tail(dtmp);
		cout << "信用卡添加完毕" << endl;
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
	else//用户新建卡
	{
		CreditCard dtmp(x, cnum, bank, credit, point);
		cout << "信用卡新建完毕" << endl;
		cardlist.add_tail(dtmp);
		cout << "信用卡添加完毕" << endl;
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