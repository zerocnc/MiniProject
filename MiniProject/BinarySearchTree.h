#pragma once

#include <fstream>
#include "Queue.h"

enum OrderType { PRE_ORDER, IN_ORDER, POST_ORDER };

template<class ItemType>
struct TreeNode
{
	ItemType info;
	TreeNode* left;
	TreeNode* right;
};

template<class ItemType>
class TreeType
{
private:
	TreeNode<ItemType>* root;

	// To traverse tree in node -> left -> right
	//					   left -> node -> right
	//					   left -> node -> right -> node
	Queue<ItemType> preQue;
	Queue<ItemType> inQue;
	Queue<ItemType> postQue;

public:
	// General Constructors & Deconstructor
	TreeType();
	TreeType(const TreeType<ItemType>*& originalTree);

	// TODO: delete tree pointers.
	~TreeType();

	int NumberOfNodes() const;

	// Operations to tree structure.
	// Insert-Delete - Recursive
	void MakeEmpty();
	bool IsEmpty();
	bool IsFull();
	void RetrieveItem(ItemType& item, bool& found);
	void InsertItem(ItemType item);
	void DeleteItem(ItemType item);
	void PrintTree(std::fstream& outFile);
	void ResetTree(OrderType order);
	void GetNextItem(ItemType& item, OrderType order, bool& finished);
	void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* orginalTree);

	void operator=(const TreeType<ItemType>& orginalTree);

	// Visit Trees in PRE_ORDER, IN_ORDER, POST_ORDER
	void PreOrder(TreeNode<ItemType>* tree, Queue<ItemType>& preQue);
	void InOrder(TreeNode<ItemType>* tree, Queue<ItemType>& inQue);
	void PostOrder(TreeNode<ItemType>* tree, Queue<ItemType>& postQue);

private:
	// Auxiliary Functions
	void Destory(TreeNode<ItemType>*& tree);
	void DeleteNode(TreeNode<ItemType>*& tree);
	void Delete(TreeNode<ItemType>*& tree, ItemType item);
	void Print(TreeNode<ItemType>* tree, std::fstream& outFile);

	int CountNodes(TreeNode<ItemType>*) const;

};

/// <summary>Default constructor.
/// <remarks>Sets root to NULL.</remarks>
/// </summary>
template<class ItemType>
TreeType<ItemType>::TreeType()
{
	root = nullptr;
}

/// <summary>Default deconstructor.
/// <remarks>Destorys current tree.</remarks>
/// </summary>
template<class ItemType>
TreeType<ItemType>::~TreeType()
{
	Destory(root);
}

/// <summary>Default deconstructor.
/// <remarks>Post: Tree is empty; nodes have been deallocated, destorys current tree.</remarks>
/// </summary>
template<class ItemType>
void TreeType<ItemType>::Destory(TreeNode<ItemType>*& tree)
{
	if (tree != nullptr)
	{
		Destory(tree->left);
		Destory(tree->right);
		delete tree;
	}
}

/// <summary>Initializes tree to empty state.
/// <remarks>Tree exist and is empty.</remarks>
/// </summary>
template<class ItemType>
void TreeType<ItemType>::MakeEmpty()
{
	Destory(root);
	root = nullptr;

	return;
}

/// <summary>Determines if the tree is full.
/// <remarks>Function value = (tree is full).</remarks>
/// </summary>
template<class ItemType>
bool TreeType<ItemType>::IsEmpty()
{
	return true;
}

/// <summary>Determines if the tree is full.
/// <remarks>Function value = (tree is full).</remarks>
/// </summary>
template<class ItemType>
bool TreeType<ItemType>::IsFull()
{
	return;
}

/// <summary>Determines how many elements are in the tree.
/// <remarks>Function value = (number of elements within tree).</remarks>
/// </summary>
template<class ItemType>
int TreeType<ItemType>::NumberOfNodes() const
{
	return CountNodes(root);
}

/// <summary>Counts how many elements there are in the tree though recursion.
/// <remarks>Function value = (number of elements within tree).</remarks>
/// </summary>
template<class ItemType>
int TreeType<ItemType>::CountNodes(TreeNode<ItemType>* tree) const
{
	if (tree == nullptr)
		return 0;
	else
		return CountNodes(tree->left) +	CountNodes(tree->right) + 1;
}


