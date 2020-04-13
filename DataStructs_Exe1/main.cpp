#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;
#include "Network.h";

void FindAccessible(int computer, int* accessibleList, char *colors, Network *network)
{
	colors[computer-1] = 'b';//colors array begins from 0, computer 1 is in place 0 in the array
	for (int i = 0; i < network->pairs; i++)
		if (network->pairsArray[i]->first == computer)
			if (colors[network->pairsArray[i]->second] == 'w')
				FindAccessible(network->pairsArray[i +1]->first, accessibleList, colors, network);

}

void main()
{
	//TODO: cin, cout, receive the details below from the user
	int countComputers = 5;
	int pairs = 5;
	int *array = new int[pairs * 2] { 1, 2, 3, 4, 5, 2, 3, 4, 5, 1 };
	
	
	vector< pair <int, int> > * pairsArray = initializePairsArray(array, pairs * 2);
	free(array);
	
	int* accessibleList= new int[countComputers];//static base array 

	char *colors = new char[countComputers];
	for(int i=0 ; i < countComputers ; i++)// initialize all computers
		colors[i] = 'w';
	
	Network network(countComputers,pairs, pairsArray); // create the network
	
	FindAccessible(1, accessibleList, colors, &network);
	

}




vector< pair <int, int> > *initializePairsArray(int *arr, int size)
{
	vector< pair <int, int> > * pairsArray= new vector< pair <int, int> >;
	for (int i = 0; i < size; i = i + 2)
		pairsArray->push_back(make_pair(arr[i], arr[i+1]));
	
	return pairsArray;
}