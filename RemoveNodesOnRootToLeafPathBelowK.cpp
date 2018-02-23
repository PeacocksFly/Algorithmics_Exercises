#include "RemoveNodesOnRootToLeafPathBelowK.h"

RemoveNodesOnRootToLeafPathBelowK::RemoveNodesOnRootToLeafPathBelowK()
	                     : _k(0){

	/*_head = new node(1);
	_head->l = new node(2);
	_head->r = new node(3);
	_head->r->r = new node(6);
	_head->r->r->l = new node(8);
	_head->l->l = new node(4);
	_head->l->r = new node(5);
	_head->l->l->l = new node(7);*/


	_head = new node(1);
	_head->l = new node(2);
	_head->r = new node(3);

	_head->l->l = new node(4);
	_head->l->r = new node(5);
	_head->r->r = new node(6);
	_head->r->l = new node(7);

	_head->l->l->l = new node(8);
	_head->l->r->l = new node(9);
	_head->l->r->r = new node(10);

	_head->l->l->l->l = new node(11);
	_head->l->l->l->r = new node(12);

}


RemoveNodesOnRootToLeafPathBelowK::~RemoveNodesOnRootToLeafPathBelowK() {

	clearTreeR(_head);
}

void RemoveNodesOnRootToLeafPathBelowK::clearTreeR(link h) {

	if (!h) {

		return; 
	}
	link l = nullptr, r = nullptr;
	if (h->l) l = h->l;
	if (h->r) r = h->r;
	delete h;
	clearTreeR(l);
	clearTreeR(r);
}


int RemoveNodesOnRootToLeafPathBelowK::removeNodeR(link h, int k) {

	if (!h) return 0;

	h->floor = ++k;
	
	int u = removeNodeR(h->l, h->floor);
	int v = removeNodeR(h->r, h->floor);

	if (_k - h->floor - u > 0) {
		clearTreeR(h->l);
		if (h->l) h->l = nullptr;
		u = 0;
	}

	if (_k - h->floor - v > 0) {
        clearTreeR(h->r);
		if(h->r) h->r = nullptr;
		v = 0;
	}

	return  (u < v) ? (v + 1) : (u + 1);

}


void RemoveNodesOnRootToLeafPathBelowK::readerR(link h) {

	if (!h) return;
	std::cout << " " << h->val;
	readerR(h->l);
	readerR(h->r);

}