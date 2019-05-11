

#include "pch.h"
#include <iostream>

int main()
{
	/*GraphM_NO *testGraph;
	testGraph = new GraphM_NO();
	testGraph->printStart();
	system("pause");
    std::cout << "Hello World!\n"; */

	/*GraphL_NO *testGraphL;
	testGraphL = new GraphL_NO();
	testGraphL->print_start();
	cout << endl;
	cout << "---------------------------";
	cout << endl;
	testGraphL->printWithValues();
	string userInput;
	cout << "Podaj plik do ktorego chcesz zpaisac: ";
	cin >> userInput;
	testGraphL->saveToFile(userInput);
	system("pause");*/


	/*BinaryHeap* testBH;
	testBH = new BinaryHeap();
	testBH->createRand(20);
	testBH->display();
	testBH->display3();
	testBH = NULL;
	system("pause");*/

	GraphM_NO *testGraph;
	testGraph = new GraphM_NO();
	testGraph->printStart();


	algorithms::algorithm_PrimV2(testGraph);
	algorithms::algorithm_Dijkstra(testGraph, 1);
	system("pause");
}

