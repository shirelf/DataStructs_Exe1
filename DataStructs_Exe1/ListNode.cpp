#include "ListNode.h"



ListNode::ListNode()
{
	next = NULL;
}

ListNode::ListNode(int computer, ListNode * ptr)
{
	this->computer = computer;
	this->next = ptr;
}


ListNode::~ListNode()
{
}

void ListNode::insertAfter(ListNode * newNode)
{
	newNode->next = next;
	next = newNode;
}
