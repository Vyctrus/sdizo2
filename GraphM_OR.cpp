#include "pch.h"
#include "GraphM_OR.h"

using namespace std;

void GraphM_OR::loadEdgeInfo(std::string fileName)
{
	int edgesNum_check = 0;
	std::fstream file;
	std::string  dataRow;
	file.open(fileName, std::ios::in);	//fileName = data_in.txt
	if (file.good() == true) {

		int a;
		if (file >> a)
		{
			printf("%d ", a);
		}
		edgesNum = a;
		if (file >> a)
		{
			printf("%d ", a);
		}
		vertsNum = a;


		if (file >> a)
		{
			printf("\n%d", a);
		}
		int tester = a;
		std::cout << std::endl << tester;

		/*std::getline(file, dataRow);
		std::cout << "Poprawny odczyt z pliku\n";
		int numberOfData = std::stoi(dataRow);
		for (int i = 0; i < numberOfData; i++) {
			getline(file, dataRow);
			//loadedArray->append(std::stoi(dataRow));
		}*/
		file.close();
		return;//std::fstream &file
	}
	else {
		std::cout << "Nieudany odczyt z pliku\n";
	}
	std::cout << vertsNum << " " << edgesNum;
	return;

}

GraphM_OR::GraphM_OR(int verts, int edges)
{
	vertsNum = verts;
	edgesNum = edges;
	matrix = new int *[verts];
	for (int i = 0; i < verts; i++) {
		matrix[i] = new int[edges];	//wiersze
	}
	for (int i = 0; i < verts; i++) {
		for (int j = 0; j < edges; j++) {
			matrix[i][j] = 0;
		}
	}
}

void GraphM_OR::printStart()
{
	cout << "  ";
	for (int i = 0; i < vertsNum; i++) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < vertsNum; i++) {
		cout << i << " ";
		for (int j = 0; j < edgesNum; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << vertsNum << " " << edgesNum;
}

GraphM_OR::GraphM_OR()
{
	int edgesNum_check = 0;
	std::string fileName;
	std::cout << "Podaj filename : ";
	std::cin >> fileName;

	std::fstream file;
	//std::string  dataRow;
	file.open(fileName, std::ios::in);	//fileName = data_in.txt
	if (file.good() == true) {

		int a;
		if (file >> a)
		{
			//printf("%d ", a);
		}
		edgesNum = a;
		if (file >> a)
		{
			//printf("%d ", a);
		}
		vertsNum = a;
		////////////////////////////////////
		/*if (file >> a)
		{
			printf("%d ", a);
		}
		arg3 = a;*/
		//---------------------------------

		int verts = vertsNum;
		int edges = edgesNum;
		matrix = new int *[verts];
		for (int i = 0; i < verts; i++) {
			matrix[i] = new int[verts];	//wiersze
		}
		for (int i = 0; i < verts; i++) {
			for (int j = 0; j < verts; j++) {
				matrix[i][j] = 0;
			}
		}


		//-----------------odczyt krawedzi
		int w_start;
		int w_end;
		int e_value;//waga
		while (file >> a) {
			//printf("\n%d ", a);
			w_start = a;
			if (file >> a) {
				//printf("%d ", a);
				w_end = a;
			}
			else {
				cout << "nieoczekiwany blad!\n";
			}

			if (file >> a) {
				//printf("%d ", a);
				e_value = a;
			}
			else {
				cout << "nieoczekiwany blad!\n";
			}
			//cout << "My little values: " << w_start << " " << w_end << " " << e_value;

			if (w_start < vertsNum && w_end < vertsNum) {
				matrix[w_start][w_end] = e_value;
				matrix[w_end][w_start] = e_value;		//bo niezorientowany
				edgesNum_check++;
			}
			else {
				cout << "bledny wierzcholek\n";
			}

		}

		file.close();

	}
	else {
		std::cout << "Nieudany odczyt z pliku\n";
	}
	//std::cout << vertsNum << " " << edgesNum;


}


GraphM_OR::~GraphM_OR()
{
}
