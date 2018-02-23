#pragma once
#include <deque>
#include <math.h>
#include <iostream>
//Given a Perfect Binary Tree, reverse the alternate level nodes of the binary tree.
//
//
//Given tree :
//           a
//       /       \
//     b          c
//    / \          / \
//   d    e       f    g
//   / \ / \      / \ / \
//  h  i j  k    l  m  n  o
//
//Modified tree :
//            a
//          /  \
//       c         b
//      / \      /   \
//    d    e    f     g
//   / \ / \   / \   / \
//  o  n m  l  k  j  i  h


class ReverseAlternateLevelsOfAPerfectBinaryTree {

private:
	struct node {
		char letter;
		node* l;
		node* r;
		node(char _val) :
			letter(_val), l(nullptr), r(nullptr) {}
	};

	typedef node* link;
	link head;
	void swapR(std::deque<link>::iterator, std::deque<link>::reverse_iterator);
	void reverseR(link);
	void clearTreeR(link&);


public:
	ReverseAlternateLevelsOfAPerfectBinaryTree();
	~ReverseAlternateLevelsOfAPerfectBinaryTree();
	void reverse() { reverseR(head); }

};