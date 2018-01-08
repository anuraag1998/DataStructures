#ifndef HEAP_H
#define HEAP_H
#include <vector>


//-----heao vector is zero index vector
class Heap
{
	public:
		Heap();
		int size;
		std::vector<int> heap;
		void insert(int);
		int find_min();
		bool delete_min();
		void heapify(int);
		void build_min_heap();
		void swap(int, int);
		int parent(int);

};

#endif
