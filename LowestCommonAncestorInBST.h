#pragma once

//Given values of two values n1 and n2 in a Binary Search Tree, 
//find the Lowest Common Ancestor(LCA).You may assume that both the values exist in the tree.
//Let T be a rooted tree.The lowest common ancestor between two nodes n1 and n2 is defined as the lowest 
//node in T that has both n1 and n2 as descendants(where we allow a node to be a descendant of itself).

#include <iostream>

class LowestCommonAncestorInBST {

private:
	struct node {
		int val;
		node* l;
		node* r;
		node(int _val) :
			val(_val), l(nullptr), r(nullptr){}
	};

	typedef node* link;
	link _head;
	int _val1;
	int _val2;
	int _LCA;
	void clearTreeR(link&);
	int searchLCAR(link);
	int helperSwitch(int, int, int);

public:
	LowestCommonAncestorInBST(int, int);
	~LowestCommonAncestorInBST();
	int searchLCA() { return searchLCAR(_head); }

};
