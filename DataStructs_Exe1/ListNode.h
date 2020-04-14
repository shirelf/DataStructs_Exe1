#ifndef __LISTNODE_H
#define __LISTNODE_H
#include <stdlib.h>

using namespace std;
class ListNode
{

public:
	
	ListNode();
	ListNode(int computer, ListNode *ptr=NULL);
	~ListNode();

	void insertAfter(ListNode *newNode);
	

private:
	int computer;
	ListNode* next;
};
#endif