/// <summary> Recursively searches the tree for item.
/// <remark>Post: If there is an element someItem, whose key matches item's, found
///		  is true and item is set to a copy of someItem; otherwise found is
///		  false and item is unchanged.
/// </remark>
/// </summary>
template<class ItemType>
void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found)
{
	if (tree == nullptr) {
		// Item is not found
		found = false;
	}
	else if (item < tree->info)
	{
		// Search left side of the subtree.
		Retrieve(tree->left, item, found);
	}
	else if (item > tree->info)
	{
		// Search right side of the subtree.
		Retrieve(tree->right, item, found);
	}
	else
	{
		// Item is found
		item = tree->info;
		found = true;
	}
	return;
}

/*
///	<summary>Retrieves an item given by the caller if matching key is found.
///	<remarks>If there is an element some Item whose key matches item's key;
///		     then found = true and item is a copy of some Item; otherwise
///			 found = false and item is unchanged. Tree is unchanged.</remarks>
///	</summary>*/
template<class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
	Retrieve(root, item, found);
}

template<class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item)
{
	if (tree == NULL)
	{
		// Insertion place found.
		tree = new TreeNode<ItemType>;
		tree->right = NULL;
		tree->left = NULL;
		tree->info = item;
	}
	else if (item < tree->info)
	{
		// Insert in left subtree
		Insert(tree->left, item);
	}
	else
	{
		// Insert in right subtree
		Insert(tree->right, item);
	}
}


/// <summary>Sets data to the info member of the right most node in the tree.
/// <remarks>Post: Traverse the tree to find the predecessor the the current node given.</remarks>
/// </summary>
template<class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
{
	while (tree->right != NULL)
	{
		tree = tree->right;
	}
	data = tree->info;
}

/// <summary> Deletes the node pointed to by the tree.
/// <remarks>Post: The user's data is in the noded pointed to by the tree is no longer
///				   in the tree.  If tree is a leaf node or has only one non-NULL child pointer, the
///				   node pointed to by the tree is deleted; otherwise , the user's data is replaced by
///				   its logical predecessor and the predecessor's node is deleted.</remarks>
/// </summary>
template<class ItemType>
void TreeType<ItemType>::DeleteNode(TreeNode<ItemType>*& tree)
{
	ItemType data;
	TreeNode<ItemType>* tempPtr;

	tempPtr = tree;
	if (tree->left == nullptr)
	{
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == nullptr)
	{
		tree = tree->left;
		delete tempPtr;
	}
	else
	{
		GetPredecessor(tree, data);
		tree->info = data;

		// Delete predecessor node.
		Delete(tree->left, data);
	}

}

/// <summary>Inserts an item into the tree.
/// <remarks>Assumes tree is not full and item doesn't exist in tree
///			 Post Condition: Item is in tree and Binary Search property is maintained (balanced).</remarks>
/// </summary>
template<class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item)
{
	// Calls recursive function Insert to insert item into tree.
	Insert(root, item);
}

/// <summary>Deletes a node based in the tree based on the key given.
/// <remarks>Assumes tree is not not empty and item exist.
///			 Post Condition: Item is removed from the tree.</remarks>
/// </summary>
template<class ItemType>
void TreeType<ItemType>::Delete(TreeNode<ItemType>*& tree, ItemType item)
{
	if (item < tree->info)
	{
		// Looks in the left subtree
		Delete(tree->left, item);
	}
	else if (item > tree->info)
	{
		// Looks in the right subtree
		Delete(tree->right, item);
	}
	else
	{
		// Node found, call DeleteNode.
		DeleteNode(tree);
	}
}

/// <summary>Removes an item from the tree if its key matches.
/// <remarks>Key member of item is initialized. One and only one element in three has a key matching item's key
///			 Post Condition: No element in tree has key matching item's key.</remarks>
/// </summary>
template<class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item)
{
	Delete(root, item);
	return;
}

/// <summary>Prints the values in the tree in ascending key order on outFile.
/// <remarks>Precondition: outFile is opened for writing.
///			 Postcondition: Items in the tree have been printed in ascending key order; outFile is still open.</remarks>
/// </summary>
template<class ItemType>
void Print(TreeNode<ItemType>* tree, std::ofstream& outFile)
{
	if (tree != NULL)
	{
		// Prints left side first.
		Print(tree->left, outFile);
		outFile << tree->left;
		// Prints right side second.
		Print(tree->right, outFile);
	}
}

