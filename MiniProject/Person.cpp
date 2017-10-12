#include "Person.h"

Person::Person()
{
	FirstName = "";
	LastName = "";

	return;
}

Person::~Person()
{
	return;
}

std::istream& operator>>(std::istream& is, Person& item)
{
	is >> item.FirstName;
	is >> item.LastName;

	return is;
}

std::ostream& operator<<(std::ostream& os, Person item)
{
	os << item.FirstName << " ";
	os << item.LastName << "\n";

	return os;
}