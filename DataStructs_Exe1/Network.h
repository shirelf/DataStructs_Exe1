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
	vector< pair <int, int> >* pairsArray;

	Network();

	Network(int computers, int pairs, vector< pair <int, int> > * pairsArray);
	~Network();
};
#endif