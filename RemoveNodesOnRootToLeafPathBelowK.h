#pragma once

//Given a Binary Tree and a number k, remove all nodes that lie only on root to leaf path(s) 
//of length smaller than k.If a node X lies on multiple root - to - leaf paths and if any 
//of the paths has path length >= k, then X is not deleted from Binary Tree.In other words 
//a node is deleted if all paths going through it have lengths smaller than k.

#include <iostream>

class RemoveNodesOnRootToLeafPathBelowK {

private:
	struct node {
		int val;
		int floor;
		node* l;
		node* r;
		node(int _val) :
			val(_val), l(nullptr), r(nullptr), floor(0) {}
	};

	typedef node* link;
	link _head;
	int _k;
	void clearTreeR(link&);
	int removeNodeR(link, int);
	void readerR(link);

public:
	RemoveNodesOnRootToLeafPathBelowK();
	~RemoveNodesOnRootToLeafPathBelowK();
	void remodeNode(int k) { 
		_k = k;
		removeNodeR(_head, 0); 
	}
	void reader() { readerR(_head); }



};
