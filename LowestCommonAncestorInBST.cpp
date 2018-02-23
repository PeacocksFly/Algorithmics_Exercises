#include "LowestCommonAncestorInBST.h"


LowestCommonAncestorInBST::LowestCommonAncestorInBST(int val1, int val2)
	                                                :_val1(val1), _val2(val2), _LCA(0) {

	_head = new node(20);
	_head->l = new node(8);
	_head->r = new node(22);
	_head->l->l = new node(4);
	_head->l->r = new node(12);
	_head->l->r->l = new node(10);
	_head->l->r->r = new node(14);
}



LowestCommonAncestorInBST::~LowestCommonAncestorInBST() {

	clearTreeR(_head);
}

void LowestCommonAncestorInBST::clearTreeR(link& h) {

	if (!h) return;
	link l = nullptr, r = nullptr;
	if (h->l) l = h->l;
	if (h->r) r = h->r;
	delete h;
	h = nullptr;
	clearTreeR(l);
	clearTreeR(r);
}

int LowestCommonAncestorInBST::searchLCAR(link h) {

	if (!h) return 0;

	int u = searchLCAR(h->l);
	int v = searchLCAR(h->r);

	if ((u == _val1 || u == _val2) && (v == _val1 || v == _val2)) return h->val;
	if ((u == 0 && v == 0) && (h->val == _val1 || h->val == _val2)) return h->val;
	if (u == 0 && v == 0 && h->val != _val1 && h->val != _val2) return 0;

	if (u == 0 && v != 0) {
		return helperSwitch(u, v, h->val);
	}

	if (v == 0 && u != 0) {
		return helperSwitch(v, u, h->val);
	}
	return 0;

}


int LowestCommonAncestorInBST::helperSwitch(int u, int v, int h) {

		if (v != _val1 && v != _val2) {
			return v;
		}
		else if (h == _val1 || h == _val2) {
			return h;
		}
		else
			return v;
}




