#pragma once

#include "HomeAddress.h"
#include <string>

StreetAddress::StreetAddress() {

}

StreetAddress::StreetAddress()
{
	StreetAddress.clear();

	return;
}

HouseAddress::~HouseAddress()
{
	return;
}


std::istream& operator>>(std::istream& is, HouseAddress& item)
{
	std::getline(is, item.StreetAddress);

	return is;
}

std::ostream& operator<<(std::ostream& os, HouseAddress item)
{
	os << item.StreetAddress << '\n';

	return os;
}