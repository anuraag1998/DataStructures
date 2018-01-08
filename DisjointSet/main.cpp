/* This is the Program for union find data structure
 *
*/
#include <iostream>
#include "GRAPH.h"
#include "union_find.h"

int main()
{
	//----------take input from the user
	int ver,edges;
	std::cout<<"Enter the number of the vertices in the graph: ";
	std::cin>>ver;

	
	//-------------creating the union find data structure
	Graph graph(ver,0);
	union_find UnionFind(graph);
	

	int cas,src,des;
	std::cout<<"Cases are:\n";
	std::cout<<"1->union\n2->find\n3->exit\n";
	while(true)
	{
		std::cout<<"Enter your case No.:";
		std::cin>>cas;
		switch(cas)
		{
			case 1:
				std::cout<<"Enter 1st vertex no. to union:";
				std::cin>>src;
				std::cout<<"Enter 2nd vertex no. to union:";
				std::cin>>des;
				if(!UnionFind.union_(src, des))
					std::cout<<"You have enter wrong edges number\n";
				break;
			case 2:
				std::cout<<"Enter 1st vertex no. to find:";
				std::cin>>src;
				std::cout<<"Enter 2nd vertex no. to find:";
				std::cin>>des;
				if(UnionFind.find_(src, des))
					std::cout<<"They are in same set\n";
				else
					std::cout<<"They are not in same set or you have enter wrong edge numbers\n";
				break;
			case 3:
				return 0;
			default:
				std::cout<<"You have enter the wrong choice\n";
		}

	}


	return 0;	
}

