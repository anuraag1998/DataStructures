#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class edge
{
	public:
		edge(int, int, int);//-----(source, destination, weight)
		int src;
		int des;
		int weight;
};

class Graph
{
	public:
		Graph(int ,int);//--------(no. of vertices, no. of edges)
		int n_edges;
		int n_vertices;
		std::vector<edge> edges;//-----------graph as collection of edges
		bool insert_edge(int, int, int);//---------(source, destination, weight)
		void edges_sort();//---------sort the edges according to their weights
};

#endif