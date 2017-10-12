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
	is >> item.SQ_Feet >> item.BedRoom;

	return is;
}

std::ostream& operator<<(std::ostream& os, HouseDescription item)
{
	os << item.SQ_Feet << item.BedRoom;

	return os;
}
