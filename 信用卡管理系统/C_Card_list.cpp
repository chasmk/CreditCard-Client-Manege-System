#include "C_Card_list.h"
C_Card_list::C_Card_list()
{
	head = tail = new Cnode;
	size = 0;
}
CreditCard* C_Card_list::add_Card(CreditCard* a)
{
	tail->next = new Cnode(a, nullptr);
	tail = tail->next;
	size++;
	return tail->mcard;
}
CreditCard* C_Card_list::find_Cardid(String a)
{
	Cnode* p = head->next;
	while (p && !(p->mcard->get_num() == a))
	{
		p = p->next;
	}
	if (p == nullptr) return nullptr;
	return p->mcard;
}
int C_Card_list::list_size()
{
	return size;
}
