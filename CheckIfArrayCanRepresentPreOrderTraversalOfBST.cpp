#include "CheckIfArrayCanRepresentPreOrderTraversalOfBST.h"


CheckIfArrayCanRepresentPreOrderTraversalOfBST::CheckIfArrayCanRepresentPreOrderTraversalOfBST(std::vector<int> vec)
	:_vec(vec) {

	_head = new node(40);
	_head->r = new node(80);
	_head->l = new node(30);
	_head->l->r = new node(35);
	_head->r->r = new node(100);

	//_head->l->r = new node(12);
	//_head->l->r->l = new node(10);
	//_head->l->r->r = new node(14);
}



CheckIfArrayCanRepresentPreOrderTraversalOfBST::~CheckIfArrayCanRepresentPreOrderTraversalOfBST() {

	clearTreeR(_head);
}

void CheckIfArrayCanRepresentPreOrderTraversalOfBST::clearTreeR(link& h) {

	if (!h) return;
	link l = nullptr, r = nullptr;
	if (h->l) l = h->l;
	if (h->r) r = h->r;
	delete h;
	h = nullptr;
	clearTreeR(l);
	clearTreeR(r);
}

bool CheckIfArrayCanRepresentPreOrderTraversalOfBST::checkR(link h, int& i) {

	if (!h) return true;

	if (i <= _vec.size() - 1)
		if (h->val != _vec[i])
			return false;
		else
			i++;
	else
		return false;

	bool u = checkR(h->l, i);
	bool v = checkR(h->r, i);

	return (u == false || v == false) ? false : true;

}