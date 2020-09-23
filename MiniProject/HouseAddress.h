#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>

class StreetAddress {
public:
	std::string HouseStreetAddress;

	friend std::istream& operator>>(std::istream& is, StreetAddress& item);
	friend std::ostream& operator<<(std::ostream& os, StreetAddress item);

private:
};

std::istream& operator>>(std::istream& is, StreetAddress& item)
{
	std::getline(is, item.HouseStreetAddress);

	return is;
}

std::ostream& operator<<(std::ostream& os, StreetAddress item)
{
	os << item.HouseStreetAddress << "\n";
	
	return os;
}