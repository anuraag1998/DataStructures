#include <iostream>
#include "BST.h"
using namespace std;

BST::BST()
{
	root = NULL;
}

bool BST::search_node(string roll_number)
{
	if(root == NULL)
		return false;
	else
	{
		Node* temp = root;
		while(temp != NULL)
		{
			if(roll_number < temp->roll_number){
				temp = temp->left;
				}
			else if(roll_number > temp->roll_number){
				temp = temp->right;
				}
			else
				return true;
		}		
		return false;
	}
}


int BST::insert_node(string name, string roll_number)
{
	//-----check whether root is null or not
	if(root == NULL)
	{
		Node* temp = new Node;
		temp->name = name;
		temp->roll_number = roll_number;
		temp->right = NULL;temp->left = NULL;temp->parent = NULL;
		root = temp;
	}
	else
	{
		//-make copy of root
		Node* temp = root;
		Node* temp2;
		//---------iterator up to leaf to insert
		while(temp != NULL)
		{
			if(roll_number < temp->roll_number)
			{
				if(temp->left == NULL)
				{
					temp2 = new Node;
					temp2->name = name;
					temp2->roll_number = roll_number;
					temp2->left = NULL;temp2->right = NULL;temp2->parent = temp;
					temp->left = temp2; 
					return 0;
				}
				else
					temp = temp->left;
			
			}
			else if(roll_number > temp->roll_number)
			{
				if(temp->right == NULL)
				{
					temp2 = new Node;
					temp2->name = name;
					temp2->roll_number = roll_number;
					temp2->left = NULL;temp2->right = NULL;temp2->parent = temp;
					temp->right = temp2; 		
					return 0;

				}
				else
					temp = temp->right;
			
			}
			else
			{
				cout<<"already present\n";
				return 0;
			
			}
		}		
	}
		return 0;

}

Node* find_minimum(Node* temp)
{
		Node* res = temp;
		string min = temp->roll_number;
		while(temp != NULL)
		{
			if(temp->roll_number < min){
				min = temp->roll_number;res = temp;}
			
			temp = temp->left;
		}
		return res;
}

int BST::delete_node(string s)
{
	//---------delete node according to three cases
	if(!search_node(s))
	{
		cout<<"The roll number is not in list\n";
		return 0;
	}
	else
	{
		Node* temp = root;
		while(temp->roll_number != s)
		{
			if(s < temp->roll_number)
				temp = temp->left;
			else
				temp = temp->right;
		}

		if(temp == root)
		{
			root = NULL;
			delete(temp);
			return 0;
		}
		//--------if it a leaf node
		if(temp->left == NULL && temp->right == NULL)
		{
			if(temp->parent->left == temp)
				temp->parent->left = NULL;
			else
				temp->parent->right = NULL;
			
			delete(temp);
		}//------------if it has single child
		else if(temp->left == NULL)
		{
			if(temp->parent->left == temp)
			{
				temp->parent->left = temp->right;
				temp->right->parent = temp->parent;
			}
			else
			{
				temp->parent->right = temp->right;
				temp->right->parent = temp->parent;
			}
			delete(temp);
		}
		else if(temp->right == NULL)
		{
			if(temp->parent->left == temp)
			{
				temp->parent->left = temp->left;
				temp->left->parent = temp->parent;
			}
			else
			{
				temp->parent->right = temp->left;
				temp->left->parent = temp->parent;
			}
			delete(temp);
		}
		else
		{
			Node* temp2 = find_minimum(temp->right);
			temp->name = temp2->name;
			temp->roll_number = temp2->roll_number;
			
			if(temp2->parent->left == temp2)
			{
				temp2->parent->left = NULL;
			}
			else
				temp2->parent->right = NULL;
			delete(temp2);

		}

	}

	return 0;
}





