#pragma once

#include <algorithm>
//Given a binary tree, find the maximum path sum.The path may start and end at any node in the tree.
//
//Example:
//
//Input: Root of below tree
//	   1
//	  / \
//	 2   3
//	Output: 6
//
//	See below diagram for another example.
//	1 + 2 + 3

#include <iostream>

class MaximumPathSumInBinaryTree {

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
	int maximumPath;
	void clearTreeR(link);
	int maximumSumPathR(link);

public:
	MaximumPathSumInBinaryTree();
	~MaximumPathSumInBinaryTree();
	int maximumSumPath() { return maximumSumPathR(head); };


};

