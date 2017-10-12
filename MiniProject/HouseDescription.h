#pragma once
#include <iostream>
#include <fstream>

class HouseDescription{
public:

	int SQ_Feet;
	int BedRoom;

	friend std::istream& operator>>(std::istream& is, HouseDescription& item);
	friend std::ostream& operator<<(std::ostream& os, HouseDescription item);

	HouseDescription();
	~HouseDescription();

private:
};

