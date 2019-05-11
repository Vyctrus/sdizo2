#pragma once
#include "pch.h"

class GraphL_NO
{
private:
	DoubleConectedList ** myList;
	void insert_into_myList(int w_start, int w_end, int e_value);
	int edgesNum;
	int vertsNum;
public:
	void print_start();
	void printWithValues();
	void saveToFile(string fileName);
	GraphL_NO();
	~GraphL_NO();
};

