#include "union_find.h"
#include "GRAPH.h"

//----------constructor of the union class
union_find::union_find(Graph grp)
{
	//------------intialize the all member having only single member
	union_arr.resize(grp.n_vertices+1);
	for(int i = 1; i <= grp.n_vertices; i++)
		union_arr[i] = i;
}

//------find the root of connected graph in which src exists
int union_find::find_root(int src)
{
	while(union_arr[src] != src)
		src = union_arr[src];
	return src;
}

//----------union the vertex a and b
bool union_find::union_(int a, int b)
{
	//---------check for valid vertex number
	if(a >= union_arr.size() || b >= union_arr.size())
	{
		return false;
	}

	int r1 = find_root(a);
	int r2 = find_root(b);
	//-----------check the root of both vertices
	union_arr[r1] = r2;
	return true;
}

//---------find whether the vertex a and b are in same set or not
bool union_find::find_(int a, int b)
{
	if(a >= union_arr.size() || b >= union_arr.size())
		return false;

	//--------find the root of both the vertex
	int r1 = find_root(a);
	int r2 = find_root(b);

	if(r1 == r2)
		return true;
	else 
		return false;
}
