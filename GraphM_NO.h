#pragma once
//NOT OREIENTED MATRIX GRAPH


class GraphM_NO
{
private:
	/*int ** matrix;
	int vertsNum;
	int edgesNum;*/
	//bool **matrix_b;
	
	
public:
	int ** matrix;
	int vertsNum;
	int edgesNum;

	static void algorithm_Prim(GraphM_NO myGraph);
	void loadEdgeInfo(std::string str);
	
	void printStart();
	//GraphM_NO();
	GraphM_NO();
	GraphM_NO(int verts, int edges);
	~GraphM_NO();
};

