#include "List.h"

template <typename T>
void List<T>::MakeEmpty() {
	ListNode<T> * current = head;
	ListNode<T> * next;

	while (current != nullptr) {
		next = current->GetNext();
		free(current);
		current = next;
	}

	size = 0;
}