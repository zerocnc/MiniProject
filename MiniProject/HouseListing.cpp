#include <iostream>
#include <string>
#include <iomanip>

#include "HouseListing.h"

bool HouseListing::operator<( HouseListing otherOwner) const
{
	int result = 0;

	result = std::strcmp(HouseOwner.LastName.c_str(), otherOwner.HouseOwner.LastName.c_str());

	if (result < 0)
	{
		return true;
	}
	else
		return false;
}

bool HouseListing::operator>(HouseListing otherOwner) const
{
	int result = 0;

	result = std::strcmp(HouseOwner.LastName.c_str(), otherOwner.HouseOwner.LastName.c_str());

	if (result > 0)
	{
		return true;
	}
	else
		return false;
}

bool HouseListing::operator==(HouseListing otherOwner) const
{
	int result = 0;

	result = std::strcmp(HouseOwner.LastName.c_str(), otherOwner.HouseOwner.LastName.c_str());

	if (result == 0)
	{
		return true;
	}
	else
		return false;
}

HouseListing::HouseListing()
{
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
	os << item.HousePrice << " ";
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

	std::cout << "Enter price, square feet, number of bedrooms; press enter" << std::endl;
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

	std::cout << std::endl;
	std::cout << "Enter First name; press return." << std::endl;
	std::getline(std::cin, this->HouseOwner.FirstName);
}

void HouseListing::PrintNameToScreen() const
{
	std::cout << this->HouseOwner.FirstName << " " 
			  << this->HouseOwner.LastName << std::endl;
}