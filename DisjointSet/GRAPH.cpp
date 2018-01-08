#include "GRAPH.h"

//--------------edge with src and des
edge::edge(int sr, int des, int weight)
{
	src = sr;
	this->des = des;
	this->weight = weight;
}

//---------initialize graph using cons
Graph::Graph(int n_ver, int n_ed)
{
	n_edges = n_ed;
	n_vertices = n_ver;
}

//----------insert edges in the edge vector of the graph
bool Graph::insert_edge(int sr, int des, int weight)
{
	//--------check for valid src and destination number
	if(sr > n_vertices || des > n_vertices)
		return false;
	edge *ed = new edge(sr, des, weight);
	edges.push_back(*ed);
	return true;
}

//-----------sort the edges according to the edge weight
void Graph::edges_sort()
{
	edge temp(0,0,0);
	for(int i = 0; i < n_edges-1; i++)
	{
		for(int j = i+1; j < n_edges; j++)
		{
			if(this->edges[i].weight > this->edges[j].weight)
			{
				temp = edges[i];
				edges[i] = edges[j];
				edges[j] = temp;
			}				
		}
	}
}