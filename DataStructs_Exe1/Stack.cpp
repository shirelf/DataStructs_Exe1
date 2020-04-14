#include "Stack.h"



Stack::Stack()
{
	top = NULL;
}


Stack::~Stack()
{
	MakeEmpty();
}

void Stack::MakeEmpty()
{
	ListNode *temp;
	while (top != NULL) {
		temp = top;
		top = top->next;//GetNext...
		delete temp;
	}
}

bool Stack::IsEmpty()
{
	return (top==NULL);
}


void Stack::Push(ItemType * itemType)
{
	top = new ListNode(itemType, top);// need to change to Itemtype something... in ListNode
}

ItemType * Stack::Pop()
{
	if (IsEmpty()) {
		cout << "Error: STACK UNDERFLOW\n";
		exit(1);
	}
	ListNode *temp = top;
	ItemType item = top->value;// need to change to Itemtype something... in ListNode
	delete temp;
	return(item);
}

ItemType * Stack::Top()
{
	return top.getValue();//getter value
}
