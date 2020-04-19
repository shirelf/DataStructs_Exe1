#include "Stack.h"

Stack::Stack()
{
	top = nullptr;
}

Stack::~Stack()
{
	MakeEmpty();
}

void Stack::MakeEmpty()
{
	StackNode * temp;

	while (top != nullptr) {
		temp = top;
		top = top->GetNext();//GetNext...
		delete temp;
	}
}

bool Stack::IsEmpty()
{
	return (top == nullptr);
}

void Stack::Push(ItemType itemType)
{
	top = new StackNode(itemType, top);// need to change to Itemtype something... in ListNode
}

ItemType Stack::Pop()
{
	if (IsEmpty()) {
		std::cout << "Error: STACK UNDERFLOW\n";
		exit(1);
	}
	
	StackNode * temp = top;
	ItemType item = top->GetItem();// need to change to Itemtype something... in ListNode
	top = top->GetNext();
	temp->SetNext(nullptr);
	delete temp;

	return item;
}

ItemType Stack::Top()
{
	return top->GetItem();//getter value
}
