#include "Person.h"

Person::Person()
{
	FirstName.clear();
	LastName.clear();

	return;
}

Person::~Person()
{
	return;
}

std::istream& operator>>(std::istream& is, Person& item)
{
	is >> item.FirstName >> item.LastName;
	is.ignore();

	return is;
}

std::ostream& operator<<(std::ostream& os, Person item)
{
	os << item.FirstName << ' ';
	os << item.LastName << '\n';

	return os;
}