#include "114_FlattenBinaryTreeToLinkedList.h"

FlattenBinaryTreeToLinkedList::FlattenBinaryTreeToLinkedList() {
	
	head = new node(1);
	head->l = new node(2);
	head->r = new node(5);
	head->l->l = new node(3);
	head->l->r = new node(4);
	head->r->l = new node(6);
	lastPtr = head;
}

FlattenBinaryTreeToLinkedList::~FlattenBinaryTreeToLinkedList() {

	link t = head;
	link g = nullptr;

	while (t != nullptr) {
		g = t;
		t = t->l;
		delete g;
	}

	
}

void FlattenBinaryTreeToLinkedList::preOrderTraversalR(link h) {

	if (h == nullptr) 
		return;

	preOrderTraversalR(h->l);
	preOrderTraversalR(h->r);

	/*if (h == nullptr)
		return;
	
	std::cout << h->val    << std::endl;
    preOrderTraversalR(h->l);
	*/
}

void FlattenBinaryTreeToLinkedList::flattenR(link h) {

	if (h != nullptr) {		
		if (lastPtr->l != h && lastPtr != head) {
			lastPtr->l = h;			
		}	
		lastPtr = h;
	}		
	else
		return;

	flattenR(h->l);
	flattenR(h->r);

}