#include "Network.h"



Network::Network()
{
}


Network::Network(int computersCount, int connectionsCount, int * fromCopmutersArray, int * toComputersArray)
{
	this->computerNetworksArray = new List<int>[computersCount]();
	this->computersCount = computersCount;
	this->pairs = connectionsCount;
	this->pairsArrayFrists = fromCopmutersArray;
	this->pairsArraySeconds = toComputersArray;

}

Network::~Network()
{
}

void Network::Init() {
	for (int i = 0; i < pairs; i++) {
		computerNetworksArray[pairsArrayFrists[i]].Insert(pairsArraySeconds[i]);
	}
}

