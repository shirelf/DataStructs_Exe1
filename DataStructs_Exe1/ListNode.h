#pragma once
class ListNode
{

private:
	int values;
	ListNode * next;

public:
	ListNode(int values, ListNode * next) {
		this->values = values;
		this->next = next;
	}

	~ListNode();
};

