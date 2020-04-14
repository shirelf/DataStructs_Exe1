#ifndef __LISTNODE_H
#define __LISTNODE_H
#include <stdlib.h>

using namespace std;
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

	void insertAfter(ListNode *newNode);
	

private:
	int computer;
	ListNode* next;
};
#endif
