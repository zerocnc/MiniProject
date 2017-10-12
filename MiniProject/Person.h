#pragma once

#include <fstream>
#include <iostream>
#include <string>

class Person {
public:
	// First Name of a person.
	std::string FirstName;

	// Last Name of a person.
	std::string LastName;

	friend std::istream& operator>>(std::istream& is, Person& item);
	friend std::ostream& operator<<(std::ostream& os, Person item);

	Person();
	~Person();

private:

};
