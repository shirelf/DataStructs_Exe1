#include <time.h>
#include <string>
#include <vector>
#include <iostream>
#include "List.h"
#include "Network.h"
#include "ListArray.h"
#include "Stack.h"
#include "ItemType.h"

using namespace std;

ListArray * FindAccessible(int chosenComputerId, Network &network, char *colors, ListArray *&accessibleList) {
	//ListArray * accessibleList = new ListArray();

	Stack S;// Stack which simulates the recursion.
	ItemType Curr;   // Values of current  �recursive call�
	ItemType Next;   // Values of next �recursive call�.

	Curr = ItemType(chosenComputerId);
	S.Push(Curr);

	while (!S.IsEmpty()) {
		Curr = S.Pop();
		if (colors[Curr.getChosenComputerId() - 1] == 'w') {
			colors[Curr.getChosenComputerId() - 1] = 'b';
			accessibleList->insertAccesibleToList(Curr.getChosenComputerId());//
		}
		for(int i = network.getPairs()-1 ; i >= 0; i--)
			if (network.getPairsArrayFrists()[i] == Curr.getChosenComputerId())
				if (colors[network.getPairsArraySeconds()[i] - 1] == 'w') {
					S.Push(Curr);
					Next = ItemType(network.getPairsArraySeconds()[i]);
					S.Push(Next);
				}
	}

	return accessibleList;
}

ListArray * FindAccessibleRec(int chosenComputerId, Network &network, char *colors, ListArray *&accessibleList)
{
	colors[chosenComputerId - 1] = 'b';
	accessibleList->insertAccesibleToList(chosenComputerId);

	for (int i = 0; i < network.getPairs(); i++)
		if (network.getPairsArrayFrists()[i] == chosenComputerId)
			if (colors[network.getPairsArraySeconds()[i]-1] == 'w')
				FindAccessibleRec(network.getPairsArraySeconds()[i], network, colors, accessibleList);

	return accessibleList;
}

ListArray * buildAccessibleList(int comuptersCount, int chosenComputerId, Network &network)
{
	ListArray *accessibleList = new ListArray();
	accessibleList->makeEmpty(comuptersCount);
	char *colors = new char[comuptersCount];

	for (int i = 0; i < comuptersCount; i++)
		colors[i] = 'w';

	FindAccessibleRec(chosenComputerId, network, colors, accessibleList);
	return accessibleList;
}

ListArray * buildAccessibleList2(int comuptersCount, int chosenComputerId, Network &network)
{
	ListArray *accessibleList = new ListArray();
	accessibleList->makeEmpty(comuptersCount);
	char *colors = new char[comuptersCount];

	for (int i = 0; i < comuptersCount; i++)
		colors[i] = 'w';

	FindAccessible(chosenComputerId, network, colors, accessibleList);
	return accessibleList;
}


void main() {
	int comuptersCount;
	int connectionsCount;
	int * fromCoumptersArray;
	int * toComputersArray;

	//cout << "Welcome to the find accessible network project\n";
	
	//cout << "Please enter how many computers are in the network:\n";
	cin >> comuptersCount;

	//cout << "Please enter how many connections you have in your network:\n";
	cin >> connectionsCount;

	fromCoumptersArray = new int[connectionsCount];
	toComputersArray = new int[connectionsCount];

	//cout << "Please enter the network connections:\n";
	for (int i = 0; i < connectionsCount; i++) {
		//cout << "Please enter from which computer connection number " << (i + 1) << " is\n";
		cin >> fromCoumptersArray[i];

		//cout << "Please enter to which computer connection number " << (i + 1) << " is\n";
		cin >> toComputersArray[i];
	}
	
	
	Network computersNetwork(comuptersCount, connectionsCount, fromCoumptersArray, toComputersArray);
	computersNetwork.Init();


	int chosenComputerId;
	//cout << "Please enter the computer id you want to make an accessible list to it:\n";
	cin >> chosenComputerId;
	if (chosenComputerId < 1 || chosenComputerId > comuptersCount)
	{
		cout << "no such computer "<<chosenComputerId<<"\n";
		exit(1);
	}
	ListArray *accessibleList= buildAccessibleList(comuptersCount, chosenComputerId, computersNetwork);
	accessibleList->printLIst();

	ListArray *accessibleList2 = buildAccessibleList2(comuptersCount, chosenComputerId, computersNetwork);
	accessibleList2->printLIst();


}


