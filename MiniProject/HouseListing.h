#pragma once
#include <fstream>

#include "Person.h"
#include "HouseAddress.h"
#include "HouseDescription.h"

class HouseListing
{
public:
	Person HouseOwner;
	HouseAddress HouseOwnerAddress;
	float HousePrice;
	HouseDescription HomeDesription;

	friend std::istream& operator>>(std::istream& is, HouseListing& item);
	friend std::ostream& operator<<(std::ostream& os, HouseListing item);

	HouseListing();
	~HouseListing();

	void GetFromFile(std::ifstream&);
	void WriteToFile(std::ofstream&) const;
	void GetFromUser();
	void PrintHouseToScreen() const;
	void GetNameFromUser();
	void PrintNameToScreen() const;
	// Overload <,>,== later for BST usage

private:

};
