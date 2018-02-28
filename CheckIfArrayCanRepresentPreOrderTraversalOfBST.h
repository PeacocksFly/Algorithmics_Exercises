#pragma once

//Given an array of numbers, return true if given array 
//can represent preorder traversal of a Binary Search Tree, else return false.Expected time complexity is O(n).

#include <iostream>
#include <vector>

class CheckIfArrayCanRepresentPreOrderTraversalOfBST {

private:
	struct node {
		int val;
		node* l;
		node* r;
		node(int _val) :
			val(_val), l(nullptr), r(nullptr) {}
	};

	typedef node* link;
	link _head;
	std::vector<int> _vec;
	void clearTreeR(link&);
	bool checkR(link, int&);

public:
	CheckIfArrayCanRepresentPreOrderTraversalOfBST(std::vector<int>);
	~CheckIfArrayCanRepresentPreOrderTraversalOfBST();
	bool check() { 
		int i = 0;
		if (checkR(_head, i) && i == _vec.size())
			return true;
		else
			return false;
	}

};
