#include "ListArrayNode.h"

class ListArray
{
private:
	int size;
	ListArrayNode * list;
	int headFree;
	int headList;
	int lastDataIndex;
public:
	ListArray();
	~ListArray();
	void makeEmpty(int size);
	bool isEmpty();
	void insertAccesibleToList(int epicenter);
	void deleteAfter(int prevoiusIndex);
	void printLIst();

};

