#pragma once
class GraphL_OR
{
private:
	DoubleConectedList ** myList;
	void saveToFile(string fileName);
	void insert_into_myList(int w_start, int w_end, int e_value);
	int edgesNum;
	int vertsNum;
public:
	void print_start();
	void printWithValues();
	GraphL_OR();
	~GraphL_OR();
};



