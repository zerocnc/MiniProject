#include <iostream>
#include <fstream>
#include "HouseListing.h"
#include "UnsortedLinkedList.h"
#include "BinarySearchTree.h"

// Each constant represents a task.
enum CommandType {ADD, DELETE, PRINT_ONE, PRINT_ALL, QUIT };

void FileToList(UnsortedType<HouseListing>&, TreeType<HouseListing>&, std::ifstream&);

void ListToFile(TreeType<HouseListing>, std::ofstream&);

void AddHouse(TreeType<HouseListing>&);

void DeleteHouse(TreeType<HouseListing>&);

void PrintHouse(TreeType<HouseListing>&);

void PrintOwners(TreeType<HouseListing>);

void GetCommand(CommandType&);

int main()
{
	std::ifstream masterIn;
	std::ofstream masterOut;
	CommandType command;
	UnsortedType<HouseListing> houseList;

	std::string FileName = "TestData.txt";
	HouseListing myItem;

	houseList.ResetList();

	int numberOfPeople = houseList.LengthIs();

	for (int ndx = 0; ndx < numberOfPeople; ndx++)
	{
		houseList.GetNextItem(myItem);
		std::cout << myItem << std::endl;
	}


	std::cout << "Hello world!";
}

void FileToList(UnsortedType<HouseListing>& myListing, std::ifstream& MasterIn) {
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