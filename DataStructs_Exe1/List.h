#ifndef __LIST_H
#define __LIST_H
#include "ListNode.h"

template <typename T>
class List
{

private:
	ListNode<T> * head = nullptr;
	ListNode<T> * tail = nullptr;
	int size = 0;

public:
	List() {}

	~List() {
		MakeEmpty();
	}

	void MakeEmpty();

	bool IsEmpty() {
		return head == nullptr;
	}

	ListNode<T> * First() {
		return head;
	}

	ListNode<T> * Last() {
		return tail;
	}

	void InsertAfter(ListNode<T> & nodeToInsertAfter, T value) {
		if (IsEmpty()) {
			head = tail = new ListNode<T>(value, nullptr, nullptr);
			return;
		}

		nodeToInsertAfter.SetNext(new ListNode<T>(value, nodeToInsertAfter.GetNext(), &nodeToInsertAfter));

		if (&nodeToInsertAfter == tail) {
			tail = nodeToInsertAfter.GetNext();
		}
	}

	void Insert(T value) {
		ListNode<T> * newNode = new ListNode<T>(value, nullptr, nullptr);

		if (IsEmpty()) {
			head = tail = newNode;
			return;
		}

		tail->InsertAfter(newNode);
		tail = tail->GetNext();
	}

	void DeleteNode(ListNode<T> * nodeToDelete) {
		ListNode<T> tempToDelete = nodeToDelete;

		if (nodeToDelete == head) {
			*head = nodeToDelete->GetNext();
		}
		else {
			nodeToDelete->GetPrev()->SetNext(nodeToDelete->GetNext());
		}
	}
};
#endif
