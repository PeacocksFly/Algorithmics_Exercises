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

	clearTreeR(head);
}

void FlattenBinaryTreeToLinkedList::clearTreeR(link h) {

	if (h == nullptr) return;
	link l = nullptr, r = nullptr;
	if (h->l != nullptr) l = h->l;
	if (h->r != nullptr) r = h->r;
	delete h;
	clearTreeR(l);
	clearTreeR(r);
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

void printR(std::ostream& os, FlattenBinaryTreeToLinkedList::link h) {

	if (h == nullptr) return;
	os << h->val;
	printR(os, h->l);
	printR(os, h->r);

}

std::ostream& operator<<(std::ostream& os, const FlattenBinaryTreeToLinkedList& tree) {

	FlattenBinaryTreeToLinkedList::link h = tree.head;
	printR(os, h);
	
	return os;
}