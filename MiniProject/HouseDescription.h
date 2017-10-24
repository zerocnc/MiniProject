#pragma once
#include <iostream>
#include <fstream>

class HouseDescription{
public:

	int SQ_Feet;
	int BedRoom;

	friend std::istream& operator>>(std::istream& is, HouseDescription& item);
	friend std::ostream& operator<<(std::ostream& os, HouseDescription item);

private:
};

std::istream& operator>>(std::istream& is, HouseDescription& item)
{
	is >> item.SQ_Feet;
	is >> item.BedRoom;

	return is;
}

std::ostream& operator<<(std::ostream& os, HouseDescription item)
{
	os << item.SQ_Feet;
	os << item.BedRoom;

	return os;
}
