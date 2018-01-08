#include "HEAP.h"
#include <vector>
//---------zero index heap

Heap::Heap()
{
	size = 0;
}

void Heap::swap(int a, int b)
{
	node_h temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
	return;
}

//------assume the heap is formed
//------take the actual index of the array
void Heap::heapify(int index)
{
	int min = index;
	int left = 2*index + 1;
	int right = 2*index + 2;

	if(left <= size-1 && heap[left].weight < heap[index].weight)
		min = left;
	else
		min = index;
	
	if(right <= size-1 && heap[right].weight < heap[min].weight)
		min = right;
	
	if(min != index)
	{
		swap(min,index);
		heapify(min);
	}

	return;

}

void Heap::build_min_heap()
{
	for(int i = size/2-1; i >=0; i--)
	{
		heapify(i);
	}
	return;
}

int Heap::find_min()
{
	if(size > 0)
		return heap[0].weight;
	else
	{
		return 0;
	}
}

int Heap::parent(int index)
{
	if(index%2 == 0){
		int temp = index/2 -1;
		if(temp == -1)
			return 0;
		else
			return temp;
	}
	else
		return index/2;
}


void Heap::insert(int vertex, int key)
{
	//heap.push_back(key);
	//heap[size] = key;
	node_h temp = *(new node_h);
	temp.ver = vertex;
	temp.weight = key;
		
	if(heap.size() > size)
	{
		heap[size] = temp;
	}
	else
	{

		heap.push_back(temp);
	}

	size = size+1;

	int pos = size - 1;//-------position of problem
	while(pos >= 0 && heap[parent(pos)].weight > heap[pos].weight)
	{
		swap(pos, parent(pos));
		pos = parent(pos);
	}

	return;
}

node_h Heap::delete_min()
{
	node_h temp = heap[0];
	heap[0] = heap[size-1];
	size = size -1;
	heapify(0);
	return temp;
}

bool Heap::update(int des, int weight)
{
	int pos = -1;
	for(int i = 0; i < size; i++)
	{
		if(heap[i].ver == des && heap[i].weight > weight)
		{
			heap[i].weight = weight;
			pos = i;
		}
		
	}
	if(pos == -1)
		return false;

	while(pos >= 0 && heap[parent(pos)].weight > heap[pos].weight)
	{
		swap(pos, parent(pos));
		pos = parent(pos);
	}
	

	return true;
}