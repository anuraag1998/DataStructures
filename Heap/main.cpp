/** This is the program for implementing the priority queue
*/

#include "HEAP.h"
#include <iostream>

int main()
{
	/*insert, find min, delete min
	*/
	Heap heap;

	int cas, num;
	std::cout<<"Cases are: \n1.Insert\n2.Find min\n3.Extract min\n4.Exit\n\n";
	while(true)
	{
		std::cout<<"Enter your case:";
		std::cin>>cas;
		switch(cas)
		{
			case 1:
				std::cout<<"Enter number to insert:";
				std::cin>>num;
				heap.insert(num);
				break;
			case 2:
				if(heap.find_min() == 0)
					std::cout<<"The heap is empty\n";
				else
					std::cout<<"The minimum element is: "<<heap.find_min()<<"\n";
				break;
			case 3:
				if(heap.delete_min())
					std::cout<<"Minimum element is deleted\n";
				else
					std::cout<<"Heap is empty\n";
				break;
			case 4:
				std::cout<<"Successfully retured\n\n";
				return 0;
			case 5:
				std::cout<<"print the heap: \n";
				for(int i = 0; i < heap.size; i++)
				{
					std::cout<<heap.heap[i]<<" ";
				}
				std::cout<<"\n";
				break;
			default:
				std::cout<<"You have enter wrong choice\n";
		}
	}

	return 0;
}
