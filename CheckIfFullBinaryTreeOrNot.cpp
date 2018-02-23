#include "CheckIfFullBinaryTreeOrNot.h"


CheckIfFullBinaryTreeOrNot::CheckIfFullBinaryTreeOrNot() {

	head = new node(1);
	head->l = new node(2);
	head->r = new node(3);
	head->r->r = new node(4);
	head->r->l = new node(4);
	head->l = new node(2);
}


CheckIfFullBinaryTreeOrNot::~CheckIfFullBinaryTreeOrNot() {

	clearTreeR(head);
}

void CheckIfFullBinaryTreeOrNot::clearTreeR(link& h) {

	if (!h) return;
	link l = nullptr, r = nullptr;
	if (h->l) l = h->l;
	if (h->r) r = h->r;
	delete h;
	h = nullptr;
	clearTreeR(l);
	clearTreeR(r);
}

int CheckIfFullBinaryTreeOrNot::isFullBinaryTreeR(link h) {

	if (!h) return -1;

	int u = isFullBinaryTreeR(h->l);
	int v = isFullBinaryTreeR(h->r);

	return ( u == 0 || v == 0 || (u * v) == -1)? 0 : 1;
}