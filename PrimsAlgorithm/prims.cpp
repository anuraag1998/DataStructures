#include "Graph.h"
#include "HEAP.h"
#include <iostream>
#include <vector>

int main()
{
	std::cout<<"This is the program for finding the MST using prims algorithm\n\n\n";
	int ver,ed,src,des,weight,fir,sec;
	std::cout<<"Enter the number of vertex in the graph: ";
	std::cin>>ver;
	std::cout<<"Enter the number of the edges in the graph: ";
	std::cin>>ed;

	Graph graph(ver);

	for(int i =0; i < ed; i++)
	{
		std::cout<<"Enter first vertex: ";
		std::cin>>fir;
		std::cout<<"Enter second vertex: ";
		std::cin>>sec;
		std::cout<<"Enter weight:";
		std::cin>>weight;

		graph.add_edge(fir, sec, weight);
	}

	//----------nodes which are in mst
	Heap heap;

	for(int i = 0; i < ver; i++)
	{
		if(i == 0)
			heap.insert(1,0);
		else
			heap.insert(i+1,1000);		
	}

	//--parent of the vertex
	std::vector<int > parent(ver+1, 0);
	for(int i = 0; i <= ver; i++)
	{
		parent[i] = i;
	} 

	//-------------included or not in mst
	std::vector<bool> included(ver+1, false);

	
	node_h min_node; 
	while(heap.size != 0)
	{
		//----get minimum weight node from the heap
		min_node = heap.delete_min();
		int ver = min_node.ver;
		//------add vertex to mst
		included[min_node.ver] = true;


		node* temp = graph.list[ver];
		while(temp != nullptr)
		{
			if(included[temp->des] == false)
			{
				//-------update the key in heap
				//-------if it is less than original and not yet included in MST set
				if(heap.update(temp->des, temp->weight))
				{
					parent[temp->des] = min_node.ver;
				}
			}
			temp = temp->next;
		}

	}

	std::cout<<"MST is \n";

	for(int i =0; i <= ver; i++)
	{
		if(parent[i] != i)
			std::cout<<i<<"---"<<parent[i]<<"\n";
	}

	return 0;
}