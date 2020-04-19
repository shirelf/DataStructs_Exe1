#pragma once
#include "ItemType.h"

class StackNode {
private:
	ItemType item;
	StackNode * next;

public:
	StackNode() {}

	StackNode(ItemType item, StackNode * next = nullptr) {
		this->item = item;
		this->next = next;
	}
	
	~StackNode() {}

	ItemType GetItem() {
		return item;
	}

	void SetItem(ItemType item) {
		this->item = item;
	}

	StackNode * GetNext() {
		return next;
	}

	void SetNext(StackNode * next) {
		this->next = next;
	}
};