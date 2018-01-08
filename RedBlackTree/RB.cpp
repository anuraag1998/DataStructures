//*******This is the program for red black tree
//*****************************

//-------red is 0
//-------black is 1

#include "RB.h"
#include <iostream>

//---------this is nil node of tree
Node::Node()
{
	this->parent = nullptr;
	this->left = nullptr;
	this->right = nullptr;
	this->key = -99;
	this->color = 0;

}

//----------------------------------inorder traversal of tree
void Traversal::inorder(Node* root)
{
	if(root && root->key != -99)
	{
		inorder(root->left);
		std::cout<<root->key<<" color:"<<root->color<<std::endl;
		inorder(root->right);
	}
}

//-----------------------------------intialize rb tree with root point to nullptr
RB::RB()
{
	root = nullptr;
}

//-----------------------------------insert in rb tree
void RB::insert_node(int key)
{
	//-------------insert normally as bst insertion
	Node *rb_nil = new Node;//-----------create nil node
	rb_nil->color = 1;
	
	Node *new_node = new Node;//--------create new node
	new_node->key = key;
	new_node->left = rb_nil;
	new_node->right = rb_nil;
	new_node->parent = rb_nil;


	if(root == nullptr)
	{
		root = new_node;
	}
	else
	{
		Node* temp = root;
		while(true)
		{
			if(key < temp->key)
			{
				if(temp->left->key == -99)//----nullptr
				{
					temp->left = new_node;
					new_node->parent = temp;	
					break;
				}
				else
					temp = temp->left;
			}
			else
			{
				if(temp->right->key == -99)
				{
					temp->right = new_node;
					new_node->parent = temp;
					break;
				}
				else
					temp = temp->right;
			}
		}
	}


	/*-----fix the property invalidate by the newly added red node---
	*/
	insert_fix(new_node);
}


//----------------rotate tree right
void RB::right_rotate(Node* n)
{
	if(n == root)
		root = n->left;

	Node *n_left = n->left;

	n->left = n_left->right;

	if (n->left != nullptr)
		n->left->parent = n;

	n_left->parent = n->parent;

	//-----it is changing root
	if (n->parent == nullptr)
		root = n_left;

	else if (n == n->parent->left)
		n->parent->left = n_left;

	else
		n->parent->right = n_left;

	n_left->right = n;
	n->parent = n_left;
}

//----------------rotate tree left
void RB::left_rotate(Node* n)
{
	if(n == root)
		root = n->right;

	Node *n_right = n->right;

	n->right = n_right->left;

	if (n->right != nullptr)
		n->right->parent = n;

	n_right->parent = n->parent;

	if (n->parent == nullptr)
		root = n_right;

	else if (n == n->parent->left)
		n->parent->left = n_right;

	else
		n->parent->right = n_right;

	n_right->left = n;
	n->parent = n_right;
}


//--------------------insert fix 
void RB::insert_fix(Node* n)
{
	if(n == root)
		n->color = 1;
	while(n->parent->color != 1)
	{
		if(n==root)
			n->color == 1;
		else
		{
			//-----------------newly added red node(voilate node) will surely have grandparent 
			Node* grandp = n->parent->parent;
			//----------------if uncle is red node
			if(grandp->right->color == 0 && grandp->left->color == 0)
			{
				grandp->right->color =1; grandp->left->color = 1;
				grandp->color = 0;
				n = grandp;
				insert_fix(n);
			}
			else
			{
				/*if uncle is black then will be four cases according to orentation
				 *----------------so that proper left and right rotation happen
				 */
				if( grandp->left->left == n)
				{
					right_rotate(grandp);
					grandp->color = 0;
					n->parent->color = 1;			
				}
				else if( grandp->left->right == n)
				{
					left_rotate(n->parent);
					n = n->left;
				}
				else if(grandp->right->right == n)
				{
					left_rotate(grandp);
					grandp->color = 0;
					n->parent->color = 1;
				}
				else
				{
					right_rotate(n->parent);
					n = n->right;
				}
			}
		}
	}
}


/*----find minimum in the tree rooted at n-------
 * */
Node* RB::find_min_node(Node* n)
{
	Node* temp = n;
	if(temp->key != -99)
	{
		while(temp->right->key != -99)
			temp = temp->right;
	}
	return temp;
}


