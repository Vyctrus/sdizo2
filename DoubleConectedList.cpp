#include "pch.h"
#include "DoubleConectedList.h"


DoubleConectedList::DoubleConectedList()
{
	back = NULL;
	front = NULL;
}


DoubleConectedList::~DoubleConectedList()
{
	listElement *iter = back;
	for (int i = 0; i < size; i++) {
		//std::cout << iter->value << " ";
		removeTail();
	}

}


void DoubleConectedList::addHead(int addNumb)
{
	listElement *currElm;
	currElm = new listElement;
	(*currElm).value = addNumb;		//element na ktorym bede pracowac

	if (size == 0) {
		front = currElm;
		back = currElm;
	}
	(*currElm).next = front; // dostawia sie przed pierwszym i wskazuje na niego
	(*currElm).previous = back; //jest rowniez za "koncowym" i wskazuje go jako poprzednika
	front->previous = currElm;
	back->next = currElm;

	front = currElm;
	++size;
}

void DoubleConectedList::addTail(int addNumb)
{
	listElement *currElm;
	currElm = new listElement;
	(*currElm).value = addNumb;		//element na ktorym bede pracowac

	if (size == 0) {
		front = currElm;
		back = currElm;
	}
	(*currElm).next = front; // dostawia sie przed pierwszym i wskazuje na niego
	(*currElm).previous = back; //jest rowniez za "koncowym" i wskazuje go jako poprzednika
	front->previous = currElm;
	back->next = currElm;

	back = currElm;//jedyna roznica miedzy addTail a addHead
	++size;
}

void DoubleConectedList::addTailGraph(int addNumb, int vOfEdge)
{
	listElement *currElm;
	currElm = new listElement;
	(*currElm).value = addNumb;		//element na ktorym bede pracowac
	(*currElm).valueOfEdge = vOfEdge;
	if (size == 0) {
		front = currElm;
		back = currElm;
	}
	(*currElm).next = front; // dostawia sie przed pierwszym i wskazuje na niego
	(*currElm).previous = back; //jest rowniez za "koncowym" i wskazuje go jako poprzednika
	front->previous = currElm;
	back->next = currElm;

	back = currElm;//jedyna roznica miedzy addTail a addHead
	++size;
}

void DoubleConectedList::addPos(int addNumb, int numbPos)
{
	if (size == 0 || numbPos == 0) {
		addHead(addNumb);
		return;
	}
	if (numbPos == size) {
		addTail(addNumb);
		return;
	}
	if (numbPos > size) {
		std::cout << "Bledna pozycja\n";
		return;
	}
	listElement *currElm;
	currElm = new listElement;
	(*currElm).value = addNumb;		//element na ktorym bede pracowac

	listElement * iter = front;
	for (int i = 0; i < numbPos - 1; i++) {
		iter = iter->next;
	}

	currElm->previous = iter;
	currElm->next = iter->next;
	iter->next->previous = currElm;
	iter->next = currElm;

	++size;
}

void DoubleConectedList::removeHead()
{
	if (size == 0) {
		return;
	}
	if (size == 1) {
		delete front;//nowe
		//delete back;
		front = NULL;
		back = NULL;
		--size;
		return;
	}
	front->previous->next = front->next;	//previous->next to to samo tutaj co back->next
	front->next->previous = front->previous;

	delete front;
	front = back->next;//front->next;
	--size;
}

void DoubleConectedList::removeTail()
{
	if (size == 0) {
		return;
	}
	if (size == 1) {
		delete front;//nowe
		//delete back;
		front = NULL;
		back = NULL;
		--size;
		return;
	}

	back->previous->next = back->next;
	back->next->previous = back->previous;
	delete back;
	back = front->previous;//back->previous;
	--size;
}

void DoubleConectedList::removePos(int numbPos)
{
	if (size == 0 || numbPos > size) {
		return;
	}
	if (size == 1) {
		delete front;
		//delete back;
		front = NULL;
		back = NULL;
		--size;
		return;
	}
	if (numbPos == 0) {
		removeHead();
		return;
	}
	if (numbPos == size - 1) {
		removeTail();
		return;
	}

	listElement * iter = front;
	for (int i = 0; i < numbPos; i++) {
		iter = iter->next;
	}
	iter->previous->next = iter->next;
	iter->next->previous = iter->previous;
	delete iter;
	--size;
}

