#ifndef union_find_H
#define  union_find_H
#include <vector>
#include "GRAPH.h"

//---------union find class 
class union_find
{
	public:
		std::vector<int> union_arr;
		union_find(Graph);//----------intialize vector with size = vertex in graph
		bool union_(int ,int);//------union the vertex 1 and 2
		bool find_(int, int);//-------find the vertex 1 and 2 whether they are in same set or not
		int find_root(int);//---------find the root of 1st vertex
};

#endif