//--------------pass it as node* as we need its color as well
//Node* n can be nullptr 
//***********************************************************
void RB::delete_fix(Node* n)
{
	Node* sibl;
	while(n != root && n->color == 1)
	{
		if(n->parent != nullptr && n->parent->left != nullptr)
		{
			if(n->parent->left == n)
				sibl = n->parent->right;
			else
				sibl = n->parent->left;
		}
		else
			sibl = nullptr;



		//---------------sibling:red 
		if(sibl != nullptr && sibl->color == 0)
		{
			sibl->parent->color = 0;
			sibl->color = 1;
			if(sibl->parent->right == sibl)
			{
				sibl->color = 1;
				sibl->parent->color = 0;
				left_rotate(sibl->parent);
			}
			else{
				sibl->color = 1;
				sibl->parent->color = 0;
				right_rotate(sibl->parent);
			
			}
		}
		
		//----------sibling:black
		
		else if(sibl == nullptr)
		{
			root = nullptr;
			break;
			//sibl->parent->color = 1;
		}
		
		//---------sibling:black , child of sibling:both black
		else if(sibl != nullptr && sibl->left->color == 1 && sibl->right->color == 1) 
		{
			sibl->color = 0;
			//sibl->parent->color = 1;
			n = n->parent;//----new x
		}
		//----------left child of sibl:red and right child of sibl: black
		else if(sibl!= nullptr && sibl->left->color == 0 && sibl->right->color == 1)
		{
			//=-------case:3 a 
			if(n->parent->left == n)
			{
				right_rotate(sibl);
				sibl->color = 0;
				sibl->parent->color = 1;
			}
			//---------case:3 c
			else
			{
				right_rotate(n->parent);
				sibl->color = 0;
				sibl->right->color = 1;
				sibl->left->color = 1;
				//n = sibl;
				n = root;
			}
		}
		else if(sibl!=nullptr && sibl->right->color == 0)
		{
			//---case 3: b
			if(n->parent->left == n)
			{
				left_rotate(n->parent);
				sibl->color = 0;
				sibl->right->color = 1;
				sibl->left->color = 1;
				//n = sibl;
				n = root;
			}
			//----case 3: d
			else
			{
				left_rotate(sibl);
				sibl->color = 0;
				sibl->parent->color = 1;
			}
		}
	}
	n->color = 1;
	return;
}


//-----delete node n in tree rooted at rt
void RB::delete_node(Node*rt,int n)
{
	//--------------first search for key to delete
	//--------------according to the normal binary tree
	Node* temp = rt;
	Node* fix;
	while(temp->key != n)
	{
		if(n < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}


	/*-----delete according to the normal bst -------
	 *
	 */
	int color;	
	if(temp->left->key == -99 && temp->right->key == -99)
	{
		if(temp->parent->left == temp)
			temp->parent->left = temp->left;
		else
			temp->parent->right = temp->left;
		
		temp->left->parent = temp->parent;

		if(temp == root)
			root = nullptr;

		fix = temp->left;
		color = temp->color;
		delete(temp);
		if(color)
			delete_fix(fix);

	}
	else if(temp->left->key == -99)
	{
		if(temp->parent->left == temp)
		{
			temp->parent->left = temp->right;
		}
		else
		{
			temp->parent->right = temp->right;
		}
		temp->right->parent = temp->parent;
		fix = temp->right;

		if(temp == root)
			root = temp->right;

		delete(temp);
		if(color)
			delete_fix(fix);

	}
	else if(temp->right->key == -99)
	{
		if(temp->parent->left == temp)
		{
			temp->parent->left = temp->left;
		}
		else
		{
			temp->parent->right = temp->left;
		}
		temp->left->parent = temp->parent;
		fix = temp->left;

		if(temp == root)
			root = temp->left;

		delete(temp);
		delete_fix(fix);
	}
	else
	{
		Node* temp2 = this->find_min_node(temp->left);
		int t_key = temp->key;
		temp->key = temp2->key;
		temp2->key = t_key;

		delete_node(temp2,temp2->key);

	}

	/*--------now fix the voilation of property by the deletion node-------------
	 * ---------------------------------------------------------------------------
	 */ 
	//-----here it is called by the node
	return;
}


