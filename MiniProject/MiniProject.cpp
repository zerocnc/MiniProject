#include <iostream>
#include <fstream>

#include "HouseListing.h"
#include "UnsortedLinkedList.h"
#include "BinarySearchTree.h"

// Each constant represents a task.
enum class CommandType {ADD, DELETE, PRINT_ONE, PRINT_ALL, QUIT };

void FileToList(UnsortedType<HouseListing>&, std::ifstream&);
void BSTToFile(TreeType<HouseListing>);
void ConvertListToBST(UnsortedType<HouseListing>&, TreeType<HouseListing>&);
void AddHouse(TreeType<HouseListing>&);
void DeleteHouse(TreeType<HouseListing>&);
void PrintHouse(TreeType<HouseListing>&);
void PrintOwners(TreeType<HouseListing>&);
void GetCommand(CommandType&);

int main()
{
	std::ifstream masterIn;
	std::ofstream masterOut;
	CommandType cmd;

	// List Data Structure
	UnsortedType<HouseListing> houseList;

	// BST
	TreeType<HouseListing> houseBST;

	FileToList(houseList, masterIn);
	ConvertListToBST(houseList, houseBST);

	HouseListing myItem;

	GetCommand(cmd);

	while (cmd != CommandType::QUIT)
	{
		switch (cmd)
		{
		case CommandType::ADD:	AddHouse(houseBST);
			break;
		case CommandType::DELETE: DeleteHouse(houseBST);
			break;
		case CommandType::PRINT_ONE: PrintHouse(houseBST);
			break;
		case CommandType::PRINT_ALL: PrintOwners(houseBST);
			break;
		default:
			std::cout << "Invalid command option: enum! CONTACT SUPPORT!" << std::endl;
			break;
		}
		GetCommand(cmd);
	}

	//BSTToFile(houseBST);

	return 0;
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

void BSTToFile(TreeType<HouseListing> houseBST)
{
	HouseListing item;
	std::ofstream masterOut;

	int length;
	bool finished = true;
	HouseListing record;

	masterOut.open("masterOut.mf");
	
	length = houseBST.NumberOfNodes();


	masterOut.close();
}

void AddHouse(TreeType<HouseListing>& houseList)
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

void DeleteHouse(TreeType<HouseListing>& houseList)
{
	bool found;
	HouseListing item;

	item.GetKeyNameOnlyFromUser();
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

void PrintHouse(TreeType<HouseListing>& houseBST)
{
	bool found;
	HouseListing item;

	item.GetKeyNameOnlyFromUser();
	houseBST.RetrieveItem(item, found);

	std::cout << std::endl;
	std::cout << "Retrieving Record" << std::endl;

	if (found)
		item.PrintHouseToScreen();
	else
		std::cout << "Owner not in list.";

	std::cout << std::endl;

	return;
}

void PrintOwners(TreeType<HouseListing>& houseTree)
{
	int length = 0;

	length = houseTree.NumberOfNodes();
	std::cout << "Number of people on List: " << length << std::endl << std::endl;
	houseTree.PrintTreeToScreen();

	std::cout << std::endl;
	std::cout << "Operation Complete." << std::endl;
}

void GetCommand(CommandType& command)
{
	// Prompt User
	std::cout << "Operations are listed below. \n"
		<< "Enter the appropriate uppercase letter and "
		<< "press return." << std::endl;
	std::cout << "A : Add a house to the list of hosues." << std::endl;
	std::cout << "D : Delete a specific owner's house." << std::endl;
	std::cout << "P : Print the information about an owner's house." << std::endl;
	std::cout << "L : Print all the names on the screen." << std::endl;
	std::cout << "Q : Quit Processing." << std::endl;

	char letter;
	std::cin >> letter;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	bool ok = false;
	while (!ok)
	{
		ok = true;
		letter = toupper(letter);

		switch (letter)
		{
		case 'A': command = CommandType::ADD;
			break;
		case 'D': command = CommandType::DELETE;
			break;
		case 'P': command = CommandType::PRINT_ONE;
			break;
		case 'L': command = CommandType::PRINT_ALL;
			break;
		case 'Q': command = CommandType::QUIT;
			break;
		default:
			std::cout << "Letter entered is not one of the specified uppercase commands. " << std::endl;
			std::cout << "Reenter and press return." << std::endl;

			std::cin >> letter;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ok = false;
			break;
		}
	}
}

void ConvertListToBST(UnsortedType<HouseListing>& homeListing, TreeType<HouseListing>& homeBST)
{
	int length = homeListing.LengthIs();
	HouseListing record;
	
	homeListing.ResetList();

	for (int ndx = 0; ndx < length; ndx++)
	{
		homeListing.GetNextItem(record);
		homeBST.InsertItem(record);
	}
}