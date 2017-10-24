#pragma once

#include <fstream>
#include <iostream>
#include <string>

class Person {
public:
	// First Name of a person.
	std::string Firstname;

	// Last Name of a person.
	std::string Lastname;

	friend std::istream& operator>>(std::istream& is, Person& item);
	friend std::ostream& operator<<(std::ostream& os, Person item);

private:

};

std::istream& operator>>(std::istream& is, Person& item)
{
	is >> item.Firstname;
	is >> item.Lastname;

	return is;
}

std::ostream& operator<<(std::ostream& os, Person item)
{
	os << item.Firstname << " ";
	os << item.Lastname << "\n";

	return os;
}