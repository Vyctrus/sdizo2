#pragma once
using namespace std;

class DoubleConectedList
{
	struct listElement {
		int value;
		int valueOfEdge=0;
		listElement *next;
		listElement *previous;
	};

private:
	listElement *front;
	listElement * back;
	int size = 0;

public:
	DoubleConectedList();
	~DoubleConectedList();
	void addHead(int addNumb);	//dodaj na poczatku		
	void addTail(int addNumb);	//dodaj na koncu	//chyba ok
	void addTailGraph(int addNumb, int vOfEdge);
	void addPos(int addNumb, int numbPos);	//dodanie na wybranej pozycji	
	void removeHead();	//usun na poczatku	//ok
	void removeTail();	//usun na koncu		//ok
	void removePos(int numbPos);	//usun z pozycji
	void removeValue(int numbValue);	//usun wartosc
	void append(int addNumb);

	bool searchNumb(int numbWanted);//wyszukanie elementu //Bool zawiera, nie zawiera, nie zwraca adressu gdzie, nie zwraca ilosci: ile?
	bool searchNumbGraph(int value, int verticle);

	int getNumb(int numbPos);	//pozyskanie elementu z pozycji
	int getNumbValue(int numbPos);
	void display();	//wyswietl na ekran	
	void displayWithEdgeValue();//wyswietla na ekran wersje z wartosciami krawedzi
	void displayN();
	static void loadFromFile(string fileName, DoubleConectedList * loadedArray);
	void createRand(int sizeOfArray);	//utworzenie randomowo wygenerowanej talbicy

	void removeList();
};

