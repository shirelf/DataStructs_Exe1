#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;
#include "Network.h";

void FindAccessible(int computer, vector<int> accessibleList, char *colors, Network *network)
{
	
	colors[computer - 1] = 'b';//colors array begins from 0, computer 1 is in place 0 in the array
	accessibleList.push_back(computer);
	for (int i = 0; i < network->pairs; i++)
		if (network->pairsArrayFrists[i] == computer)
			if (colors[network->pairsArraySeconds[i]]== 'w')
				FindAccessible(network->pairsArraySeconds[i], accessibleList, colors, network);

}

void main()
{
	//TODO: cin, cout, receive the details below from the user
	int countComputers = 5;
	int pairs = 5;
	int *pairsArrayFirsts = new int[pairs] { 1, 2, 3, 4, 5};
	int *pairsArraySeconds = new int[pairs] { 2, 3, 4, 5, 1};

	
	vector<int> accessibleList;
	
	//int* accessibleList= new int[countComputers];//static base array 

	char *colors = new char[countComputers];
	for(int i=0 ; i < countComputers ; i++)// initialize all computers
		colors[i] = 'w';
	
	Network network(countComputers,pairs, pairsArrayFirsts, pairsArraySeconds); // create the network
	
	FindAccessible(1, accessibleList, colors, &network);
	

}



