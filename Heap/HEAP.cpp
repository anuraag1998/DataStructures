#include "HEAP.h"
#include <vector>

Heap::Heap()
{
	size = 0;
}

void Heap::swap(int a, int b)
{
	int temp = heap[a];
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

	if(left <= size-1 && heap[left] < heap[index])
		min = left;
	else
		min = index;
	
	if(right <= size-1 && heap[right] < heap[min])
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
		return heap[0];
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


void Heap::insert(int key)
{
	//heap.push_back(key);
	//heap[size] = key;
	if(heap.size() > size)
		heap[size] = key;
	else
		heap.push_back(key);

	size = size+1;

	int pos = size - 1;//-------position of problem
	while(pos >= 0 && heap[parent(pos)] > heap[pos])
	{
		swap(pos, parent(pos));
		pos = parent(pos);
	}

	return;
}

bool Heap::delete_min()
{
	if(size > 0)
	{
		heap[0] = heap[size-1];
		size = size -1;
		heapify(0);
	}
	else
	{
		return false;
	}
	return true;
}