#pragma once
#include <fstream>

class HouseListing
{
public:

	friend std::istream& operator>>(std::istream& is, HouseListing& item);
	friend std::ostream& operator<<(std::ostream& os, HouseListing item);

	bool operator<(HouseListing HomeOwner) const;
	bool operator>(HouseListing HomeOwner) const;
	bool operator==(HouseListing HomeOwner) const;

	HouseListing();
	~HouseListing();

	void GetFromFile(std::ifstream&);
	void WriteToFile(std::ofstream&) const;
	void GetFromUser();
	void PrintHouseToScreen() const;
	void GetKeyNameOnlyFromUser();
	void PrintNameToScreen() const;
	// Overload <,>,== later for BST usage

private:
	std::string FirstName;
	std::string LastName;
	std::string HouseAddress;
	float HousePrice;
	int SquareFeet;
	int BedRooms;

};
