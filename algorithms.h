#pragma once
class algorithms
{
public:
	algorithms();
	~algorithms();
	static void algorithm_Prim(GraphM_NO* myGraph);//nie uzywac kto w boga wierzy
	static void algorithm_PrimV2(GraphM_NO* myGraph);
	static void algorithm_Dijkstra(GraphM_NO* myGraph, int verticleStart);//zmienic na graphM-OR
	static void algorithm_DijkstraV2(GraphM_NO* myGraph, int verticleStart);//zmienic na graphM-OR

};

