#pragma once

#include<iostream>

//Given a binary tree, flatten it to a linked list in - place.
//
//For example,
//Given
//
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
//The flattened tree should look like :
//1
// \
//  2
//   \
//    3
//     \
//      4
//       \
//        5
//         \
//          6


class FlattenBinaryTreeToLinkedList {

private:
	struct node {
		int val;
		node* l;
		node* r;
		node(int _val):
			val(_val), l(nullptr), r(nullptr) {}
	};

	typedef node* link;
	link head;
	link lastPtr;

	void flattenR(link);
	void preOrderTraversalR(link);
	

public:
	FlattenBinaryTreeToLinkedList();
	~FlattenBinaryTreeToLinkedList();
	void flatten() { flattenR(head); };
	void preOrderTraversal() { preOrderTraversalR(head); }

};
