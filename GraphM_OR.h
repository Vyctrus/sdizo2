#pragma once
class GraphM_OR
{
private:
	int ** matrix;
	int vertsNum;
	int edgesNum;
public:
	void loadEdgeInfo(std::string str);
	GraphM_OR(int verts, int edges);
	void printStart();
	GraphM_OR();
	~GraphM_OR();
};