/// <summary>Prints the values in the tree in ascending key order on outFile.
/// <remarks>Precondition: outFile is opened for writing.
///			 Postcondition: Items in the tree have been printed in ascending key order; outFile is still open.</remarks>
/// </summary>
template<class ItemType>
void TreeType<ItemType>::PrintTree(std::fstream& outFile)
{
	// Calls recursive function Print to print items in the tree.
	Print(root, outFile);
}

template<class ItemType>
void TreeType<ItemType>::Print(TreeNode<ItemType>* tree, std::fstream& outFile)
{
	if (tree != nullptr)
	{
		// Print(tree->left, outFile);
		// outFile << tree->info;
		std::cout << tree->info;
		Print(tree->right, outFile);
	}
}

/// <summary>Initilizes current position for an iteration though the tree in OrderType order.
/// <remarks>Precondition: Tree is not empty.
///			 Postcondition: Current position is prior to root of tree.</remarks>
/// </summary>
template<class ItemType>
void TreeType<ItemType>::ResetTree(OrderType order)
{
	switch (order)
	{
	case PRE_ORDER: PreOrder(root, preQue);
		break;
	case IN_ORDER: InOrder(root, inQue);
		break;
	case POST_ORDER: PostOrder(root, postQue);
		break;
	}

	return;
}

/// <summary>Gets the next element in tree.
/// <remarks>Precondition: Current position defined; Element at current position is not last in tree.
///			 Postcondition: Current psoition is one position beyond current position at entry to GetNextItem.
///			 finished = (current psoition is last)
///			 item is copy of element at current position</remarks>
/// </summary>
// Make your own Stack & queue ADT
template<class ItemType>
void TreeType<ItemType>::GetNextItem(ItemType& item, OrderType order, bool& finished)
{
	finished = false;

	switch (order)
	{
	case PRE_ORDER: preQue.Dequeue(item);
		if (preQue.IsEmpty())
			finished = true;
		break;
	case IN_ORDER: inQue.Dequeue(item);
		if (inQue.IsEmpty())
			finished = true;
		break;
	case POST_ORDER: postQue.Dequeue(item);
		if (postQue.IsEmpty())
			finished = true;
		break;
	}

	return;
}

/// <summary>Calls recrusive function CopyTree to copy tree pointed to by originalTree into self.
/// <remarks>Precondition: If tree is not empty.</remarks>
/// </summary>
template<class ItemType>
TreeType<ItemType>::TreeType(const TreeType<ItemType>*& originalTree)
{
	CopyTree(root, originalTree);
}

template<class ItemType>
void TreeType<ItemType>::operator=(const TreeType<ItemType>& originalTree)
{
	if (&originalTree == this)
	{
		return;
	}
	else
	{
		// Deallocate existing tree nodes.
		Destory(root);
		CopyTree(root, orginalTree.root);
	}
}

template<class ItemType>
void TreeType<ItemType>::CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* orginalTree)
{
	if (orginalTree == nullptr)
		copy = nullptr;
	else
	{
		copy = new TreeNode<ItemType>;
		copy->info = orginalTree->info;
		CopyTree(copy->left, orginalTree->left);
		CopyTree(copy->right, orginalTree->right);
	}
}

template<class ItemType>
void TreeType<ItemType>::PreOrder(TreeNode<ItemType>* tree, Queue<ItemType>& preQue)
{
	if (tree != nullptr)
	{
		preQue.Enqueue(tree->info);
		PreOrder(tree->left, preQue);
		PreOrder(tree->right, preQue);
	}
}

template<class ItemType>
void TreeType<ItemType>::InOrder(TreeNode<ItemType>* tree, Queue<ItemType>& inQue)
{
	if (tree != nullptr)
	{
		InOrder(tree->left, inQue);
		inQue.Enqueue(tree->info);
		InOrder(tree->right, inQue);
	}
}

template<class ItemType>
void TreeType<ItemType>::PostOrder(TreeNode<ItemType>* tree, Queue<ItemType>& postQue)
{
	if (tree != nullptr)
	{
		PostOrder(tree->left, postQue);
		PostOrder(tree->right, postQue);
		postQue.Enqueue(tree->info);
	}
}