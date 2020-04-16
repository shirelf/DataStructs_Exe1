#include <time.h>
#include <string>
#include <vector>
#include <iostream>
#include "List.h";
#include "Network.h";
#include "ListArray.h";




ListArray * FindAccessibleRec(int chosenComputerId, Network &network, char *colors, ListArray *&accessibleList)
{
	colors[chosenComputerId - 1] = 'b';//the colors array began in 0
	accessibleList->insertAccesibleToList(chosenComputerId);//
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
	char *colors = new char[comuptersCount];//change to boolean?
	for (int i = 0; i < comuptersCount; i++)
		colors[i] = 'w';
	FindAccessibleRec(chosenComputerId, network, colors, accessibleList);
	return accessibleList;
}


void main() {
	int comuptersCount;
	int connectionsCount;
	int * fromCoumptersArray;
	int * toComputersArray;

	cout << "Welcome to the find accessible network project\n";
	
	cout << "Please enter how many computers are in the network:\n";
	cin >> comuptersCount;

	cout << "Please enter how many connections you have in your network:\n";
	cin >> connectionsCount;

	fromCoumptersArray = new int[connectionsCount];
	toComputersArray = new int[connectionsCount];

	cout << "Please enter the network connections:\n";
	for (int i = 0; i < connectionsCount; i++) {
		cout << "Please enter from which computer connection number " << (i + 1) << " is\n";
		cin >> fromCoumptersArray[i];

		cout << "Please enter to which computer connection number " << (i + 1) << " is\n";
		cin >> toComputersArray[i];
	}
	
	
	Network computersNetwork(comuptersCount, connectionsCount, fromCoumptersArray, toComputersArray);
	computersNetwork.Init();


	int chosenComputerId;
	cout << "Please enter the computer id you want to make an accessible list to it:\n";
	cin >> chosenComputerId;

	ListArray *accessibleList= buildAccessibleList(comuptersCount, chosenComputerId, computersNetwork);
	accessibleList->printLIst();
}



//using namespace std;
//void main(){
//	// Testing the list
//	List<string> * strings = new List<string>();
//	strings->Insert("first node");
//	strings->Insert("second node");
//	ListNode<string> * first = strings->First();
//	strings->InsertAfter(*first, "1.5 node");
//	
//	ListNode<string> * itr = strings->First();
//
//	while (itr != nullptr) {
//		cout << itr->GetValue() << "\n";
//		itr = itr->GetNext();
//	}
//	delete strings;
//}



