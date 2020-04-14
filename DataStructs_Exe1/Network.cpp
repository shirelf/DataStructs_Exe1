#include "Network.h"



Network::Network()
{
}


Network::Network(int computers, int pairs, int * pairsArrayFrists, int* pairsArraySeconds)
{
	this->computers = computers;
	this->pairs = pairs;
	this->pairsArrayFrists = pairsArrayFrists;
	this->pairsArraySeconds = pairsArraySeconds;

}

Network::~Network()
{
}
