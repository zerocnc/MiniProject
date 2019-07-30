#include <iostream>
#include <string>
#include <iomanip>

#include "HouseListing.h"

bool HouseListing::operator<( HouseListing otherOwner) const
{
	int resultLastName = 0;

	resultLastName = std::strcmp(HouseOwner.LastName.c_str(), otherOwner.HouseOwner.LastName.c_str());

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

	resultLastName = std::strcmp(HouseOwner.LastName.c_str(), otherOwner.HouseOwner.LastName.c_str());

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

	resultLastName = std::strcmp(HouseOwner.LastName.c_str(), otherOwner.HouseOwner.LastName.c_str());
	resultFirstName = std::strcmp(HouseOwner.FirstName.c_str(), otherOwner.HouseOwner.FirstName.c_str());

	if ( resultLastName == 0 )
	{
		return true;
	}
	else
		return false;
}

HouseListing::HouseListing()
{
	this->HomeDesription.BedRoom = 0;
	this->HomeDesription.SQ_Feet = 0;
	this->HouseOwner.FirstName.clear();
	this->HouseOwner.LastName.clear();
	this->HouseOwnerAddress.HouseHouseAddress.clear();

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
	os << "Price: $" << std::fixed << std::setprecision(2) << std::setfill('0') << item.HousePrice << std::endl;
	os << item.HomeDesription;

	return os;
}

void HouseListing::GetFromFile(std::ifstream& file)
{
	file >> this->HouseOwner.FirstName;
	file >> this->HouseOwner.LastName;
	file.ignore();
	std::getline( file, this->HouseOwnerAddress.HouseHouseAddress);
	file >> HousePrice >> this->HomeDesription.SQ_Feet >> this->HomeDesription.BedRoom;

	return;
}

void HouseListing::WriteToFile(std::ofstream& file) const
{
	file << this->HouseOwner.FirstName;
	file << this->HouseOwner.LastName << "\n";
	file << " " << this->HouseOwnerAddress.HouseHouseAddress << "\n";
	file << HousePrice << this->HomeDesription.SQ_Feet << this->HomeDesription.BedRoom;

	return;
}

void HouseListing::GetFromUser()
{
	std::cout << "Enter last name; press return." << std::endl;
	std::getline(std::cin, HouseOwner.LastName);

	std::cout << "Enter the first name; press enter." << std::endl;
	std::getline(std::cin, HouseOwner.FirstName);

	std::cout << "Enter the home address; press enter." << std::endl;
	std::getline(std::cin, HouseOwnerAddress.HouseHouseAddress);

	std::cout << "Enter price, square feet, number of bedrooms; separated by a space, then press enter" << std::endl;
	std::cin >> HousePrice >> this->HomeDesription.SQ_Feet >> this->HomeDesription.BedRoom;

	return;
}

void HouseListing::PrintHouseToScreen() const
{
	std::cout << this->HouseOwner.FirstName << ' ';
	std::cout << this->HouseOwner.LastName << '\n';
	std::cout << this->HouseOwnerAddress;
	std::cout << "Price: $" << std::fixed << std::setprecision(2) << std::setfill('0') << this->HousePrice << std::endl;
	std::cout << "Total Square Feet: " << this->HomeDesription.SQ_Feet << std::endl;
	std::cout << "Number of Baths: " << this->HomeDesription.BedRoom << std::endl;
}

void HouseListing::GetKeyNameOnlyFromUser()
{
	std::cout << std::endl;
	std::cout << "Enter last name; press return." << std::endl;
	std::getline(std::cin, this->HouseOwner.LastName);

}

void HouseListing::PrintNameToScreen() const
{
	std::cout << this->HouseOwner.FirstName << " " 
			  << this->HouseOwner.LastName << std::endl;
}