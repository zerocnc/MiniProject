#include "HouseAddress.h"

HouseAddress::HouseAddress()
{
	HouseHouseAddress.clear();

	return;
}

HouseAddress::~HouseAddress()
{
	return;
}


std::istream& operator>>(std::istream& is, HouseAddress& item)
{
	std::getline(is, item.HouseHouseAddress);

	return is;
}

std::ostream& operator<<(std::ostream& os, HouseAddress item)
{
	os << item.HouseHouseAddress << '\n';

	return os;
}