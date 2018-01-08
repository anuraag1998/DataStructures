//********--------------
//*****---------This is the program for BST------------****** 
//*****--------The implementation for BST is in BST.cpp file
//This is the program for binary search tree 
//--------
//------***************------------------

#include <iostream>
#include "BST.h"
using namespace std;


int main()
{
	int cas;
	string r_num,name,gen;
	cout<<"cases for BST are:\n1:--Inserting\n2:--Searching\n3:--Deleting\n4---EXIT\n\n";
	cout<<"enter the case: ";
	cin>>cas;

	BST bin_tree;
	while(cas != 0)
	{
		switch(cas)
		{
			case 1:
				cout<<"enter the person roll Number name gender to insert\n";
				cin>>r_num>>name>>gen;
				bin_tree.insert_node(name,r_num);
				break;
			case 2:
				cout<<"enter the roll number for search\n";
				cin>>r_num;
				if(bin_tree.search_node(r_num))
					cout<<"The person is in the list\n";
				else
					cout<<"The person is not in the list\n";
				break;
			case 3:
				cout<<"enter the roll number to delete\n";
				cin>>r_num;
				bin_tree.delete_node(r_num);
				break;
			case 4:
				cout<<"Successfully exit\n";
				return 0;
			default:
				cout<<"you have not enter the correct choice\n";
		}
		cout<<endl;
		cout<<"Enter Case: ";
		cin>>cas;
	}
	return 0;
}
