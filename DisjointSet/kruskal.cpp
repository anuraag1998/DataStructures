#include <iostream>
#include "GRAPH.h"
#include "union_find.h"

int main()
{
	int vertices,edges;
	std::cout<<"enter Number of vertices in the graph: ";
	std::cin>>vertices;
	std::cout<<"enter Number of edges in the graph: ";
	std::cin>>edges;

	Graph graph(vertices, edges);

	//----take the edges of the graph as the input

	int src,des,weight;

	for(int i =0; i < edges; i++)
	{
		std::cout<<"enter the edges source, destination and weight\n";
		std::cout<<"src: ";std::cin>>src;
		std::cout<<"des: ";std::cin>>des;
		std::cout<<"weight: ";std::cin>>weight;

		if(!graph.insert_edge(src, des, weight))
		{
			std::cout<<"You have enter wrong no. of edges\nPlease re-enter the edges\n";
			i--;
			continue;
		}
	}

	//-------make the union find class
	union_find union_f(graph);
	graph.edges_sort();


	std::cout<<"MST: \n";
	//----------------implement the kruskal algorithm
	for(int i = 1; i <= graph.n_edges; i++)
	{
		if(!union_f.find_(graph.edges[i-1].src, graph.edges[i-1].des))
		{
			std::cout<<graph.edges[i-1].src<<" "<<graph.edges[i-1].des<<" "<<graph.edges[i-1].weight<<"\n";
			union_f.union_(graph.edges[i-1].src, graph.edges[i-1].des);
		}
	}

	if(graph.n_edges == 0)
		std::cout<<"graph is empty\n";
	return 0;
}

