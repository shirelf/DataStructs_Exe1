#include "ListArray.h"

#include <iostream>
using namespace std;

ListArray::ListArray()
{
	headFree = 0;
	headList = -1;
	size = 0;
	list = nullptr;
}


ListArray::~ListArray()
{
	//free(list);
}

void ListArray::makeEmpty(int size)
{
	list = new ListArrayNode[size];
	
	for (int i = 0; i < size-1; i++)
		list[i].next = i + 1;
	list[size-1].next = -1;
}
bool ListArray::isEmpty()
{
	return(headList == -1);

}

void ListArray::insertAccesibleToList(int epicenter)
{
	int nextFree;

	if (isEmpty())
	{
		
		list[headFree].computerId = epicenter;
		lastDataIndex = headFree;
		nextFree = list[headFree].next;
		list[headFree].next = -1;
		headList = headFree;
		headFree = nextFree;
		size++;
	}

	else
	{
		if (headFree != -1)
		{
			list[lastDataIndex].next = headFree;
			list[headFree].computerId = epicenter;
			lastDataIndex = headFree;
			nextFree = list[headFree].next;
			list[headFree].next = -1;
			headFree = nextFree;
			size++;
		}
		else
		{
			return;
		}
	}
}
void ListArray::deleteAfter(int prevoiusIndex)
{
	int locFree = list[prevoiusIndex].next;
	list[prevoiusIndex].next=list[locFree].next;
	//list[locFree].data = NULL;// if we change to itemp type
	list[locFree].next = headFree;
	headFree = locFree;
}

void ListArray::printLIst()
{
	for (int i = 0; i < size; i++)
		cout << list[i].computerId << " ";
}
