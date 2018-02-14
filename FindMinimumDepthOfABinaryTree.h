#pragma once
//Given a binary tree, find its minimum depth.The minimum depth is the number of 
//nodes along the shortest path from root node down to the nearest leaf node.
//
//For example, minimum height of below Binary Tree is 2.
//             1
//        2        3
//    4       5
#include <algorithm> 

class FindMinimumDepthOfABinaryTree{

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
	int minimumLengthR(link);
	void clearTreeR(link);


public:
	FindMinimumDepthOfABinaryTree();
	~FindMinimumDepthOfABinaryTree();
	int minimumLength() { return minimumLengthR(head); }

};
