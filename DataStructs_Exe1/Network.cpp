#include "Network.h"



Network::Network()
{
}


Network::Network(int computers, int pairs, int* pairsArray)
{
	this->computers = computers;
	this->pairs = pairs;
	this->pairsArray = pairsArray;
}

Network::~Network()
{
}
