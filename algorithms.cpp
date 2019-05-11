#include "pch.h"
#include "algorithms.h"


algorithms::algorithms()
{
}


algorithms::~algorithms()
{
}

void algorithms::algorithm_Prim(GraphM_NO* myGraph)
{
	//int verts = myGraph.vertsNum;
	int verts = myGraph->vertsNum;
	int edges = myGraph->edgesNum;
	int **matrixData = myGraph->matrix;

	GraphM_NO *answerGraph = new GraphM_NO(verts, edges);
	//DoubleConectedList *answerList = new DoubleConectedList();
	int answerSum = 0;

	DoubleConectedList * usedVerticles;			//wierzcholki do ktorych mam dostep
	usedVerticles = new DoubleConectedList();

	DoubleConectedList * notUsedVerticles;			//wierzcholki do ktorych nie mam dostepu
	notUsedVerticles = new DoubleConectedList();

	BinaryHeap * posiblyVerts;
	posiblyVerts = new BinaryHeap();
	///inicjalizacja

	for (int i = 0; i < verts; i++) {		//wypelnij liste wartosciami wierzcholkow grafu
		notUsedVerticles->addTailGraph(i, 0);		//wstaw do listy
	}

	//
	int startNumb = rand() % verts;		//wybierz wierzcholek od ktorego chcesz zaczac
	int startVert = notUsedVerticles->getNumb(startNumb);	//getNumb bierze x z(x,y) wartosc z listy z pozycji startNumb
	notUsedVerticles->removePos(startNumb);		//usun z listy


	for (int i = 0; i < verts; i++) {

		int tempEdgeValue;
		int tempVert;
		//step 2
		for (int j = 0; j < verts; j++) {
			if (matrixData[startVert][j] != 0) {	//jest krawedz z "startVert" "i" do "czegos"
				tempVert = j;
				tempEdgeValue = matrixData[startVert][j];	//to wstawic do kopca trzeba
				posiblyVerts->append((-1)*tempEdgeValue, tempVert, startVert);		//mozna usuna zmienne temp,chwilowo pomagaja zrozumiec
			}
		}
		graphData temp;
		bool emptyFlag = true;
		if (!posiblyVerts->isSizeZero()) {
			temp = posiblyVerts->pop();
			emptyFlag = false;
			while (!usedVerticles->searchNumb(temp.verticleNumb)) {//jesli juz odwiedzony, usun z kopca, wez kolejny, verticle Numb to drugi argument
				temp = posiblyVerts->pop();
				emptyFlag = false;
				if (posiblyVerts->isSizeZero()) {
					//emptyFlag = true;
					break;
				}
			}
			//temp = posiblyVerts->pop();
		}
		if (!emptyFlag) {
			if (!usedVerticles->searchNumb(temp.verticleNumb)) {
				//pracuj nad temp wyciagnietym z kopca
				answerSum += temp.value;
				cout << "(" << temp.verticleFrom << ")->" << "(" << temp.verticleNumb << ")" << "value(" << temp.value << ") AnswerSum: " << answerSum << "\n";//skad dokad, jaka wartosc
				startVert = temp.verticleNumb;
			}
			else {
				cout << "cos mocno zawiodlo\n";
			}
		}
		


	}

	

}

void algorithms::algorithm_PrimV2(GraphM_NO * myGraph)
{
	cout << "Algorytm PrimV2 zaczyna dzialanie\n";
	int verts = myGraph->vertsNum;
	int edges = myGraph->edgesNum;
	int **matrixData = myGraph->matrix;
	if (verts == 1) {
		cout << "Graf ma tylko jeden wierzcholek\n";
		cout << "Algorytm PrimV2 konczy dzialanie\n";
		return;
	}
	if (verts == 0) {
		cout << "Graf nie ma wierzcholkow wierzcholek\n";
		cout << "Algorytm PrimV2 konczy dzialanie\n";
		return;
	}
	int firstVeticle = 0;
	int answerSum = 0;
	bool* usedVerticles;
	usedVerticles = new bool[verts];

	for (int i = 0; i < verts; i++) {
		usedVerticles[i] = false;
	}
	//cout << "Algorytm PrimV2 punkt1 dzialanie\n";
	BinaryHeap * posiblyVerts;
	posiblyVerts = new BinaryHeap();

	usedVerticles[0] = true;

	int foundVerts = 1;
	int fVertsFlag =1;
	//cout << verts;
	while (foundVerts != verts) {
		//cout << "Algorytm PrimV2 punkt2 dzialanie\n"; //algorytm wiesza sie w tej petli
		fVertsFlag = foundVerts;
		for (int i = 0; i < verts; i++) {
			if (matrixData[firstVeticle][i]!=0) {//czy istnieje polaczenie //value=0 --->brak polaczenia
				if (usedVerticles[i] == false) {//jesli uzyty juz zostal to go pomin
					posiblyVerts->append((-1)*(matrixData[firstVeticle][i]), i, firstVeticle);	//wkladam do kopca z ujemna wartoscia aby korzen(max)
					//przechowywal minimaln¹ wartoœæ
					//usedVerticles[i] = true;
				}
			}
		}
		if (!(posiblyVerts->isSizeZero())) {
			//cout << "rozmiar jest ok\n";
			while (!(posiblyVerts->isSizeZero())) {
				graphData tempX=posiblyVerts->pop();
				if (usedVerticles[tempX.verticleNumb]) {
					//jedz dalej
					if (posiblyVerts->isSizeZero()) {
						//nie rob nic bo nie masz wartosci
						//firstVeticle += 1;//rozpatruj kolejny wierzcholek
						break;
					}
				}
				else {
					answerSum += (-1)*tempX.value;
					cout << "(" << tempX.verticleFrom << ")->" << "(" << tempX.verticleNumb << ")" << "value(" << (-1)*tempX.value << ") AnswerSum: " << answerSum << "\n";//skad dokad, jaka wartosc
					usedVerticles[tempX.verticleNumb]=true;
					foundVerts += 1;
					firstVeticle = tempX.verticleNumb;
					break;
				}
			}
		}
		if (foundVerts == fVertsFlag) {
			cout << "Algorytm nie moze znalezc drzewa MST niepodlaczony wierzcholek: " << firstVeticle << endl;
			break;
		}
		
	}
	cout << "Algorytm PrimV2 konczy dzialanie\n";

}

