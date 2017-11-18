#include <iostream>
#include "HouseDescription.h"

HouseDescription::HouseDescription() {
	SQ_Feet = 0;
	BedRoom = 0;
}

HouseDescription::~HouseDescription()
{
	return;
}

std::istream& operator>>(std::istream& is, HouseDescription& item)
{
	is >> item.SQ_Feet;
	is >> item.BedRoom;

	return is;
}

std::ostream& operator<<(std::ostream& os, HouseDescription item)
{
	os << "Sqaure Feet:" << item.SQ_Feet << "sq. ft." << std::endl;
	os <<"Bedrooms: " << item.BedRoom;

	return os;
}
