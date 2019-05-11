#include "pch.h"
#include "GraphL_OR.h"


#include "pch.h"
#include "GraphL_NO.h"


void GraphL_OR::saveToFile(string fileName)		//wersja oriented
{
	fstream wyniki;
	wyniki.open(fileName, ios::out);	//  | ios::app
	if (wyniki.good() == true) {
		wyniki << edgesNum << " " << vertsNum << endl;
		for (int i = 0; i < vertsNum; i++) {
			/*for (int j = 0; j < vertsNum; j++) {
				if (myList[i] != NULL) {
					if (myList[i]->getNumb(j) != NULL) {
						wyniki << i << " " << myList[i]->getNumb(j) << " " << 69 << endl;
					}
				}
			}*/
			if (myList[i] != NULL) {
				int j = 0;
				while (myList[i]->getNumb(j) != NULL) {		//hasnext()?
					wyniki << i << " " << myList[i]->getNumb(j) << " " << myList[i]->getNumbValue(j) << endl;
					j++;
				}
			}

			//wyniki << i << " " << myList[i]->getNumb() << " " << 69 << endl;
		}
		//wyniki << 4 << " " << 3 << " " << 69 << endl;
		wyniki.close();
	}
}

void GraphL_OR::insert_into_myList(int w_start, int w_end, int e_value)
{
	DoubleConectedList * list_h1;
	if (myList[w_start] == NULL) {
		list_h1 = new DoubleConectedList();
		//list_h1->addHead(e_value);
		list_h1->addTailGraph(w_end, e_value);
		myList[w_start] = list_h1;

		if (myList[w_end] == NULL) {
			list_h1 = new DoubleConectedList();	//not oriented
			//list_h2->addHead(e_value);
			list_h1->addTailGraph(w_start, e_value);
			myList[w_end] = list_h1;
		}
		else {
			//cout << "taka sytuacja...";
			if (!myList[w_end]->searchNumb(w_start)) {
				myList[w_end]->addTailGraph(w_start, e_value);
			}


		}

	}
	else {
		if (!myList[w_start]->searchNumb(w_end)) {
			myList[w_start]->addTailGraph(w_end, e_value);		//dodac sprawdzanie czy w liscie juz jest ta krawedz, nic nie dodawc jesli oriented
			//myList[w_end]->addTail(w_start);
			insert_into_myList(w_end, w_start, e_value);
		}

	}
}

void GraphL_OR::print_start()
{
	for (int i = 0; i < vertsNum; i++) {
		cout << i << "  ";
		if (myList[i] != NULL) {
			myList[i]->display();
		}
		else {
			cout << endl;
		}
	}
}

void GraphL_OR::printWithValues()
{
	for (int i = 0; i < vertsNum; i++) {
		cout << i << "  ";
		if (myList[i] != NULL) {
			myList[i]->displayWithEdgeValue();
		}
		else {
			cout << endl;
		}
	}
}

GraphL_OR::GraphL_OR()
{
	std::string fileName;
	std::cout << "Podaj filename : ";
	std::cin >> fileName;
	DoubleConectedList * list_h1;
	//DoubleConectedList * list_h2;
	std::fstream file;
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
		myList = new DoubleConectedList *[verts];

		for (int i = 0; i < verts; i++) {
			//matrix[i] = new int[verts];	//wiersze
			myList[i] = NULL;// zamiast zer wypelniamy ja NULL'ami "pustymi listami"
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

			//if (myList[w_start] == NULL) {
			//	list_h1 = new DoubleConectedList();
			//	//list_h1->addHead(e_value);
			//	list_h1->addTail(w_end);
			//	myList[w_start] = list_h1;

			//	
			//	list_h1 = new DoubleConectedList();	//not oriented
			//	//list_h2->addHead(e_value);
			//	list_h1->addTail(w_start);
			//	myList[w_end] = list_h1;
			//	
			//	
			//}
			//else {
			//	myList[w_start]->addTail(w_end);		//dodac sprawdzanie czy w liscie juz jest ta krawedz, nic nie dodawc jesli oriented
			//	//myList[w_end]->addTail(w_start);
			//	if (myList[w_end] != NULL) {
			//		myList[w_end]->addTail(w_start);
			//	}
			//	else {
			//		cout << "cos sie spierdolilo\n";
			//		cout << w_start << " " << w_end;
			//		cout << endl;
			//	}
			//}
			insert_into_myList(w_start, w_end, e_value);


		}

		file.close();

	}
	else {
		std::cout << "Nieudany odczyt z pliku\n";
	}
	//std::cout << vertsNum << " " << edgesNum;
}


GraphL_OR::~GraphL_OR()
{
}

