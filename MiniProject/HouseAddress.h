#pragma once
#include <iostream>
#include <fstream>
#include <string>

class HouseAddress {
public:
	std::string HouseHouseAddress;

	friend std::istream& operator>>(std::istream& is, HouseAddress& item);
	friend std::ostream& operator<<(std::ostream& os, HouseAddress item);

	HouseAddress();
	~HouseAddress();

private:
};
