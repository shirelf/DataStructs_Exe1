#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;
#include "Network.h";
void FindAccessible(int computer, int* accessibleList, char *colors, Network *network)
{
	colors[computer] = 'b';
	for (int i = 0; i < network->pairs; i=i + 2)
		if (network->pairsArray[i] == computer)
			if (colors[network->pairsArray[i + 1]] == 'w')
				FindAccessible(network->pairsArray[i + 1], accessibleList, colors, network);

}

void main()
{
	int countComputers = 5;
	int pairs = 5;
	int *array = new int[pairs*2];
	
	int* accessibleList= new int[countComputers];

	char *colors = new char[countComputers];
	for(int i=0 ; i < countComputers ; i++)
		colors[i] = 'w';
	
	Network network(countComputers,pairs,array);
	FindAccessible(0, accessibleList, colors, &network);

	//vector< pair <int, int> >  pairsArray= initializePairsArray(str);

}




//vector< pair <int, int> > initializePairsArray(string str)
//{
//	vector< pair <int, int> > pairsArray;
//	pairsArray.push_back(make_pair(str[0], str[1]));
//	
//	
//	return 0;
//}