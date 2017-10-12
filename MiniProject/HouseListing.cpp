#include <iostream>
#include "HouseListing.h"

HouseListing::HouseListing()
{
	HousePrice = 0;
}

HouseListing::~HouseListing()
{

}

std::istream& operator>>(std::istream& is, HouseListing& item)
{
	is >> item.HouseOwner;
	is >> item.HouseOwnerAddress;
	is >> item.HousePrice;
	is >> item.HomeDesription;

	return is;
}

std::ostream& operator<<(std::ostream& os, HouseListing item) {

	os << item.HouseOwner;
	os << item.HouseOwnerAddress;
	os << item.HousePrice << " ";
	os << item.HomeDesription;

	return os;
}