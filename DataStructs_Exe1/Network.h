#ifndef __NETWORK_H
#define __NETWORK_H

#include <vector>;
#include <iostream>;

using namespace std;

class Network
{
public:
	int computers;
	int pairs;
	int* pairsArrayFrists;
	int* pairsArraySeconds;

	Network();

	Network(int computers, int pairs, int * pairsArrayFrists, int* pairsArraySeconds);
	~Network();
};
#endif