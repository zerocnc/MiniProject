#pragma once

template<class ItemType>
struct NodeType;

// Assumption: ItemType is a type for which the operators "<"
// and "==" are defined-either an appropriate built-in type or 
// a class that overloads these operators.

template<class ItemType>
class UnsortedType
{
public:

	// Class constructor
	UnsortedType();

	// Class deconstructor
	~UnsortedType();

	// Determines whether list is full.
	bool IsFull() const; // Determines whether the list is full or not.

	int LengthIs() const;

	void MakeEmpty();
	// Initialize list to empty state;
	// Post: List is empty.

	void RetrieveItem(ItemType& item, bool& found);
	// Retrieves list element whose key matches item's key
	// (if present).
	// Pre: Key member of item is initialized.
	// Post: If there is an element someItem whose key matches
	//		 item's key, then found = true and item is a copy
	//		 of someItem; otherwise found = false and item is
	//		 unchanged.
	//		 List is unchanged.

	void InsertItem(ItemType item);
	// Adds item to list.
	// Pre: List is not full.
	//		item is not in list.
	// Post: item is in list.

	void DeleteItem(ItemType& item);
	// Deletes teh element whose key matches item's key.
	// Pre: Key member of item is initialized.
	//		One and only one element in list has a key matching
	//		item's key.
	// Post: No element in list has a key matching item's key.

	void ResetList();
	// Initialize current position for an iteration though the
	// list.
	// Post: Current position is prior to first element in list.

	void GetNextItem(ItemType& item);
	// Gets the next element in list.
	// Pre: Current position is defined.
	//		Element at current position is not last in list.
	//		item is a copoy of element at current position.

private:
	NodeType<ItemType>* listData;
	int length;
	NodeType<ItemType>* currentPos;
};

template<class ItemType>
struct NodeType {
	ItemType info;
	NodeType* next;
};

// ----------------------- Class Constructors -------------------------------- //
template<class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
	length = 0;
	listData = NULL;
}

template<class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{

}

template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
// Returns true if there is no room for another NodeType node
// on the free store: false otherwise.
{
	NodeType<ItemType>* ptr;
	ptr = new NodeType<ItemType>;

	if (ptr == NULL)
		return true;
	else {
		delete ptr;
		return false;
	} // end if
}

template<class ItemType>
int UnsortedType<ItemType>::LengthIs() const
{
	return length;
}
// Determines the number of elements in the list.
// Post: Function value = number of elements in list.

template<class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{
	NodeType<ItemType>* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}

	length = 0;
}

template<class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
	bool moreToSearch;
	NodeType<ItemType>* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->info)
		{
			found = true;
			item = location->info;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}
	return;
}

template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
{
	NodeType<ItemType>* location;

	location = new NodeType<ItemType>;
	location->info = item;
	location->next = listData;
	listData = location;
	length++;
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList()
{
	currentPos = NULL;
}

template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
{
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;

	item = currentPos->info;
}

template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType& item)
{
	NodeType<ItemType>* location = listData;
	NodeType<ItemType>* tempLocation;

	// Locate the node to be deleted
	if (item == listData->info)
	{
		tempLocation = location;
		listData = listData->next;	// Delete the first node
	}
	else
	{
		while (!(item == (location->next)->info))
			location = location->next;

		// Delete node at location->next
		tempLocation = location->next;
		location->next(location->next)->next;
	}

	delete tempLocation;
	length--;
}