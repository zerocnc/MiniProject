#include <iostream>
#include <fstream>
#include "HouseListing.h"
#include "UnsortedLinkedList.h"
#include "BinarySearchTree.h"

// Each constant represents a task.
enum CommandType {ADD, DELETE, PRINT_ONE, PRINT_ALL, QUIT };

void FileToList(UnsortedType<HouseListing>&, std::ifstream&);

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
	// List
	UnsortedType<HouseListing> houseList;


	FileToList(houseList, masterIn);
	//GetCommand(command);

	HouseListing myItem;

	houseList.ResetList();

	int numberOfPeople = houseList.LengthIs();

	// Prints entire tree.
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

void ListToFile(UnsortedType<HouseListing> houseList, std::ofstream& masterOut)
{
	HouseListing item;
	int length;

	masterOut.open("masterOut.mf");
	houseList.ResetList();
	length = houseList.LengthIs();
	for (int ndx = 0; ndx < length; ndx++)
	{
		houseList.GetNextItem(item);
		masterOut << item;
	}

	masterOut.close();
}

void AddHouse(UnsortedType<HouseListing>& houseList)
{
	bool found;
	HouseListing item;

	item.GetFromUser();
	houseList.RetrieveItem(item, found);

	if (!found)
	{
		houseList.InsertItem(item);
		std::cout << "Operation completed." << std::endl;
	}
	else
		std::cout << "Duplicate name: Operation Aborted" << std::endl;
}

void DeleteHouse(UnsortedType<HouseListing>& houseList)
{
	bool found;
	HouseListing item;

	item.GetFromUser();
	houseList.RetrieveItem(item, found);

	if (found)
	{
		houseList.DeleteItem(item);
		std::cout << "Operation completed." << std::endl;
	}
	else
		std::cout << "Person not in list." << std::endl;

	return;
}

void PrintHouse(UnsortedType<HouseListing> houseList)
{
	bool found;
	HouseListing item;

	item.GetNameFromUser();
	houseList.RetrieveItem(item, found);

	if (found)
		item.PrintHouseToScreen();
	else
		std::cout << "Owner not in list." << std::endl;

	return;
}

void PrintOwners(UnsortedType<HouseListing> houseList)
{
	HouseListing item;
	int length = 0;

	houseList.ResetList();
	length = houseList.LengthIs();

	for (int ndx = 0; ndx < length; ndx++)
	{
		houseList.GetNextItem(item);
		item.PrintNameToScreen();
	}

	std::cout << "Operation Complete." << std::endl;
}

void GetCommand(CommandType& command)
{
	// Prompt User
	std::cout << "Operations are listed below."
		<< "Enter the appropriate uppercase letter and "
		<< "press return." << std::endl;
	std::cout << "A : Add a hosue to thei list of hosues." << std::endl;
	std::cout << "D : Delete a specific owner's house." << std::endl;
	std::cout << "P : Print the information about an owner's house." << std::endl;
	std::cout << "L : Print all the names on the screen." << std::endl;
	std::cout << "Q : Quit Processing." << std::endl;

	char letter;
	std::cin >> letter;

	bool ok = false;
	while (!ok)
	{
		ok = true;
		switch (letter)
		{
		case 'A': command = ADD;
			break;
		case 'D': command = DELETE;
			break;
		case 'P': command = PRINT_ONE;
			break;
		case 'L': command = PRINT_ALL;
			break;
		case 'Q': command = QUIT;
			break;
		default:
			std::cout << "Letter entered is not one of the specified uppercase commands. " << std::endl;
			std::cout << "Reenter and press return." << std::endl;
			ok = false;
			break;
		}
	}
}