void DoubleConectedList::removeValue(int numbValue)
{
	listElement* iter = front;
	for (int i = 0; i < size; i++) {
		if (iter->value == numbValue) {
			removePos(i);
			return;
		}
		iter = iter->next;
	}
	return;
}

void DoubleConectedList::append(int addNumb)
{
	addTail(addNumb);
}

bool DoubleConectedList::searchNumb(int numbWanted)
{
	listElement* iter = front;
	for (int i = 0; i < size; i++) {
		if (iter->value == numbWanted) {
			//std::cout << numbWanted << " -liczba jest w strukturze\n";
			return true;
		}
		iter = iter->next;
	}
	//std::cout << numbWanted << " -liczba nie ma w strukturze\n";
	return false;
}

bool DoubleConectedList::searchNumbGraph(int numbWanted, int verticle)// numbWanted nie jest potrzebny ale rozrozniam funkcje
{
	listElement* iter = front;
	for (int i = 0; i < size; i++) {
		if (iter->valueOfEdge== verticle) {
			//std::cout << numbWanted << " -liczba jest w strukturze\n";
			return true;
		}
		iter = iter->next;
	}
	//std::cout << numbWanted << " -liczba nie ma w strukturze\n";
	return false;
}

int DoubleConectedList::getNumb(int numbPos)
{
	if (size == 0 || numbPos >= size) {
		std::cout << "odwolanie do blednego indeksu\n";
		return 0;
	}
	if (size == 1 || numbPos == 0) {
		return front->value;
	}

	listElement * iter = front;
	for (int i = 0; i < numbPos; i++) {
		iter = iter->next;
	}

	return iter->value;
}

int DoubleConectedList::getNumbValue(int numbPos)
{
	if (size == 0 || numbPos >= size) {
		std::cout << "odwolanie do blednego indeksu\n";
		return 0;
	}
	if (size == 1 || numbPos == 0) {
		return front->valueOfEdge;
	}

	listElement * iter = front;
	for (int i = 0; i < numbPos; i++) {
		iter = iter->next;
	}

	return iter->valueOfEdge;
}

void DoubleConectedList::display()
{
	listElement *iter = front;
	for (int i = 0; i < size; i++) {
		std::cout << iter->value << " ";
		iter = iter->next;
	}
	std::cout << std::endl;
	iter = front;
	
	/*iter = back;		//wyswietlanie od tylu
	for (int i = 0; i < size; i++) {
		std::cout << iter->value << " ";
		iter = iter->previous;
	}
	std::cout << std::endl;*/

}

void DoubleConectedList::displayWithEdgeValue()
{
	listElement *iter = back;
	for (int i = 0; i < size; i++) {
		std::cout << iter->value << "";
		std::cout << "(" << iter->valueOfEdge << ") ";
		iter = iter->next;
	}
	std::cout << std::endl;
}

void DoubleConectedList::displayN()// wyswietlanie od tylu
{
	listElement *iter = back;
	for (int i = 0; i < size; i++) {
		std::cout << iter->value << " ";
		iter = iter->previous;
	}
	std::cout << std::endl;
}

void DoubleConectedList::loadFromFile(string fileName, DoubleConectedList * loadedList)
{
	std::fstream file;
	std::string  dataRow;
	file.open(fileName, std::ios::in);	//fileName = data_in.txt
	if (file.good() == true) {
		getline(file, dataRow);
		std::cout << "Poprawny odczyt z pliku\n";
		int numberOfData = std::stoi(dataRow);
		for (int i = 0; i < numberOfData; i++) {
			getline(file, dataRow);
			loadedList->append(std::stoi(dataRow));
		}
		file.close();
		return;//std::fstream &file
	}
	else {
		std::cout << "Nieudany odczyt z pliku\n";
	}
	return;
}

void DoubleConectedList::createRand(int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++) {
		addHead(rand());	//tutaj mozna dac rand() % maksymalna liczba
	}
}


