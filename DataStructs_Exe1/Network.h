#ifndef __NETWORK_H
#define __NETWORK_H

#include <vector>;
#include "List.h";
using namespace std;

class Network
{
private:
	int computersCount;
	int pairs;
	int* pairsArrayFrists;
	int* pairsArraySeconds;
	List<int> * computerNetworksArray;

public:
	Network();

	Network(int computers, int pairs, int * pairsArrayFrists, int* pairsArraySeconds);
	~Network();
	void Init();
};
#endif