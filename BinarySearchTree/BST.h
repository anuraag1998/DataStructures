#ifndef BST_H
#define BST_H


class Node
{
	public:
		std::string roll_number;
		std::string name;
		std::string gender;
		Node* parent;
		Node* left;
		Node* right;

};

class BST
{
	public:
		BST();
		Node* root;
		int insert_node(std::string, std::string);
		bool search_node(std::string);
		int delete_node(std::string);
		int retrive_info(std::string);
};

#endif
