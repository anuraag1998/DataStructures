#ifndef RB_H
#define RB_H

//------------------create Node of the tree 
class Node
{
	public:
		Node();
		Node* parent;
		Node* right;
		Node* left;
		int key;
		int color;
};

//------------------traversal class for the tree
class Traversal
{
	public:
		void inorder(Node*);
};

//------------------red black tree class
class RB
{
	public:
		RB();
		Node* root;
		void insert_node(int);
		void insert_fix(Node*);
		void right_rotate(Node *);
		void left_rotate(Node *);
		void delete_node(Node*, int);
		void delete_fix(Node*);
		Node* find_min_node(Node*);//-------find minimum in the tree rooted at Node* 
};

#endif
