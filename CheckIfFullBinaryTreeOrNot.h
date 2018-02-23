#pragma once


//A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes.
//Conversely, there is no node in a full binary tree, which has one child node.
//More information about full binary trees can be found here.
#include <iostream>
class CheckIfFullBinaryTreeOrNot {

private:
	struct node {
		int val;
		node* l;
		node* r;
		node(int _val) :
			val(_val), l(nullptr), r(nullptr) {}
	};

	typedef node* link;
	link head;
	void clearTreeR(link&);
	int isFullBinaryTreeR(link);

public:
	CheckIfFullBinaryTreeOrNot();
	~CheckIfFullBinaryTreeOrNot();
	int isFullBinaryTree() { return isFullBinaryTreeR(head); };

};
