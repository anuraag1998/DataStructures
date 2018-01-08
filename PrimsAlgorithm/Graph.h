//----------list is 1 index

#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class node
{
	public:
		node(int, int);
		int des;
		int weight;
		class node* next;
};

class Graph
{
	//-----------add edge
public:
	Graph();
	Graph(int);//-------cons for intialising the graph
	int ver_no;//-----------vertices in the graph
	std::vector<node* > list;//----adjency list
	bool add_edge(int , int , int);//-------src, des, weight
};

#endif