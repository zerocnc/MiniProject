#pragma once
#include <fstream>

#include "Person.h"
#include "HouseAddress.h"
#include "HouseDescription.h"

class HouseListing
{
public:
	Person HouseOwner;
	StreetAddress HouseAddress;
	float HousePrice;
	HouseDescription HomeDesription;

	friend std::istream& operator>>(std::istream& is, HouseListing& item);
	friend std::ostream& operator<<(std::ostream& os, HouseListing item);

private:

};

std::istream& operator>>(std::istream& is, HouseListing& item)
{
	is >> item.HouseOwner;
	is >> item.HouseAddress;
	is >> item.HousePrice;
	is >> item.HomeDesription;

	return is;
}

std::ostream& operator<<(std::ostream& os, HouseListing item){
	
	os << item.HouseOwner;
	os << item.HouseAddress;
	os << item.HousePrice << " ";
	os << item.HomeDesription;

	return os;
}