void algorithms::algorithm_Dijkstra(GraphM_NO * myGraph, int verticleStart)
{
	cout << "Algorytm Dijkstra zaczyna dzialanie\n";
	int verts = myGraph->vertsNum;
	int edges = myGraph->edgesNum;
	int **matrixData = myGraph->matrix;
	if (verts == 1) {
		cout << "Graf ma tylko jeden wierzcholek\n";
		cout << "Algorytm Dijkstra konczy dzialanie\n";
		return;
	}
	if (verts == 0) {
		cout << "Graf nie ma wierzcholkow wierzcholek\n";
		cout << "Algorytm Dijkstra konczy dzialanie\n";
		return;
	}



	bool * usedFromQ;
	usedFromQ = new bool[verts];
	for (int i = 0; i < verts; i++) {
		usedFromQ[i] = false;
	}

	int infinity = 9999;//przeniesc definicje do *.h
	int * valueOfPaths;
	valueOfPaths = new int[verts];
	for (int i = 0; i < verts; i++) {
		valueOfPaths[i] = infinity;
	}


	int firstVert = verticleStart;
	valueOfPaths[firstVert] = 0;
	usedFromQ[firstVert] = true;

	BinaryHeap * qHeap;
	qHeap = new BinaryHeap();			//kolejka priorytetowa
	

	for (int i = 0; i < verts; i++) {
		if (i == firstVert) {
			qHeap->append(0, i, 0);
		}
		else {
			qHeap->append((-1)*infinity, i, 0);
		}
	}


	bool* usedV2;
	usedV2 = new bool[verts];
	for (int i = 0; i < verts; i++) {
		usedV2[i] = false;
	}
	////////////
	while (!qHeap->isSizeZero()) {//qHeap is not null
		graphData tempX = qHeap->pop();
		if (usedV2[tempX.verticleNumb] == true) {
			//juz to badalem, wyciagnij to i nic nie rob z tym, potrzebne ze wzgeldu na nadmiar danych w kopcu
			continue;
		}
		//tempX.verticleNumb; ---wierzcholek z kotrego wyciagmy
		int father = tempX.verticleNumb;
		for (int i = 0; i < verts; i++) {		//chce wyznaczyc sasiadow  father'a
			if (matrixData[father][i] != 0) {
				if (usedFromQ[i] == false) {//jesli uzyty juz zostal to go pomin(jesli zostaly dla niego juz rozpatrzone odnogi)
					//posiblyVerts->append((-1)*(matrixData[father][i]), i, father);
					//(nie)wkladam do kopca z ujemna wartoscia aby korzen(max) wartosc,do_gdzie, from_gdzie

					if ((valueOfPaths[father] + (matrixData[father][i])) < valueOfPaths[i]) {
						valueOfPaths[i] = (valueOfPaths[father] + (matrixData[father][i]));
						qHeap->append((-1)*valueOfPaths[i], i, father);
					}

				}
			}
		}
		usedFromQ[father] = true;
		usedV2[father] = true;//to chyba niepotrzebne, ustalane tak samo jakusedFromQ

		
		//for (int i = 0; i < verts; i++) {
		//	if (matrixData[firstVert][i] != 0) {//czy istnieje polaczenie //value=0 --->brak polaczenia
		//		if (usedVerticles[i] == false) {//jesli uzyty juz zostal to go pomin(jesli zostaly dla niego juz rozpatrzone odnogi)
		//			posiblyVerts->append((-1)*(matrixData[firstVert][i]), i, firstVert);
		//			//wkladam do kopca z ujemna wartoscia aby korzen(max) wartosc,do_gdzie, from_gdzie
		//		}
		//	}
		//}
		//if (!(posiblyVerts->isSizeZero())) {
		//	//cout << "rozmiar jest ok\n";
		//	while (!(posiblyVerts->isSizeZero())) {
		//		graphData tempX = posiblyVerts->pop();
		//		
		//		//jedz dalej, z kopca masz dane pierwszego sasiada od wskazanego punktu
		//		if ((valueOfPaths[tempX.verticleNumb]) + (-1)*(tempX.value) < valueOfPaths[tempX.verticleFrom]) {
		//			//jesli da sie dojsc szybciej niz dotychczasow¹ sciezka
		//			valueOfPaths[tempX.verticleFrom] = (valueOfPaths[tempX.verticleNumb]) + (-1)*(tempX.value);
		//		}



		//		if (posiblyVerts->isSizeZero()) {
		//			//nie rob nic bo nie masz wartosci
		//			//firstVeticle += 1;//rozpatruj kolejny wierzcholek
		//			break;
		//		}
		//		
		//		//usedVerticles[tempX.verticleNumb] = true;
		//		//foundVerts += 1;
		//		//firstVeticle = tempX.verticleNumb;
		//		//break;
		//		
		//	}
		//	usedVerticles[firstVert] = true;
		//	
		//}
		//if (foundVerts == fVertsFlag) {
		//	cout << "Algorytm nie moze znalezc drzewa MST niepodlaczony wierzcholek: " << firstVeticle << endl;
		//	break;
		//}

	}
	///////////
	cout << "Algorytm Dijkstra konczy dzialanie\n";
	for (int i = 0; i < verts; i++) {
		cout << "("<<i<<") "<<valueOfPaths[i] << endl;
	}
}

