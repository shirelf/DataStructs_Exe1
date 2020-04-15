#ifndef __LISTNODE_H
#define __LISTNODE_H
#include <stdlib.h>

using namespace std;

template <typename T>
class ListNode
{

private:
	T value;
	ListNode * next = nullptr;
	ListNode * prev = nullptr;

public:
	ListNode(T value, ListNode * next, ListNode * prev) {
		this->value = value;
		this->next = next;
		this->prev = prev;
	}

	~ListNode() {
		if (next != nullptr) prev->SetNext(next);
		if (prev != nullptr) next->SetPrev(prev);
	}

	void InsertAfter(ListNode<T> * newNode) {
		newNode->next = next;
		next = newNode;
	}
	
	ListNode * DeleteAfter() {
		ListNode * temp = next;
		if (next == nullptr) return nullptr;
		next = temp->next;
		return temp;
	}
	
	T GetValue() {
		return value;
	}
	
	ListNode * GetNext() {
		return next;
	}
	
	void SetNext(ListNode<T> * nextNode) {
		next = nextNode;
	}

	ListNode * GetPrev() {
		return prev;
	}

	void SetPrev(ListNode<T> * prevNode) {
		prev = prevNode;
	}
};
#endif
