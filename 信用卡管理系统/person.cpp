#include "person.h"
person::person()
{
	my_name = "null name";
	my_id = "null_id";
}
person::person(String n="null_name", String i="null_id") :my_name(n), my_id(i)
{

}
person::person(person& p)
{
	my_id = p.get_id();
	my_name = p.get_name();
}