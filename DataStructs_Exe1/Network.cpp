#include "Network.h"



Network::Network()
{
}


Network::Network(int computers, int pairs, vector< pair <int, int> >* pairsArray)
{
	this->computers = computers;
	this->pairs = pairs;
	this->pairsArray = pairsArray;
}

Network::~Network()
{
}
