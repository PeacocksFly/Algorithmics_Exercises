#include "MaximumPathSumInBinaryTree.h"


MaximumPathSumInBinaryTree::MaximumPathSumInBinaryTree():maximumPath(0) {

	//head = new node(10);
	//head->l = new node(2);	
	//head->l->l = new node(20);
	//head->l->r = new node(1);
	//head->r = new node(10);
	//head->r->r = new node(-25);
	//head->r->r->l = new node(3);
	//head->r->r->r = new node(4);

	head = new node(-25);
	head->l = new node(40);	
	head->r = new node(-10);
	head->r->r = new node(3);
	head->r->l = new node(40);
	head->r->l->l = new node(100);
	head->r->l->l->l = new node(-10);
	head->r->l->l->r = new node(-2);


}


MaximumPathSumInBinaryTree::~MaximumPathSumInBinaryTree() {

	clearTreeR(head);
}

void MaximumPathSumInBinaryTree::clearTreeR(link& h) {

	if (!h) return;
	link l = nullptr, r = nullptr;
	if (h->l) l = h->l;
	if (h->r) r = h->r;
	delete h;
	h = nullptr;
	clearTreeR(l);
	clearTreeR(r);
}


int MaximumPathSumInBinaryTree::maximumSumPathR(link h) {

	if (!h) return 0;

    int u = maximumSumPathR(h->l);
	int v = maximumSumPathR(h->r);
	maximumPath = std::max(maximumPath, std::max(u, v));
	if (h != head) 		
		return (u > v) ? std::max(h->val, u + h->val) : std::max(h->val, v + h->val);		
	else 
		return std::max(maximumPath, std::max(u, std::max(v, std::max(u + v + h->val, std::max(v + h->val, u + h->val)))));		
}

