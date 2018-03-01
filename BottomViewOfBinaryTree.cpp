#include "BottomViewOfBinaryTree.h"


BottomViewOfBinaryTree::BottomViewOfBinaryTree() {

	head = new node(20);
	head->l = new node(8);
	head->r = new node(22);
	head->r->l = new node(4);
	head->l->l = new node(5);
	head->l->r = new node(3);
	head->l->r->l = new node(10);
	head->l->r->r = new node(14);
	head->r->r = new node(25);
}


BottomViewOfBinaryTree::~BottomViewOfBinaryTree() {

	clearTreeR(head);
}

void BottomViewOfBinaryTree::clearTreeR(link& h) {

	if (h == nullptr) return;
	link l = nullptr, r = nullptr;
	if (h->l != nullptr) l = h->l;
	if (h->r != nullptr) r = h->r;
	delete h;
	h = nullptr;
	clearTreeR(l);
	clearTreeR(r);
}


void BottomViewOfBinaryTree::printR(link h) {

	if (h == nullptr) return;

	std::vector<std::pair<link, int>> storage;
	storage.reserve(1000);
	storage.push_back(std::make_pair(h, 0));
	std::vector<std::pair<link, int>>::iterator it = storage.begin();
	std::vector<int> existingValues;

	while (it!= storage.end()) {
		
		if (it->first->l != nullptr) 
			storage.push_back(std::make_pair(it->first->l, it->second - 1));
	    if (it->first->r != nullptr)
		    storage.push_back(std::make_pair(it->first->r, it->second + 1));		
		it++;
		
	}

	while (!storage.empty()) {

		int val = storage.back().second;
		if (std::find(existingValues.begin(), existingValues.end(), val) == existingValues.end())
			    std::cout << storage.back().first->val << "  ";
		existingValues.push_back(val);
		storage.pop_back();
	}
	  
}