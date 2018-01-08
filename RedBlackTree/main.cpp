#include <iostream>
#include "RB.h"


int main()
{
	RB rb_tree;//--------------------create red black tree
	int cas,key;
	Traversal tr;//------------------create traversal class
	std::cout<<"This is the program for Red Black Tree\n\n";
	std::cout<<"cases are: \n1:-->insert key\n2:-->delete key\n3:-->print tree in inorder traversal\n4:-->exit\n\n";

	while(true)
	{
		std::cout<<"enter case:";
		std::cin>>cas;
		switch(cas)
		{
			//---------------insert node in tree
			case 1:
				std::cout<<"enter key to insert:";
				std::cin>>key;
				rb_tree.insert_node(key);
				break;
			//---------------delete node in tree
			case 2:
				std::cout<<"enter node to delete:";
				std::cin>>key;
				rb_tree.delete_node(rb_tree.root,key);
				break;
			//---------------traverse the tree
			case 3:
				tr.inorder(rb_tree.root);
				break;
			case 4:
				std::cout<<"Successfully exit the program\n";
				return 0;
			default:
				std::cout<<"You have enter wrong choice\n";
				
		}

	}

	return 0;	
}
