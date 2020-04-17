#pragma

template <typename T>
struct Node {
	T data;
	int next;
	int prev;
};

template <typename T>
class ArrayList
{

private:
	int headList = 0;
	int tailList = 0;
	int headFree = 0;
	int arraySize = 0;
	Node<T> * listArray;

public:
	ArrayList() {}

	~ArrayList() {
		//MakeEmpty();
	}

	void MakeEmpty();

	bool IsEmpty() {
		return arraySize == 0;
	}

	T First() {
		return listArray[headList].data;
	}

	T Last() {
		return listArray[tailList].data;
	}

	/*void InsertAfter(ListNode<T> & nodeToInsertAfter, T value) {
		if (IsEmpty()) {
			head = tail = new ListNode<T>(value, nullptr, nullptr);
			return;
		}

		nodeToInsertAfter.SetNext(new ListNode<T>(value, nodeToInsertAfter.GetNext(), &nodeToInsertAfter));

		if (&nodeToInsertAfter == tail) {
			tail = nodeToInsertAfter.GetNext();
		}
	}*/

	void Insert(T value) {
		listArray[headFree].data = value;
		listArray[headFree].next = 

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
