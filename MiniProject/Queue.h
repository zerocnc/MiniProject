// For NULL
#include <stddef.h>
#pragma once

template<class ItemType>
struct QueueNodeType
{
	ItemType info;
	QueueNodeType<ItemType>* next;
};

template<class ItemType>
class Queue
{
public:
	Queue();
	~Queue();
	void MakeEmpty();
	void Enqueue(ItemType);
	void Dequeue(ItemType&);
	bool IsFull() const;
	bool IsEmpty() const;

private:
	QueueNodeType<ItemType>* qFront;
	QueueNodeType<ItemType>* qRear;
};

template<class ItemType>
Queue<ItemType>::Queue()
{
	qFront = NULL;
	qRear = NULL;
}

template<class ItemType>
Queue<ItemType>::~Queue()
{
	MakeEmpty();
}

template<class ItemType>
void Queue<ItemType>::MakeEmpty()
{
	QueueNodeType<ItemType>* tempPtr;

	while (qFront != NULL)
	{
		tempPtr = qFront;
		qFront = qFront->next;
		delete tempPtr;
	}
	qFront = NULL;
}

template<class ItemType>
void Queue<ItemType>::Enqueue(ItemType newItem)
{
	QueueNodeType<ItemType>* newNode;

	newNode = new QueueNodeType<ItemType>;
	newNode->info = newItem;
	newNode->next = NULL;

	if (qRear == NULL)
		qFront = newNode;
	else
		qRear->next = newNode;

	qRear = newNode;

}

template<class ItemType>
void Queue<ItemType>::Dequeue(ItemType& item)
{
	QueueNodeType<ItemType>* tempPtr;

	tempPtr = qFront;
	item = qFront->info;
	qFront = qFront->next;

	if (qFront == NULL)
		qRear = NULL;
	delete tempPtr;
}

template<class ItemType>
bool Queue<ItemType>::IsFull() const
{
	QueueNodeType<ItemType>* ptr;

	ptr = new QueueNodeType<ItemType>;

	if (ptr == NULL)
	{
		return true;
	}
	else
	{
		delete ptr;
		return false;
	}
}

template<class ItemType>
bool Queue<ItemType>::IsEmpty() const
{
	return (qFront == NULL);
}