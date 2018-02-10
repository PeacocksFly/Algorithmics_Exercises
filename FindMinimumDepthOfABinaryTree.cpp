#include "FindMinimumDepthOfABinaryTree.h"

FindMinimumDepthOfABinaryTree::FindMinimumDepthOfABinaryTree() {

	head = new node(1);
	head->l = new node(2);
    head->r = new node(5);
    head->r->r = new node(10);
	head->r->r->r = new node(10);
	head->l->l = new node(3);
	head->l->r = new node(4);
	head->l->l->l = new node(7);
	head->l->l->r = new node(9);
}


FindMinimumDepthOfABinaryTree::~FindMinimumDepthOfABinaryTree() {

	link t = head;
	link g = nullptr;

	while (t != nullptr) {
		g = t;
		t = t->l;
		delete g;
	}
}


int FindMinimumDepthOfABinaryTree::minimumLengthR(link h) {
	
	if (h == nullptr) return -1;

	int u = minimumLengthR(h->l);
	int v = minimumLengthR(h->r);

	return (std::min(u, v) != -1) ? std::min(u, v) +1  : std::max(u, v) + 1;
}