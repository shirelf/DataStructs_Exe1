#include "Network.h"



Network::Network()
{
}


Network::Network(int computersCount, int pairs, vector< pair <int, int> >* pairsArray)
{
	List *networkListArray = new List[computersCount];

	for (int i = 0; i < pairs; i++) {
		
	}

	this->computersCount = computersCount;
	this->pairs = pairs;
	this->pairsArray = pairsArray;


}

Network::~Network()
{
}
