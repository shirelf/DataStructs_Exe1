#ifndef __NETWORK_H
#define __NETWORK_H

#include <vector>;
#include <iostream>;
#include "List.h";

using namespace std;

class Network
{
public:
	int computersCount;
	int pairs;
	vector< pair <int, int> >* pairsArray;

	Network();

	Network(int computersCount, int pairs, vector< pair <int, int> > * pairsArray);
	~Network();
};
#endif