void algorithms::algorithm_DijkstraV2(GraphM_NO * myGraph, int verticleStart)
{
	cout << "Algorytm Dijkstra zaczyna dzialanie\n";
	int verts = myGraph->vertsNum;
	int edges = myGraph->edgesNum;
	int **matrixData = myGraph->matrix;
	if (verts == 1) {
		cout << "Graf ma tylko jeden wierzcholek\n";
		cout << "Algorytm Dijkstra konczy dzialanie\n";
		return;
	}
	if (verts == 0) {
		cout << "Graf nie ma wierzcholkow wierzcholek\n";
		cout << "Algorytm Dijkstra konczy dzialanie\n";
		return;
	}

	bool * usedVerticles;
	usedVerticles = new bool[verts];
	for (int i = 0; i < verts; i++) {
		usedVerticles[i] = false;
	}


	int infinity = 9999;//przeniesc definicje do *.h
	int * valueOfPaths;
	valueOfPaths = new int[verts];
	for (int i = 0; i < verts; i++) {
		valueOfPaths[i] = infinity;
	}

	int firstVert = verticleStart;
	valueOfPaths[firstVert] = 0;
	usedVerticles[firstVert] = true;// czy rozwazony?

	BinaryHeap * posiblyVerts;
	posiblyVerts = new BinaryHeap();

	////////////

	while (true) {
		for (int i = 0; i < verts; i++) {
			if (matrixData[firstVert][i] != 0) {//czy istnieje polaczenie //value=0 --->brak polaczenia
				if (usedVerticles[i] == false) {//jesli uzyty juz zostal to go pomin(jesli zostaly dla niego juz rozpatrzone odnogi)
					posiblyVerts->append((-1)*(matrixData[firstVert][i]), i, firstVert);
					//wkladam do kopca z ujemna wartoscia aby korzen(max) wartosc,do_gdzie, from_gdzie
				}
			}
		}
		if (!(posiblyVerts->isSizeZero())) {
			//cout << "rozmiar jest ok\n";
			while (!(posiblyVerts->isSizeZero())) {
				graphData tempX = posiblyVerts->pop();

				//jedz dalej, z kopca masz dane pierwszego sasiada od wskazanego punktu
				if ((valueOfPaths[tempX.verticleNumb]) + (-1)*(tempX.value) < valueOfPaths[tempX.verticleFrom]) {
					//jesli da sie dojsc szybciej niz dotychczasow¹ sciezka
					valueOfPaths[tempX.verticleFrom] = (valueOfPaths[tempX.verticleNumb]) + (-1)*(tempX.value);
				}



				if (posiblyVerts->isSizeZero()) {
					//nie rob nic bo nie masz wartosci
					//firstVeticle += 1;//rozpatruj kolejny wierzcholek
					break;
				}

				//usedVerticles[tempX.verticleNumb] = true;
				//foundVerts += 1;
				//firstVeticle = tempX.verticleNumb;
				//break;

			}
			usedVerticles[firstVert] = true;

		}
		/*if (foundVerts == fVertsFlag) {
			cout << "Algorytm nie moze znalezc drzewa MST niepodlaczony wierzcholek: " << firstVeticle << endl;
			break;
		}*/

	}
}
