#ifndef __STACK_H
#define __STACK_H
#include "ItemType.h"
#include "StackNode.h"
#include <iostream>

const int MAX_SIZE = 100;

class Stack
{
private:
	StackNode * top;

public:
	Stack();	
	~Stack();	// dtor

	void MakeEmpty();
	bool IsEmpty();			
	void Push(ItemType item);
	ItemType Pop();
	ItemType Top();


};

#endif
