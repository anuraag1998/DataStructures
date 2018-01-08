#ifndef HEAP_H
#define HEAP_H
#include <vector>
//------zero index heap

class node_h
{
public:
	int ver;
	int weight;
}
;
//-----heao vector is zero index vector
class Heap
{
	public:
		Heap();
		int size;
		std::vector<node_h> heap;
		void insert(int, int);//--------vertex , wei
		int find_min();
		node_h delete_min();
		void heapify(int);
		void build_min_heap();
		void swap(int, int);
		bool update(int, int);
		int parent(int);

};

#endif
