//--------list is 1 index

#include "Graph.h"
#include <iostream>
#include <cstdlib>

node::node(int des, int weight)
{
	this->des = des;
	this->weight = weight;
	next = nullptr;
}

Graph::Graph(int ver)
{
	std::cout<<"This is call\n";
	list = *(new std::vector<node* >(ver+1, nullptr));
	ver_no = ver;
}
Graph::Graph()
{

}

bool Graph::add_edge(int src, int des, int weight)
{
		node* temp = new node(des, weight);

		if(list[src] == nullptr)
		{
			list[src] = temp;			
		}
		else
		{
			node* head = list[src];
			while(head->next != nullptr)
			{
				head = head->next;
			}
			head->next = temp;
		}
		//-------add in des list also
		temp = new node(src, weight);
		if(list[des] == nullptr)
			list[des] = temp;
		else
		{
			node* head = list[des];
			while(head->next != nullptr)
			{
				head = head->next;
			}
			head->next = temp;
		}

		return true;
}


