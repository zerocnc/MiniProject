
#include <iostream>
#include <fstream>
#include "HouseListing.h"
#include "UnsortedLinkedList.h"

void LoadFile(UnsortedType<HouseListing>&, std::ifstream&);

int main()
{
	std::string FileName = "TestData.txt";
	HouseListing myItem;

	std::ifstream inFile;

	UnsortedType<HouseListing> myHouseListing;

	LoadFile(myHouseListing, inFile);

	myHouseListing.ResetList();

	int numberOfPeople = myHouseListing.LengthIs();

	for (int ndx = 0; ndx < numberOfPeople; ndx++)
	{
		myHouseListing.GetNextItem(myItem);
		std::cout << myItem << std::endl;
	}


	std::cout << "Hello world!";
}

void LoadFile(UnsortedType<HouseListing>& myListing, std::ifstream& MasterIn) {
	HouseListing item;
	MasterIn.open("TestData.txt");
	myListing.MakeEmpty();

	do
	{
		MasterIn >> item;
		myListing.InsertItem(item);

	} while (MasterIn.good());

	MasterIn.close();
	return;
}