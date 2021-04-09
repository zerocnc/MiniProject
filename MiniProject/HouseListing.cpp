#include <iostream>
#include <string>
#include <iomanip>

#include "HouseListing.h"

bool HouseListing::operator<( HouseListing otherOwner) const
{
	int resultLastName = 0;

	resultLastName = std::strcmp(FirstName.c_str(), otherOwner.LastName.c_str());

	if ( resultLastName < 0 )
	{
		return true;
	}
	else
		return false;
}

bool HouseListing::operator>(HouseListing otherOwner) const
{
	int resultLastName = 0;

	resultLastName = std::strcmp(LastName.c_str(), otherOwner.LastName.c_str());

	if (resultLastName > 0)
	{
		return true;
	}
		return false;
}

bool HouseListing::operator==(HouseListing otherOwner) const
{
	int resultLastName = 0;
	int resultFirstName = 0;

	resultLastName = std::strcmp(LastName.c_str(), otherOwner.LastName.c_str());
	resultFirstName = std::strcmp(FirstName.c_str(), otherOwner.FirstName.c_str());

	if ( resultLastName == 0 )
	{
		return true;
	}
	else
		return false;
}

/* Constructor */
HouseListing::HouseListing()
{
	FirstName = "";
	LastName = "";
	HouseAddress = "";
	HousePrice = 0.0;
	SquareFeet = 0;
	BedRooms = 0;
}

HouseListing::~HouseListing()
{

}

std::istream& operator>>(std::istream& is, HouseListing& item)
{
	is >> item.FirstName;
	is >> item.LastName;
	is >> item.HouseAddress;
	is >> item.HousePrice;
	is >> item.SquareFeet;
	is >> item.BedRooms;

	return is;
}

std::ostream& operator<<(std::ostream& os, HouseListing item) {

	os << item.FirstName;
	os << item.LastName;
	os << item.HouseAddress;
	os << item.HousePrice;
	os << item.SquareFeet;
	os << item.BedRooms;

	return os;
}

void HouseListing::GetFromFile(std::ifstream& file)
{
	file >> FirstName;
	file >> LastName;
	file >> HouseAddress;
	file >> HousePrice;
	file >> SquareFeet;
	file >> BedRooms;

	return;
}

void HouseListing::WriteToFile(std::ofstream& file) const
{
	file << FirstName;
	file << LastName;
	file << HouseAddress;
	file << HousePrice;
	file << SquareFeet;
	file << BedRooms;

	return;
}

void HouseListing::GetFromUser()
{
	std::cout << "Enter last name; press return." << std::endl;
	std::getline(std::cin, LastName);

	std::cout << "Enter the first name; press enter." << std::endl;
	std::getline(std::cin, FirstName);

	std::cout << "Enter the home address; press enter." << std::endl;
	std::getline(std::cin, HouseAddress);

	std::cout << "Enter house price." << std::endl;
	std::cin >> HousePrice;

	std::cout << "Enter the house square feet." << std::endl;
	std::cin >> SquareFeet;

	std::cout << "Enter the number of bed rooms." << std::endl;
	std::cin >> BedRooms;

	return;
}

void HouseListing::PrintHouseToScreen() const
{
	std::cout << FirstName << ' ';
	std::cout << LastName << '\n';
	std::cout << HouseAddress;
	std::cout << "Price: $" << std::fixed << std::setprecision(2) << std::setfill('0') << HousePrice << std::endl;
	std::cout << "Total Square Feet: " << SquareFeet << std::endl;
	std::cout << "Number of Bed Rooms: " << BedRooms << std::endl;
}

void HouseListing::GetKeyNameOnlyFromUser()
{
	std::cout << std::endl;
	std::cout << "Enter last name; press return." << std::endl;
	std::getline(std::cin, LastName);

}

void HouseListing::PrintNameToScreen() const
{
	std::cout << FirstName << " " 
			  << LastName << std::endl;
}